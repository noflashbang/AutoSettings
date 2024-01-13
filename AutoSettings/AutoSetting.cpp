#include "AutoSetting.h"

AutoSettingEntry::AutoSettingEntry(const AutoSettingEntry &other)
{
	m_Key = other.m_Key;
	m_Value = other.m_Value;
	m_Datored = other.m_Datored;
	m_Loaded = other.m_Loaded;
	m_Added = other.m_Added;
	m_Save = other.m_Save;
	m_pDator = other.m_pDator;
};
AutoSettingEntry& AutoSettingEntry::operator=(const AutoSettingEntry &other)
{
	if (this != &other)
	{
		m_Key = other.m_Key;
		m_Value = other.m_Value;
		m_Datored = other.m_Datored;
		m_Loaded = other.m_Loaded;
		m_Added = other.m_Added;
		m_Save = other.m_Save;
		m_pDator = other.m_pDator;
	}
	return (*this);
};
void AutoSettingEntry::SetKey(std::string key)
{
	Util::StringToUpper(&key);
	Util::StringTrim(&key);
	m_Key = key;
};
void AutoSettingEntry::SetValue(IDator* pDator, bool DatorPersists)
{
	m_Value = pDator->GetValue();
	if (DatorPersists)
	{
		m_pDator = pDator;
	}
	else
	{
		m_pDator = NULL;
	}
	m_Datored = true;
};
void AutoSettingEntry::SetValue(std::string Value)
{
	m_Value = Value;
};
void AutoSettingEntry::ClearDatored()
{
	m_Datored = false;
	m_pDator = NULL;
};
void AutoSettingEntry::SetLoaded(bool Loaded)
{
	m_Loaded = Loaded;
};
void AutoSettingEntry::SetAdded(bool Added)
{
	m_Added = Added;
};
void AutoSettingEntry::SetSave(bool Save)
{
	m_Save = Save;
};
std::string AutoSettingEntry::GetKey()
{
	return m_Key;
};
std::string AutoSettingEntry::GetValue()
{
	return m_Value;
};
bool AutoSettingEntry::GetDatored()
{
	return m_Datored;
};
bool AutoSettingEntry::GetLoaded()
{
	return m_Loaded;
};
bool AutoSettingEntry::GetAdded()
{
	return m_Added;
};
bool AutoSettingEntry::GetSave()
{
	return m_Save;
};
void AutoSettingEntry::Update()
{
	if (m_Datored && m_pDator != NULL)
	{
		m_Value = m_pDator->GetValue();
	}
};
AutoSettingGroup::AutoSettingGroup(const AutoSettingGroup &other)
{
	m_GroupName = other.m_GroupName;
	m_Entries = other.m_Entries;
	m_Save = other.m_Save;
};
AutoSettingGroup& AutoSettingGroup::operator=(const AutoSettingGroup &other)
{
	if (this != &other)
	{
		m_GroupName = other.m_GroupName;
		m_Entries = other.m_Entries;
		m_Save = other.m_Save;
	}
	return (*this);
};
void AutoSettingGroup::SetName(std::string Name)
{
	Util::StringToUpper(&Name);
	Util::StringTrim(&Name);
	m_GroupName = Name;
};

void AutoSettingGroup::AddEntry(AutoSettingEntry* pEntry)
{
	AutoSettingEntry* pHold = NULL;
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == pEntry->GetKey())
		{
			pHold = &(*iter);
			break;
		}
	}
	if (pHold != NULL)
	{
		pHold->SetValue(pEntry->GetValue());
	}
	else
	{
		m_Entries.push_back((*pEntry));
	}
};

void AutoSettingGroup::SetEntry(std::string Key, IDator* pDator, bool DatorPersists)
{
	AutoSettingEntry* pHold = NULL;
	Util::StringToUpper(&Key);
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == Key)
		{
			pHold = &(*iter);
			break;
		}
	}
	if (pHold != NULL)
	{
		pHold->SetValue(pDator, DatorPersists);
	}
	else
	{
		AutoSettingEntry entry;
		entry.SetKey(Key);
		entry.SetValue(pDator, DatorPersists);
		m_Entries.push_back(entry);
	}
};

void AutoSettingGroup::GetEntry(std::string Key, IDator* pDator, bool DatorPersists)
{
	AutoSettingEntry* pHold = NULL;
	Util::StringToUpper(&Key);
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == Key)
		{
			pHold = &(*iter);
			break;
		}
	}
	if (pHold != NULL)
	{
		pDator->SetValue(pHold->GetValue());
	}
	else
	{
		AutoSettingEntry entry;
		entry.SetKey(Key);
		entry.SetValue(pDator, DatorPersists);
		m_Entries.push_back(entry);
	}
};

bool AutoSettingGroup::FindEntry(std::string Key, IDator* pDator)
{
	Util::StringToUpper(&Key);
	bool ret = false;
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == Key)
		{
			pDator->SetValue(iter->GetValue());
			ret = true;
			break;
		}
	}
	return ret;
};
void AutoSettingGroup::DeleteEntry(std::string Key)
{
	Util::StringToUpper(&Key);
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == Key)
		{
			m_Entries.erase(iter);
			break;
		}
	}
};
void AutoSettingGroup::SetSave(bool Save)
{
	m_Save = Save;
};

std::string AutoSettingGroup::GetName()
{
	return m_GroupName;
};
bool AutoSettingGroup::GetSave()
{
	return m_Save;
};
void AutoSettingGroup::GetAllEntries(std::vector<AutoSettingEntry*>* pEntries)
{
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		(*pEntries).push_back(&(*iter));
	}
};

bool AutoSettingSerializerOut::IO(AutoSettingEntry &io)
{
	unsigned lenK = io.GetKey().size();
	unsigned lenV = io.GetValue().size();
	if ((lenK + 2 + lenV + m_BufferPos) > m_BufferLength)
	{
		m_OverFlowed = true;
		return false;
	}
	memcpy(&m_Buffer[m_BufferPos], io.GetKey().c_str(), lenK);
	m_BufferPos += lenK;
	memcpy(&m_Buffer[m_BufferPos], "=", 1);
	m_BufferPos += 1;
	memcpy(&m_Buffer[m_BufferPos], io.GetValue().c_str(), lenV);
	m_BufferPos += lenV;
	memcpy(&m_Buffer[m_BufferPos], "\n", 1);
	m_BufferPos += 1;
	return true;
}
bool AutoSettingSerializerOut::IO(AutoSettingGroup &io)
{
	unsigned lenGN = io.GetName().size();
	if ((lenGN + 3 + m_BufferPos) > m_BufferLength)
	{
		m_OverFlowed = true;
		return false;
	}
	memcpy(&m_Buffer[m_BufferPos], "[", 1);
	m_BufferPos += 1;
	memcpy(&m_Buffer[m_BufferPos], io.GetName().c_str(), lenGN);
	m_BufferPos += lenGN;
	memcpy(&m_Buffer[m_BufferPos], "]\n", 2);
	m_BufferPos += 2;

	std::vector<AutoSettingEntry*> Entries;
	io.GetAllEntries(&Entries);

	std::vector<AutoSettingEntry*>::iterator iter;
	for (iter = Entries.begin(); iter != Entries.end(); iter++)
	{
		(*iter)->Update();
		if ((*iter)->GetSave())
		{
			AutoSettingEntry hold = (**iter);
			this->IO(hold);
		}
	}
	return true;
}
//==============================================================================
bool AutoSettingSerializerIn::IO(AutoSettingEntry &io)
{
	bool NotDone = true;
	unsigned Start = m_BufferPos;
	bool NotFoundEnd = true;
	unsigned End = 0;
	unsigned lenL = 0;
	unsigned Before = m_BufferPos;
	while (m_BufferPos <= m_BufferLength && NotDone)
	{
		if (m_Buffer[m_BufferPos] == '\n' && NotFoundEnd)
		{
			NotFoundEnd = false;
			End = m_BufferPos;
		}
		lenL = (End - Start);
		NotDone = (NotFoundEnd);
		if (!NotDone)
		{
			bool comment = false;
			if (m_Buffer[Start] == '#')
				comment = true;

			//check the length and comment
			if (lenL <= 0 || comment)
			{
				//bad line or comment, move onto the next one
				Start = ++End;
				End = 0;
				NotFoundEnd = true;
				NotDone = true;
			}
		}
		m_BufferPos++;
	}
	if (NotDone)
	{
		//hit the end of the file without finding a new line
		//might just be the last line
		//check for length
		lenL = (m_BufferPos - 1) - Start;
		if (lenL <= 1)
			return false;
	}

	char* buffer = new char[lenL + 1];
	memset(buffer, 0, lenL + 1);
	memcpy(buffer, &m_Buffer[Start], lenL);

	//now find the '='
	unsigned current = 0;
	bool notFound = true;
	while (notFound && (current <= lenL))
	{
		if (buffer[current] == '=')
			notFound = false;
		else
			current++;
	}

	if (notFound)
	{
		//probaly hit another group
		m_BufferPos = Before;
		delete[] buffer;
		return false;
	}

	buffer[current] = '\0';
	io.SetKey(buffer);
	int dataLen = (lenL - (current + 1));
	if (dataLen > 0)
	{
		io.SetValue(&buffer[current + 1]);
	}
	else
	{
		io.SetValue("");
	}

	delete[] buffer;

	io.SetLoaded(true);
	return true;
}
bool AutoSettingSerializerIn::IO(AutoSettingGroup &io)
{
	bool NotDone = true;
	bool NotFoundStart = true;
	unsigned Start = 0;
	bool NotFoundEnd = true;
	unsigned End = 0;
	unsigned lenGN = 0;
	while (m_BufferPos <= m_BufferLength && NotDone)
	{
		if (m_Buffer[m_BufferPos] == '[' && NotFoundStart)
		{
			NotFoundStart = false;
			Start = m_BufferPos;
		}
		if (m_Buffer[m_BufferPos] == ']' && NotFoundEnd)
		{
			NotFoundEnd = false;
			End = m_BufferPos;
		}
		lenGN = (End - (Start + 1));
		NotDone = (NotFoundStart || NotFoundEnd);
		if (!NotDone)
		{
			//check the length
			if (lenGN <= 0)
			{
				//bad group name move onto the next one
				NotFoundStart = true;
				NotFoundEnd = true;
				NotDone = true;
			}
		}
		m_BufferPos++;
	}
	if (NotDone)
	{
		//hit the end of the file without finding a group name that was good
		return false;
	}
	char* temp = new char[lenGN + 1];
	memset(temp, 0, lenGN + 1);
	memcpy(temp, &m_Buffer[(Start + 1)], lenGN);
	m_BufferPos += 1; //move away from new line

	io.SetName(temp);
	delete[] temp;

	bool noError = true;
	while ((m_BufferPos <= m_BufferLength) && noError)
	{
		AutoSettingEntry hold;
		noError = this->IO(hold);
		if (noError)
		{
			io.AddEntry(&hold);
		}
	}
	return true;
}
//=====================================================================

void AutoSetting::SetSetting(std::string Group, std::string Key, IDator* pDator)
{
	SetSettingInternal(Group, Key, pDator, true);
}
void AutoSetting::SetSetting(char* pGroup, char* pKey, IDator* pDator)
{
	std::string Group = pGroup;
	std::string Key = pKey;
	SetSettingInternal(Group, Key, pDator, true);
}
void AutoSetting::GetSetting(std::string Group, std::string Key, IDator* pDator)
{
	GetSettingInternal(Group, Key, pDator, true);
}
void AutoSetting::GetSetting(char* pGroup, char* pKey, IDator* pDator)
{
	std::string Group = pGroup;
	std::string Key = pKey;
	GetSettingInternal(Group, Key, pDator, true);
}
bool AutoSetting::FindSetting(std::string Group, std::string Key, IDator* pDator)
{
	return FindSettingInternal(Group, Key, pDator, true);
};
bool AutoSetting::FindSetting(char* pGroup, char* pKey, IDator* pDator)
{
	std::string Group = pGroup;
	std::string Key = pKey;
	return FindSetting(Group, Key, pDator);
};
void AutoSetting::DeleteSetting(std::string Group, std::string Key)
{
	DeleteKeyGroup(Group, Key);
};
void AutoSetting::DeleteSetting(char* pGroup, char* pKey)
{
	std::string Group = pGroup;
	std::string Key = pKey;
	DeleteKeyGroup(Group, Key);
};
void AutoSetting::DeleteGroup(std::string Group)
{
	DeleteGroupInternal(Group);
};
void AutoSetting::DeleteGroup(char* Group)
{
	std::string stdGroup = Group;
	DeleteGroup(stdGroup);
};
void AutoSetting::LoadSettings(std::string path)
{
	LoadSettingsInternal(path);
}
void AutoSetting::LoadSettings(char* path)
{
	std::string pathS = path;
	LoadSettingsInternal(pathS);
}
void AutoSetting::SaveSettings(std::string path, int Mode)
{
	SaveSettingsInternal(path, Mode);
}
void AutoSetting::SaveSettings(char* path, int Mode)
{
	std::string pathS = path;
	SaveSettingsInternal(pathS, Mode);
}
void AutoSetting::AddGroup(std::string Group, AutoSettingGroup* pGroup)
{
	DeleteGroupInternal(Group);
	AddGroupInternal(pGroup);
};
void AutoSetting::AddGroup(char* Group, AutoSettingGroup* pGroup)
{
	std::string stdGroup = Group;
	AddGroup(stdGroup, pGroup);
};
bool AutoSetting::FindGroup(std::string Group, AutoSettingGroup* pGroup)
{
	bool ret = false;
	AutoSettingGroup* holder = NULL;
	FindGroupInternal(Group, &holder);
	if (holder != NULL)
	{
		(*pGroup) = (*holder);
		ret = true;
	}
	return ret;
};
bool AutoSetting::FindGroup(char* Group, AutoSettingGroup* pGroup)
{
	std::string stdGroup = Group;
	return FindGroup(stdGroup, pGroup);
};
void AutoSetting::GetAllGroups(std::vector< AutoSettingGroup >* ppGroups)
{
	(*ppGroups) = m_Groups;
};
void AutoSetting::SetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(Group, &pGroup))
	{
		pGroup->SetEntry(Key, pDator, DatorPersists);
	}
	else
	{
		AddKeyGroup(Group, Key, pDator, DatorPersists);
	}
}
void AutoSetting::GetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(Group, &pGroup))
	{
		pGroup->GetEntry(Key, pDator, DatorPersists);
	}
	else
	{
		AddKeyGroup(Group, Key, pDator, DatorPersists);
	}
}
bool AutoSetting::FindSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists)
{
	bool ret = false;
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(Group, &pGroup))
	{
		if (pGroup->FindEntry(Key, pDator))
		{
			ret = true;
		}
	}
	return ret;
};
void AutoSetting::LoadSettingsInternal(std::string path)
{
	m_FilePath = path;

	std::fstream file;
	file.open(m_FilePath.c_str(), std::fstream::in);
	if (!file.fail())
	{
		//load the contents onto a buffer
		file.seekg(0, std::ios::end);
		unsigned int length = file.tellg();
		file.seekg(0, std::ios::beg);

		if (length <= 10485760) //limit allowable file size(10 megabytes)
		{
			char* buffer = new char[length];
			memset(buffer, 0, length);

			file.read(buffer, length);
			file.close();

			//now construct
			AutoSettingSerializerIn builder(buffer, length);
			bool noError = true;
			unsigned CurrentRead = 0;
			while (noError && (CurrentRead <= length))
			{
				AutoSettingGroup hold;
				noError = builder.IO(hold);
				if (noError)
				{
					m_Groups.push_back(hold);
				}
				CurrentRead = builder.GetBufferPos();
			}
			delete [] buffer;
		}
	}
}
void AutoSetting::SaveSettingsInternal(std::string path, int Mode)
{
	//do the cleaning of the vector first
	std::vector< AutoSettingGroup >::iterator iter;
	for (iter = m_Groups.begin(); iter != m_Groups.end(); iter++)
	{
		bool addedTrue = false;
		std::vector< AutoSettingEntry* > entries;
		iter->GetAllEntries(&entries);

		if (entries.size() > 0)
		{
			std::vector< AutoSettingEntry* >::iterator iter2;
			for (iter2 = entries.begin(); iter2 != entries.end(); iter2++)
			{
				if (AS_DATORED & Mode)
				{
					if ((*iter2)->GetDatored())
					{
						(*iter2)->SetSave(true);
						addedTrue = true;
					}
				}
				if (AS_LOADED & Mode)
				{
					if ((*iter2)->GetLoaded())
					{
						(*iter2)->SetSave(true);
						addedTrue = true;
					}
				}
				if (AS_ADDED & Mode)
				{
					if ((*iter2)->GetAdded())
					{
						(*iter2)->SetSave(true);
						addedTrue = true;
					}
				}
				if (!(AS_UPDATE & Mode))
				{
					(*iter2)->ClearDatored();
				}
			}
			iter->SetSave(addedTrue);
		}
		else
		{
			iter->SetSave(false);
		}
	}

	std::fstream file;
	m_FilePath = path;
	file.open(m_FilePath.c_str(), std::fstream::out | std::fstream::trunc);
	if (!file.fail())
	{
		//save them
		int len = 1048576; //allow a max of 1 megabyte for each section
		char* buffer = new char[len];
		std::vector< AutoSettingGroup >::iterator iter;
		for (iter = m_Groups.begin(); iter != m_Groups.end(); iter++)
		{
			if (iter->GetSave())
			{
				memset(buffer, 0, len);
				AutoSettingSerializerOut builder(buffer, len);
				AutoSettingGroup hold;
				hold = (*iter);
				builder.IO(hold);
				file.write(buffer, builder.GetBufferPos());
			}
		}
		delete[] buffer;
		file.close();
	}
}
void AutoSetting::AddKeyGroup(std::string Group, std::string Key, IDator* pDator, bool DatorPersists)
{
	AutoSettingGroup hold;
	hold.SetEntry(Key, pDator, DatorPersists);
	hold.SetName(Group);
	m_Groups.push_back(hold);
}

bool AutoSetting::FindGroupInternal(std::string Group, AutoSettingGroup** ppGroup)
{
	bool ret = false;
	std::vector< AutoSettingGroup >::iterator iter;
	for (iter = m_Groups.begin(); iter != m_Groups.end(); iter++)
	{
		if ((iter->GetName() == Group))
		{
			ret = true;
			(*ppGroup) = &(*iter);
			break;
		}
	}
	return ret;
};

void AutoSetting::DeleteKeyGroup(std::string Group, std::string Key)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(Group, &pGroup))
	{
		pGroup->DeleteEntry(Key);
	}
};
void AutoSetting::AddGroupInternal(AutoSettingGroup* pGroup)
{
	m_Groups.push_back((*pGroup));
};
void AutoSetting::DeleteGroupInternal(std::string Group)
{
	std::vector< AutoSettingGroup >::iterator iter;
	for (iter = m_Groups.begin(); iter != m_Groups.end(); iter++)
	{
		if ((iter->GetName() == Group))
		{
			m_Groups.erase(iter);
			break;
		}
	}
};



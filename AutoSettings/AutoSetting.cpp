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
	m_Data.append(io.GetKey());
	m_Data.append("=");
	m_Data.append(io.GetValue());
	m_Data.append("\n");

	return true;
}
bool AutoSettingSerializerOut::IO(AutoSettingGroup &io)
{
	m_Data.append("[");
	m_Data.append(io.GetName());
	m_Data.append("]\n");

	std::vector<AutoSettingEntry*> Entries;
	io.GetAllEntries(&Entries);

	for(AutoSettingEntry* pEntry : Entries)
	{
		pEntry->Update();
		if (pEntry->GetSave())
		{
			AutoSettingEntry hold = (*pEntry);
			this->IO(hold);
		}
	}

	return true;
}
//==============================================================================
bool AutoSettingSerializerIn::IO(AutoSettingEntry &io)
{
	auto entry = Util::StringSplit(m_Data, "=");
	if (entry.size() != 2)
	{
		return false;
	}

	io.SetKey(entry[0]);
	io.SetValue(entry[1]);
	io.SetLoaded(true);
	return true;
}
bool AutoSettingSerializerIn::IO(AutoSettingGroup &io)
{
	//for each line
	auto lines = Util::StringSplit(m_Data, "\n");
	for (auto line : lines)
	{
		//if line is a group
		if (line[0] == '[')
		{
			io.SetName(Util::StringTrimEx(Util::StringTrimEx(line, '['), ']'));
		}

		//if line is an entry
		if (line.find("=") != std::string::npos)
		{
			AutoSettingSerializerIn in(line);
			AutoSettingEntry entry;
			bool okay = in.IO(entry);
			if (okay)
			{
				io.AddEntry(&entry);
			}
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
	std::string contents = Util::file_to_string(m_FilePath);
	std::vector<std::string> groups;

	bool findEnd = false;
	bool proccess = false;
	int pos = 0;
	int pos2 = 0;

	//look for each group
	for (int ii = 0; ii < contents.length(); ii++)
	{
		char c = contents[ii];
		if (c == '[')
		{
			if (findEnd)
			{
				pos2 = ii - 1;
				findEnd = false;
				proccess = true;
			}
			else
			{
				pos = ii;
				findEnd = true;
			}
		}
		if (proccess)
		{
			proccess = false;
			std::string groupStr = contents.substr(pos + 1, pos2 - pos);
			groups.push_back(groupStr);
		}
	}

	//add the last
	if (findEnd)
	{
		pos2 = contents.length() - 1;
		std::string groupStr = contents.substr(pos + 1, pos2 - pos);
		groups.push_back(groupStr);
	}
	
	for (auto groupStr : groups)
	{
		AutoSettingSerializerIn in(groupStr);
		AutoSettingGroup group;
		in.IO(group);
		m_Groups.push_back((group));
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

	
	m_FilePath = path;
	
	std::string dataOut;
	for (auto &iter : m_Groups)
	{
		if (iter.GetSave())
		{
			AutoSettingSerializerOut builder(dataOut);
			builder.IO(iter);
		}
	}
	Util::string_to_file(m_FilePath, dataOut);
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



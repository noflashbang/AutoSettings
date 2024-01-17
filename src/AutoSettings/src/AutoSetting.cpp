#include "AutoSetting.h"




//==============================================================================

//=====================================================================

void AutoSetting::SetSetting(std::string Group, std::string Key, IDator* pDator)
{
	SetSettingInternal(Group, Key, pDator, true);
}

void AutoSetting::GetSetting(std::string Group, std::string Key, IDator* pDator)
{
	GetSettingInternal(Group, Key, pDator, true);
}

bool AutoSetting::FindSetting(std::string Group, std::string Key, IDator* pDator)
{
	return FindSettingInternal(Group, Key, pDator, true);
};

void AutoSetting::DeleteSetting(std::string Group, std::string Key)
{
	DeleteKeyGroup(Group, Key);
};

void AutoSetting::DeleteGroup(std::string Group)
{
	DeleteGroupInternal(Group);
};

void AutoSetting::LoadSettings(std::string iniContent)
{
	LoadSettingsInternal(iniContent);
}

void AutoSetting::SaveSettings(std::string path, int Mode)
{
	SaveSettingsInternal(path, Mode);
}

std::string AutoSetting::GetIniContents(int Mode)
{
	SetSaveFlags(Mode);
	return GetIniContentsInternal();
}

void AutoSetting::AddGroup(std::string Group, AutoSettingGroup* pGroup)
{
	DeleteGroupInternal(Group);
	AddGroupInternal(pGroup);
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

void AutoSetting::GetAllGroups(std::vector< AutoSettingGroup >* ppGroups)
{
	(*ppGroups) = m_Groups;
};
void AutoSetting::SetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists)
{
	Util::StringToUpper(Group);
	Util::StringToUpper(Key);
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
	Util::StringToUpper(Group);
	Util::StringToUpper(Key);
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
	Util::StringToUpper(Group);
	Util::StringToUpper(Key);
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
void AutoSetting::LoadSettingsInternal(std::string iniContent)
{
	std::vector<std::string> groups;

	bool findEnd = false;
	bool proccess = false;
	int pos = 0;
	int pos2 = 0;

	//look for each group
	for (int ii = 0; ii < iniContent.length(); ii++)
	{
		char c = iniContent[ii];
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
			std::string groupStr = iniContent.substr(pos, pos2 - pos);
			groups.push_back(groupStr);
			pos = ii;
			findEnd = true;
		}
	}

	//add the last
	if (findEnd)
	{
		pos2 = iniContent.length() - 1;
		std::string groupStr = iniContent.substr(pos, pos2 - pos);
		groups.push_back(groupStr);
	}
	
	for (auto groupStr : groups)
	{
		AutoSettingSerializerIn in(&groupStr);
		AutoSettingGroup group;
		in.IO(group);
		m_Groups.push_back((group));
	}
}
void AutoSetting::SaveSettingsInternal(std::string path, int Mode)
{
	SetSaveFlags(Mode);
		
	m_FilePath = path;
	
	std::string dataOut = GetIniContentsInternal();

	Util::string_to_file(m_FilePath, dataOut);
}

void AutoSetting::SetSaveFlags(int mode)
{
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
				if (AS_DATORED & mode)
				{
					if ((*iter2)->GetDatored())
					{
						(*iter2)->SetSave(true);
						addedTrue = true;
					}
				}
				if (AS_LOADED & mode)
				{
					if ((*iter2)->GetLoaded())
					{
						(*iter2)->SetSave(true);
						addedTrue = true;
					}
				}
				if (AS_ADDED & mode)
				{
					if ((*iter2)->GetAdded())
					{
						(*iter2)->SetSave(true);
						addedTrue = true;
					}
				}
				if (!(AS_UPDATE & mode))
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
}

std::string AutoSetting::GetIniContentsInternal()
{
	std::string dataOut;
	for (auto& iter : m_Groups)
	{
		if (iter.GetSave())
		{
			AutoSettingSerializerOut builder(&dataOut);
			builder.IO(iter);
		}
	}
	return dataOut;
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



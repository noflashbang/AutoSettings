#include "AutoSetting.h"

void AutoSetting::SetSetting(const std::string& group, const std::string& key, IDator* pDator)
{
	SetSettingInternal(group, key, pDator, true);
}

void AutoSetting::GetSetting(const std::string& group, const std::string& key, IDator* pDator)
{
	GetSettingInternal(group, key, pDator, true);
}

bool AutoSetting::FindSetting(const std::string& group, const std::string& key, IDator* pDator)
{
	return FindSettingInternal(group, key, pDator, true);
}

void AutoSetting::DeleteSetting(const std::string& group, const std::string& key)
{
	DeleteKeyGroup(group, key);
}

void AutoSetting::LoadSettings(const std::string& iniContent)
{
	LoadSettingsInternal(iniContent);
}

void AutoSetting::DeleteGroup(const std::string& group)
{
	DeleteGroupInternal(group);
}

std::string AutoSetting::GetIniContents()
{
	return GetIniContentsInternal();
}

void AutoSetting::SetSettingInternal(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists)
{
	Util::StringToUpper(group);
	Util::StringToUpper(key);
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		pGroup->SetEntry(key, pDator, DatorPersists);
	}
	else
	{
		AddKeyGroup(group, key, pDator, DatorPersists);
	}
}

void AutoSetting::GetSettingInternal(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists)
{
	Util::StringToUpper(group);
	Util::StringToUpper(key);
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		pGroup->GetEntry(key, pDator, DatorPersists);
	}
	else
	{
		AddKeyGroup(group, key, pDator, DatorPersists);
	}
}

bool AutoSetting::FindSettingInternal(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists)
{
	Util::StringToUpper(group);
	Util::StringToUpper(key);
	bool ret = false;
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		if (pGroup->FindEntry(key, pDator))
		{
			ret = true;
		}
	}
	return ret;
}

void AutoSetting::LoadSettingsInternal(const std::string& iniContent)
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
			const std::string& groupStr = iniContent.substr(pos, pos2 - pos);
			groups.push_back(groupStr);
			pos = ii;
			findEnd = true;
		}
	}

	//add the last
	if (findEnd)
	{
		pos2 = iniContent.length() - 1;
		const std::string& groupStr = iniContent.substr(pos, pos2 - pos);
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

std::string AutoSetting::GetIniContentsInternal()
{
	std::string dataOut;
	for (auto& iter : m_Groups)
	{
		AutoSettingSerializerOut builder(&dataOut);
		builder.IO(iter);	
	}
	return dataOut;
}

void AutoSetting::AddKeyGroup(const std::string& group, const std::string& key, IDator* pDator, bool DatorPersists)
{
	AutoSettingGroup hold;
	hold.SetEntry(key, pDator, DatorPersists);
	hold.SetName(group);
	m_Groups.push_back(hold);
}

bool AutoSetting::FindGroupInternal(const std::string& group, AutoSettingGroup** ppGroup)
{
	bool ret = false;
	std::vector< AutoSettingGroup >::iterator iter;
	for (iter = m_Groups.begin(); iter != m_Groups.end(); iter++)
	{
		if ((iter->GetName() == group))
		{
			ret = true;
			(*ppGroup) = &(*iter);
			break;
		}
	}
	return ret;
}

void AutoSetting::DeleteKeyGroup(const std::string& group, const std::string& key)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		pGroup->DeleteEntry(key);
	}
}

void AutoSetting::DeleteGroupInternal(const std::string& group)
{
	std::vector< AutoSettingGroup >::iterator iter;
	for (iter = m_Groups.begin(); iter != m_Groups.end(); iter++)
	{
		if ((iter->GetName() == group))
		{
			m_Groups.erase(iter);
			break;
		}
	}
}



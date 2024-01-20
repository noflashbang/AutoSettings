#include "AutoSetting.h"

void AutoSetting::SetSetting(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		pGroup->SetEntry(key, pDator);
	}
	else
	{
		AddKeyGroup(group, key, pDator);
	}
}

void AutoSetting::GetSetting(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		pGroup->GetEntry(key, pDator);
	}
	else
	{
		AddKeyGroup(group, key, pDator);
	}
}

bool AutoSetting::FindSetting(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator)
{
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

void AutoSetting::DeleteSetting(const AS_String& group, const AS_String& key)
{
	DeleteKeyGroup(group, key);
}

void AutoSetting::LoadSettings(const std::string& iniContent)
{
	LoadSettingsInternal(iniContent);
}

void AutoSetting::DeleteGroup(const AS_String& group)
{
	DeleteGroupInternal(group);
}

std::string AutoSetting::GetIniContents()
{
	return GetIniContentsInternal();
}

void AutoSetting::LoadSettingsInternal(const std::string& iniContent)
{
	std::vector<std::string> groups;
	auto start = std::find(iniContent.begin(), iniContent.end(), '[');
	if (start == iniContent.end())
	{
		return;
	}
	
	do
	{
		auto next = std::find(start + 1, iniContent.end(), '[');
		groups.push_back(std::string(start, next-1));
		start = next;
	} 
	while (start != iniContent.end());
	
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

void AutoSetting::AddKeyGroup(const AS_String& group, const AS_String& key, const std::shared_ptr<IDator> pDator)
{
	AutoSettingGroup hold;
	hold.SetEntry(key, pDator);
	hold.SetName(group);
	m_Groups.push_back(hold);
}

bool AutoSetting::FindGroupInternal(const AS_String& group, AutoSettingGroup** ppGroup)
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

void AutoSetting::DeleteKeyGroup(const AS_String& group, const AS_String& key)
{
	AutoSettingGroup* pGroup = NULL;
	if (FindGroupInternal(group, &pGroup))
	{
		pGroup->DeleteEntry(key);
	}
}

void AutoSetting::DeleteGroupInternal(const AS_String& group)
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



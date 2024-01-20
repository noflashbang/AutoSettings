#include "AutoSettingGroup.h"

AutoSettingGroup::AutoSettingGroup(const AutoSettingGroup& other)
{
	m_GroupName = other.m_GroupName;
	m_Entries = other.m_Entries;
};
AutoSettingGroup& AutoSettingGroup::operator=(const AutoSettingGroup& other)
{
	if (this != &other)
	{
		m_GroupName = other.m_GroupName;
		m_Entries = other.m_Entries;
	}
	return (*this);
};
void AutoSettingGroup::SetName(const AS_String& name)
{
	m_GroupName = name;
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

void AutoSettingGroup::SetEntry(const AS_String& key, const std::shared_ptr<IDator> pDator)
{
	AutoSettingEntry* pHold = nullptr;
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == key)
		{
			pHold = &(*iter);
			break;
		}
	}
	if (pHold != nullptr)
	{
		pHold->SetValue(pDator);
	}
	else
	{
		AutoSettingEntry entry(key, pDator);
		m_Entries.push_back(entry);
	}
};

void AutoSettingGroup::GetEntry(const AS_String& key, const std::shared_ptr<IDator> pDator)
{
	AutoSettingEntry* pHold = NULL;
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == key)
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
		AutoSettingEntry entry(key, pDator);
		m_Entries.push_back(entry);
	}
};

bool AutoSettingGroup::FindEntry(const AS_String& key, const std::shared_ptr<IDator> pDator)
{
	bool ret = false;
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == key)
		{
			pDator->SetValue(iter->GetValue());
			ret = true;
			break;
		}
	}
	return ret;
};
void AutoSettingGroup::DeleteEntry(const AS_String& key)
{
	std::vector<AutoSettingEntry>::iterator iter;
	for (iter = m_Entries.begin(); iter != m_Entries.end(); iter++)
	{
		if (iter->GetKey() == key)
		{
			m_Entries.erase(iter);
			break;
		}
	}
};

AS_String AutoSettingGroup::GetName()
{
	return m_GroupName;
}

void AutoSettingGroup::GetEntries(std::vector<AutoSettingEntry*>& entries)
{
	entries.clear();
	entries.reserve(m_Entries.size());
	std::for_each(m_Entries.begin(), m_Entries.end(), [&entries](AutoSettingEntry& entry) { entries.push_back(&entry); });
}


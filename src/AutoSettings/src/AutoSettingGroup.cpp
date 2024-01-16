#include "AutoSettingGroup.h"

AutoSettingGroup::AutoSettingGroup(const AutoSettingGroup& other)
{
	m_GroupName = other.m_GroupName;
	m_Entries = other.m_Entries;
	m_Save = other.m_Save;
};
AutoSettingGroup& AutoSettingGroup::operator=(const AutoSettingGroup& other)
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
	Util::StringToUpper(Name);
	Util::StringTrim(Name);
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
	Util::StringToUpper(Key);
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
	Util::StringToUpper(Key);
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
		if (pHold->GetDatored())
		{
			pHold->Update();
		}
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
	Util::StringToUpper(Key);
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
	Util::StringToUpper(Key);
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

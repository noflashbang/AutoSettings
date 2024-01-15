#include "AutoSettingEntry.h"

AutoSettingEntry::AutoSettingEntry(const AutoSettingEntry& other)
{
	m_Key = other.m_Key;
	m_Value = other.m_Value;
	m_Datored = other.m_Datored;
	m_Loaded = other.m_Loaded;
	m_Added = other.m_Added;
	m_Save = other.m_Save;
	m_pDator = other.m_pDator;
};
AutoSettingEntry& AutoSettingEntry::operator=(const AutoSettingEntry& other)
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
#include "AutoSettingEntry.h"

AutoSettingEntry::AutoSettingEntry(const std::string& key, const std::shared_ptr<IDator> pDator)
{
	m_Key = key;
	Util::StringToUpper(m_Key);
	Util::StringTrim(m_Key);

	m_Value = "";
	m_pDator = std::weak_ptr(pDator);
	Update();
};

AutoSettingEntry::AutoSettingEntry(const AutoSettingEntry& other)
{
	m_Key = other.m_Key;
	m_Value = other.m_Value;
	m_pDator = other.m_pDator;
};
AutoSettingEntry::~AutoSettingEntry()
{
};
AutoSettingEntry& AutoSettingEntry::operator=(const AutoSettingEntry& other)
{
	if (this != &other)
	{
		m_Key = other.m_Key;
		m_Value = other.m_Value;
		m_pDator = other.m_pDator;
	}
	return (*this);
};

void AutoSettingEntry::SetKey(const std::string& key)
{
	m_Key = key;
	Util::StringToUpper(m_Key);
	Util::StringTrim(m_Key);
};
void AutoSettingEntry::SetValue(const std::shared_ptr<IDator> pDator)
{
	m_Value = pDator->GetValue();
	m_pDator = std::weak_ptr(pDator);
};
void AutoSettingEntry::SetValue(const std::string& Value)
{
	m_Value = Value;
};

std::string AutoSettingEntry::GetKey()
{
	return m_Key;
};
std::string AutoSettingEntry::GetValue()
{
	Update(); //update the value from the dator if it exists
	return m_Value;
};

void AutoSettingEntry::Update()
{
	std::shared_ptr<IDator> pDator = m_pDator.lock();
	if (pDator != nullptr)
	{
		m_Value = pDator->GetValue();
	}
};
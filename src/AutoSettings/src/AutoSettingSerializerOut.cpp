#include "AutoSettingSerializerOut.h"


bool AutoSettingSerializerOut::IO(AutoSettingEntry& io)
{
	m_Data->append(io.GetKey());
	m_Data->append("=");
	m_Data->append(io.GetValue());
	m_Data->append("\n");

	return true;
}
bool AutoSettingSerializerOut::IO(AutoSettingGroup& io)
{
	m_Data->append("[");
	m_Data->append(io.GetName());
	m_Data->append("]\n");

	std::vector<AutoSettingEntry*> entries;
	io.GetEntries(entries);

	std::for_each(entries.begin(), entries.end(), [&](AutoSettingEntry* pEntry)
	{
		AutoSettingEntry hold = (*pEntry);
		this->IO(hold);
	});
	return true;
}

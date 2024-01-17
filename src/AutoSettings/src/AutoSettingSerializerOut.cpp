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

	std::vector<AutoSettingEntry*> Entries;
	io.GetAllEntries(&Entries);

	for (AutoSettingEntry* pEntry : Entries)
	{
		if (pEntry->GetSave())
		{
			AutoSettingEntry hold = (*pEntry);
			this->IO(hold);
		}
	}

	return true;
}

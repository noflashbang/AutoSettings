#pragma once

#include "StandardLib.h"
#include "AS_String.h"
#include "IDator.h"
#include "Dator.h"
#include "AutoSettingEntry.h"

class AutoSettingGroup //Holds Section titles and an array of entries
{
public:
	AutoSettingGroup()
	{
		m_GroupName = "";
	};
	~AutoSettingGroup() {};

	AutoSettingGroup(const AutoSettingGroup& other);
	AutoSettingGroup& operator=(const AutoSettingGroup& other);

	void SetName(const AS_String& name);

	void AddEntry(AutoSettingEntry* pEntry);

	void SetEntry(const AS_String& key, const std::shared_ptr<IDator> pDator);

	void GetEntry(const AS_String& key, const std::shared_ptr<IDator> pDator);

	bool FindEntry(const AS_String& key, const std::shared_ptr<IDator> pDator);
	void DeleteEntry(const AS_String& key);

	AS_String GetName();

	void GetEntries(std::vector<AutoSettingEntry*>& entries);

private:
	AS_String m_GroupName;
	std::vector<AutoSettingEntry> m_Entries;
};

#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "IDator.h"
#include "Dator.h"
#include "AutoSettingEntry.h"

class AutoSettingGroup //Holds Section titles and an array of entries
{
public:
	AutoSettingGroup()
	{
		m_GroupName = "";
		m_Save = false;
	};
	~AutoSettingGroup() {};

	AutoSettingGroup(const AutoSettingGroup& other);
	AutoSettingGroup& operator=(const AutoSettingGroup& other);

	void SetName(const std::string& name);

	void AddEntry(AutoSettingEntry* pEntry);

	void SetEntry(const std::string& key, const std::shared_ptr<IDator> pDator);

	void GetEntry(const std::string& key, const std::shared_ptr<IDator> pDator);

	bool FindEntry(const std::string& key, const std::shared_ptr<IDator> pDator);
	void DeleteEntry(const std::string& key);

	std::string GetName();

	void GetEntries(std::vector<AutoSettingEntry*>& entries);

private:
	std::string m_GroupName;
	std::vector<AutoSettingEntry> m_Entries;
	bool m_Save;
};

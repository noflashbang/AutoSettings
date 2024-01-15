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

	void SetName(std::string Name);

	void AddEntry(AutoSettingEntry* pEntry);

	void SetEntry(std::string Key, IDator* pDator, bool DatorPersists = false);
	template<typename T>
	void SetEntry(std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		SetEntry(Key, &typeDator, false);
	};

	void GetEntry(std::string Key, IDator* pDator, bool DatorPersists = false);
	template<typename T>
	void GetEntry(std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		GetEntry(Key, &typeDator, false);
	};

	bool FindEntry(std::string Key, IDator* pDator);
	void DeleteEntry(std::string Key);

	void SetSave(bool Save);

	std::string GetName();
	bool GetSave();

	void GetAllEntries(std::vector<AutoSettingEntry* >* pEntries);
private:
	std::string m_GroupName;
	std::vector< AutoSettingEntry > m_Entries;
	bool m_Save;
};

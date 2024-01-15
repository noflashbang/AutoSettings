#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "IDator.h"

class AutoSettingEntry //Holds the Key and Value information for an ini entry
{
public:
	AutoSettingEntry()
	{
		m_Key = "";
		m_Value = "";
		m_Datored = false;
		m_Loaded = false;
		m_Added = false;
		m_Save = false;
		m_pDator = 0;
	};
	~AutoSettingEntry() {};

	AutoSettingEntry(const AutoSettingEntry& other);
	AutoSettingEntry& operator=(const AutoSettingEntry& other);

	void SetKey(std::string key);
	void SetValue(IDator* pDator, bool DatorPersists = false);
	void SetValue(std::string Value);
	void ClearDatored();
	void SetLoaded(bool Loaded);
	void SetAdded(bool Added);
	void SetSave(bool Save);

	std::string GetKey();
	std::string GetValue();
	bool GetDatored();
	bool GetLoaded();
	bool GetAdded();
	bool GetSave();

	void Update();

private:
	std::string m_Key;
	std::string m_Value;
	bool m_Datored; //indicates that this entry has been assigned to a dator(or in otherwords is in use)
	bool m_Loaded; //indicates that this entry has been loaded from an existing INI 
	bool m_Added; //indicates that this entry as been added
	bool m_Save; //used to indicate that this entry should be saved
	IDator* m_pDator; //used in update on save
};


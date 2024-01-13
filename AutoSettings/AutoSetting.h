#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Util.h"
#include "Dator.h"
#include "DatorArray.h"
#include "SerialIn.h"
#include "SerialOut.h"



enum AUTOSETTING_CODE
{
	AS_ALL = -1,
	AS_DATORED = 1,
	AS_LOADED = 2,
	AS_ADDED = 4,
	AS_UPDATE = 8
};
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

	AutoSettingEntry(const AutoSettingEntry &other);
	AutoSettingEntry& operator=(const AutoSettingEntry &other);

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

class AutoSettingGroup //Holds Section titles and an array of entries
{
public:
	AutoSettingGroup()
	{
		m_GroupName = "";
		m_Save = false;
	};
	~AutoSettingGroup() {};

	AutoSettingGroup(const AutoSettingGroup &other);
	AutoSettingGroup& operator=(const AutoSettingGroup &other);

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

class AutoSettingSerializerOut : public SerializerOut
{
public:
	AutoSettingSerializerOut(std::string data) :SerializerOut(data) {};
	virtual ~AutoSettingSerializerOut() {};

	virtual bool IO(AutoSettingEntry &io);
	virtual bool IO(AutoSettingGroup &io);

protected:
	AutoSettingSerializerOut() = delete;
};

class AutoSettingSerializerIn : public SerializerIn
{
public:
	AutoSettingSerializerIn(std::string data) :SerializerIn(data) {};
	virtual ~AutoSettingSerializerIn() {};

	virtual bool IO(AutoSettingEntry &io);
	virtual bool IO(AutoSettingGroup &io);

protected:
	AutoSettingSerializerIn() = delete;
};

class AutoSetting
{
public:
	AutoSetting()
	{
		m_FilePath = "";
	};
	AutoSetting(char* path)
	{
		LoadSettings(path);
	};
	AutoSetting(std::string path)
	{
		LoadSettings(path);
	};
	~AutoSetting()
	{
	};

	//sets a value -> if not found it will be added, if found the ini value will be updated
	void SetSetting(std::string Group, std::string Key, IDator* pDator);
	void SetSetting(char* pGroup, char* pKey, IDator* pDator);

	//retrives a value -> if not found it will be added, if found the dator value will be updated
	void GetSetting(std::string Group, std::string Key, IDator* pDator);
	void GetSetting(char* pGroup, char* pKey, IDator* pDator);

	//retrives a value -> if not found it will not be added, if found the dator value will be updated (true on success)
	bool FindSetting(std::string Group, std::string Key, IDator* pDator);
	bool FindSetting(char* pGroup, char* pKey, IDator* pDator);

	//removes a setting
	void DeleteSetting(std::string Group, std::string Key);
	void DeleteSetting(char* pGroup, char* pKey);

	//removes a group
	void DeleteGroup(std::string Group);
	void DeleteGroup(char* Group);

	//parses an ini file
	void LoadSettings(std::string path);
	void LoadSettings(char* path);

	//creates an ini file
	void SaveSettings(std::string path, int Mode = AS_ALL);
	void SaveSettings(char* path, int Mode = AS_ALL);

	//Add/replace a group
	void AddGroup(std::string Group, AutoSettingGroup* pGroup);
	void AddGroup(char* Group, AutoSettingGroup* pGroup);

	//retrives a group (true on success)
	bool FindGroup(std::string Group, AutoSettingGroup* pGroup);
	bool FindGroup(char* Group, AutoSettingGroup* pGroup);

	//retrives all the groups
	void GetAllGroups(std::vector< AutoSettingGroup >* pGroups);

	template<typename T>
	void SetSettingDirect(std::string Group, std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		SetSettingInternal(Group, Key, &typeDator, false);
	};
	template<typename T>
	void SetSettingDirect(char* pGroup, char* pKey, T& Data)
	{
		std::string stdGroup = pGroup;
		std::string stdKey = pKey;
		SetSettingDirect(stdGroup, stdKey, Data);
	};
	template<typename T>
	void SetSettingDirectArray(std::string Group, std::string Key, std::vector<T>& Data)
	{
		DatorArray<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		SetSettingInternal(Group, Key, &typeDator, false);
	};
	template<typename T>
	void SetSettingDirectArray(char* pGroup, char* pKey, std::vector<T>& Data)
	{
		std::string stdGroup = pGroup;
		std::string stdKey = pKey;
		SetSettingDirectArray(stdGroup, stdKey, Data);
	};
	template<typename T>
	void GetSettingDirect(std::string Group, std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		GetSettingInternal(Group, Key, &typeDator, false);
	};
	template<typename T>
	void GetSettingDirect(char* pGroup, char* pKey, T& Data)
	{
		std::string stdGroup = pGroup;
		std::string stdKey = pKey;
		GetSettingDirect(stdGroup, stdKey, Data);
	};
	template<typename T>
	void GetSettingDirectArray(std::string Group, std::string Key, std::vector<T>& Data)
	{
		DatorArray<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		GetSettingInternal(Group, Key, &typeDator, false);
	};
	template<typename T>
	void GetSettingDirectArray(char* pGroup, char* pKey, std::vector<T>& Data)
	{
		std::string stdGroup = pGroup;
		std::string stdKey = pKey;
		GetSettingDirectArray(stdGroup, stdKey, Data);
	};
	template<typename T>
	bool FindSettingDirect(std::string Group, std::string Key, T& Data)
	{
		Dator<T> typeDator(Data);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		return FindSettingInternal(Group, Key, &typeDator, false);
	};
	template<typename T>
	bool FindSettingDirect(char* pGroup, char* pKey, T& Data)
	{
		std::string stdGroup = pGroup;
		std::string stdKey = pKey;
		return FindSettingDirect(stdGroup, stdKey, Data);
	};
	template<typename T>
	bool FindSettingDirectArray(std::string Group, std::string Key, T* Data, int len)
	{
		DatorArray<T> typeDator(Data, len);
		Util::StringToUpper(&Group);
		Util::StringToUpper(&Key);
		return FindSettingInternal(Group, Key, &typeDator, false);
	};
	template<typename T>
	bool FindSettingDirectArray(char* pGroup, char* pKey, T* Data, int len)
	{
		std::string stdGroup = pGroup;
		std::string stdKey = pKey;
		return FindSettingDirectArray(stdGroup, stdKey, Data, len);
	};

protected:
	void SetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	void GetSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	bool FindSettingInternal(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	void LoadSettingsInternal(std::string path);
	void SaveSettingsInternal(std::string path, int Mode);
	//bool FindKeyGroup(std::string Group, std::string Key, CAutoSetEntry** pASEout);
	void AddKeyGroup(std::string Group, std::string Key, IDator* pDator, bool DatorPersists = false);
	bool FindGroupInternal(std::string Group, AutoSettingGroup** ppGroup);
	void DeleteKeyGroup(std::string Group, std::string Key);
	void AddGroupInternal(AutoSettingGroup* pGroup);
	void DeleteGroupInternal(std::string Group);

private:
	std::string m_FilePath;
	std::vector< AutoSettingGroup > m_Groups;
};






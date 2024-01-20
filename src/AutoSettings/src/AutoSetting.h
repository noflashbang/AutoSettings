#pragma once

#include "StandardLib.h"

#include "Util.h"
#include "Dator.h"
#include "SerialIn.h"
#include "SerialOut.h"
#include "AutoSettingEntry.h"
#include "AutoSettingGroup.h"
#include "AutoSettingSerializerIn.h"
#include "AutoSettingSerializerOut.h"

class AutoSetting
{
public:
	AutoSetting()
	{
	};

	AutoSetting(const std::string& iniContent)
	{
		LoadSettings(iniContent);
	};

	~AutoSetting()
	{
	};

	template<typename T>
	std::shared_ptr<IDator> CreateDator(T& data)
	{
		return std::make_shared<Dator<T>>(data);
	}

	//sets a value -> if not found it will be added, if found the ini value will be updated
	void SetSetting(const std::string& group, const std::string& key, const std::shared_ptr<IDator> pDator);

	//retrives a value -> if not found it will be added, if found the dator value will be updated
	void GetSetting(const std::string& group, const std::string& key, const std::shared_ptr<IDator> pDator);

	//retrives a value -> if not found it will not be added, if found the dator value will be updated (true on found)
	bool FindSetting(const std::string& group, const std::string& key, const std::shared_ptr<IDator> pDator);

	void DeleteSetting(const std::string& group, const std::string& key);

	void DeleteGroup(const std::string& group);

	void LoadSettings(const std::string& iniContent);

	std::string GetIniContents();

	template<typename T>
	void SetSetting(const std::string& group, const std::string& key, T& data)
	{
		std::shared_ptr<IDator> typeDator = std::make_shared<Dator<T>>(data);
		SetSettingInternal(group, key, &typeDator);
	};

	//template<typename T>
	//void SetSetting(const std::string& group, const std::string& key, std::vector<T>& Data)
	//{
	//	std::shared_ptr<IDator> typeDator = std::make_shared<TypeDator<T>>(Data);
	//	SetSettingInternal(Group, Key, &typeDator);
	//};

	template<typename T>
	void GetSetting(const std::string& group, const std::string& key, T& data)
	{
		std::shared_ptr<IDator> typeDator = std::make_shared<Dator<T>>(data);
		GetSettingInternal(group, key, &typeDator);
	};

	//template<typename T>
	//void GetSetting(const std::string& group, const std::string& key, std::vector<T>& Data)
	//{
	//	std::shared_ptr<IDator> typeDator = std::make_shared<TypeDator<T>>(Data);
	//	GetSettingInternal(Group, Key, &typeDator);
	//};

	template<typename T>
	bool FindSetting(const std::string& group, const std::string& key, T& data)
	{
		std::shared_ptr<IDator> typeDator = std::make_shared<Dator<T>>(data);
		return FindSettingInternal(group, key, &typeDator);
	};

	//template<typename T>
	//bool FindSetting(const std::string& group, const std::string& key, std::vector<T>& Data)
	//{
	//	std::shared_ptr<IDator> typeDator = std::make_shared<TypeDator<T>>(Data);
	//	return FindSettingInternal(Group, Key, &typeDator);
	//};

protected:

	void LoadSettingsInternal(const std::string& iniContent);

	std::string GetIniContentsInternal();
	
	void AddKeyGroup(const std::string& group, const std::string& key, const std::shared_ptr<IDator> pDator);
	
	bool FindGroupInternal(const std::string& group, AutoSettingGroup** ppGroup);
	void DeleteKeyGroup(const std::string& group, const std::string& key);
	
	void DeleteGroupInternal(const std::string& group);

private:
	std::vector<AutoSettingGroup> m_Groups;
};






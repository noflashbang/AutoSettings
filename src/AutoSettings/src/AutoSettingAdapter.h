#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "AutoSetting.h"
#include "AutoSettingCore.h"


struct AutoSettingBundle
{
	AutoSettingHandle hAutoSetting;
	std::unique_ptr<AutoSetting> pAutoSetting;
	std::vector<std::unique_ptr<IDator>> Dators;
};

class AutoSettingAdapter
{
public:

	static AutoSettingHandle AutoSet_Create(const std::string& iniContents);
	static AutoSettingHandle AutoSet_Create();
	static std::string AutoSet_GetIniContents(AutoSettingHandle handle, AutoSettingMode mode);
	static void AutoSet_Destroy(AutoSettingHandle handle);
	static void AutoSet_DeleteSetting(AutoSettingHandle handle, const std::string& group, const std::string& key);
	static void AutoSet_DeleteGroup(AutoSettingHandle handle, const std::string& group);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value,                      bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value,                   bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value,                     bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value,              bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value,         bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value,      bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value,        bool attachDator = false);
	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator = false);

	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value,                      bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value,                   bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value,                     bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value,              bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value,         bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value,      bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value,        bool attachDator = false);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator = false);

protected:

	template<typename T>
	void SetSetting(const AutoSettingBundle* bundle, const std::string& Group, const std::string& Key, T& Data, bool attachDator)
	{
		if (attachDator)
		{
			// Create a dator for this setting
			bundle->Dators.push_back(std::make_unique<IDator>(new Dator<T>(Data)));
			bundle->pAutoSetting->SetSetting(Group, Key, Dator);
		}
		else
		{
			bundle->pAutoSetting->SetSettingDirect(Group, Key, Data);
		}
	};

	template<typename T>
	void GetSetting(const AutoSettingBundle* bundle, const std::string& Group, const std::string& Key, T& Data, bool attachDator)
	{
		if (attachDator)
		{
			// Create a dator for this setting
			bundle->Dators.push_back(std::make_unique<IDator>(new Dator<T>(Data)));
			bundle->pAutoSetting->GetSetting(Group, Key, pDator);
		}
		else
		{
			bundle->pAutoSetting->GetSettingDirect(Group, Key, Data);
		}
	};

	static AutoSettingAdapter* GetInstance();
	AutoSettingAdapter();
	~AutoSettingAdapter();

private:
	static AutoSettingAdapter* m_Instance;

	AutoSettingHandle AddAutoSettingBundle(AutoSettingBundle bundle);
	AutoSettingBundle* GetAutoSettingBundle(AutoSettingHandle hAutoSetting);
	void RemoveAutoSettingBundle(AutoSettingHandle hAutoSetting);
	std::vector<AutoSettingBundle> m_AutoSettings;
	std::mutex m_mtx;
};


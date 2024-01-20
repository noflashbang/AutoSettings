#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "AutoSetting.h"
#include "AutoSettingCore.h"


struct AutoSettingBundle
{
	AutoSettingHandle hAutoSetting;
	std::unique_ptr<AutoSetting> pAutoSetting;

	//default constructor
	AutoSettingBundle() : hAutoSetting(0), pAutoSetting(nullptr)
	{
	}

	//move constructor
	AutoSettingBundle(AutoSettingBundle&& other) noexcept
	{
		hAutoSetting = other.hAutoSetting;
		pAutoSetting = std::move(other.pAutoSetting);
	}

	//move assignment
	AutoSettingBundle& operator=(AutoSettingBundle&& other) noexcept
	{
		if (this != &other)
		{
			hAutoSetting = other.hAutoSetting;
			pAutoSetting = std::move(other.pAutoSetting);
		}
		return (*this);
	}
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

	static void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, const std::shared_ptr<IDator>& value);
	static void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, const std::shared_ptr<IDator>& value);

	template<typename T>
	static std::shared_ptr<IDator> AutoSet_CreateDator(const AutoSettingHandle handle, T& data)
	{
		AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
		const AutoSettingBundle* bundle = pAdapter->GetAutoSettingBundle(handle);
		if (bundle != nullptr)
		{
			return bundle->pAutoSetting->CreateDator(data);
		}
		return nullptr;
	};
protected:
	static AutoSettingAdapter* GetInstance();
	AutoSettingAdapter();
	~AutoSettingAdapter();

private:
	static AutoSettingAdapter* m_Instance;

	AutoSettingHandle AddAutoSettingBundle(AutoSettingBundle& bundle);
	AutoSettingBundle* GetAutoSettingBundle(AutoSettingHandle hAutoSetting);
	void RemoveAutoSettingBundle(AutoSettingHandle hAutoSetting);
	std::vector<AutoSettingBundle> m_AutoSettings;
	std::mutex m_mtx;
};


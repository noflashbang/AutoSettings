#include "AutoSettingAdapter.h"

AutoSettingAdapter* AutoSettingAdapter::m_Instance = nullptr;

AutoSettingHandle AutoSettingAdapter::AutoSet_Create(const std::string& iniContents)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle;

	//use nanoseconds from clock as handle
	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
	bundle.hAutoSetting = ns.count();
	bundle.pAutoSetting = std::make_unique<AutoSetting>(iniContents);
	return pAdapter->AddAutoSettingBundle(bundle);	
}

AutoSettingHandle AutoSettingAdapter::AutoSet_Create()
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle;
	//use nanoseconds from clock as handle
	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
	bundle.hAutoSetting = ns.count();
	bundle.pAutoSetting = std::make_unique<AutoSetting>();
	return pAdapter->AddAutoSettingBundle(bundle);
}

std::string AutoSettingAdapter::AutoSet_GetIniContents(AutoSettingHandle handle)
{
	std::string ret;
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	const AutoSettingBundle* bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle != nullptr)
	{
		ret = bundle->pAutoSetting->GetIniContents();
	}
	return ret;
}

void AutoSettingAdapter::AutoSet_Destroy(AutoSettingHandle handle)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	pAdapter->RemoveAutoSettingBundle(handle);
}

void AutoSettingAdapter::AutoSet_DeleteSetting(AutoSettingHandle handle, const std::string& group, const std::string& key)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	const AutoSettingBundle* bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle != nullptr)
	{
		bundle->pAutoSetting->DeleteSetting(group, key);
	}
}
void AutoSettingAdapter::AutoSet_DeleteGroup(AutoSettingHandle handle, const std::string& group)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	const AutoSettingBundle* bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle != nullptr)
	{
		bundle->pAutoSetting->DeleteGroup(group);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, const std::shared_ptr<IDator>& value)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	const AutoSettingBundle* bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle != nullptr)
	{
		bundle->pAutoSetting->SetSetting(group, key, value);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, const std::shared_ptr<IDator>& value)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	const AutoSettingBundle* bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle != nullptr)
	{
		bundle->pAutoSetting->GetSetting(group, key, value);
	}
}

AutoSettingAdapter* AutoSettingAdapter::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new AutoSettingAdapter();
	}
	return m_Instance;
}

AutoSettingAdapter::AutoSettingAdapter()
{

}

AutoSettingAdapter::~AutoSettingAdapter()
{

}

AutoSettingHandle AutoSettingAdapter::AddAutoSettingBundle(AutoSettingBundle& bundle)
{
	std::lock_guard<std::mutex> lock(m_mtx);
	{
		m_AutoSettings.push_back(std::move(bundle));
		return (AutoSettingHandle)bundle.hAutoSetting;
	}
}
AutoSettingBundle* AutoSettingAdapter::GetAutoSettingBundle(AutoSettingHandle hAutoSetting)
{
	std::lock_guard<std::mutex> lock(m_mtx);
	{
		//look for the handle in the list
		std::vector<AutoSettingBundle>::iterator iter;
		for (iter = m_AutoSettings.begin(); iter != m_AutoSettings.end(); iter++)
		{
			if (iter->hAutoSetting == hAutoSetting)
			{
				return &(*iter);
			}
		}
	}
	//if we get here, we didn't find it
	return nullptr;
}
void AutoSettingAdapter::RemoveAutoSettingBundle(AutoSettingHandle hAutoSetting)
{
	std::lock_guard<std::mutex> lock(m_mtx);
	{
		//remove the handle from the list
		std::vector<AutoSettingBundle>::iterator iter;
		for (iter = m_AutoSettings.begin(); iter != m_AutoSettings.end(); iter++)
		{
			if (iter->hAutoSetting == hAutoSetting)
			{
				m_AutoSettings.erase(iter);
				break;
			}
		}
	}
}



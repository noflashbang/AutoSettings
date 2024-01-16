#include "AutoSettingAdapter.h"

AutoSettingAdapter* AutoSettingAdapter::m_Instance = nullptr;

AutoSettingHandle AutoSettingAdapter::AutoSet_Create(const std::string& iniContents)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle;
	bundle.pAutoSetting = new AutoSetting(iniContents);
	return pAdapter->AddAutoSettingBundle(bundle);
}

AutoSettingHandle AutoSettingAdapter::AutoSet_Create()
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle;
	bundle.pAutoSetting = new AutoSetting();
	return pAdapter->AddAutoSettingBundle(bundle);
}

std::string AutoSettingAdapter::AutoSet_GetIniContents(AutoSettingHandle handle, AutoSettingMode mode)
{
	std::string ret;
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		ret = bundle.pAutoSetting->GetIniContents(mode);
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
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		bundle.pAutoSetting->DeleteSetting(group, key);
	}
}
void AutoSettingAdapter::AutoSet_DeleteGroup(AutoSettingHandle handle, const std::string& group)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		bundle.pAutoSetting->DeleteGroup(group);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);
	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->SetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
	}
}

void AutoSettingAdapter::AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator)
{
	AutoSettingAdapter* pAdapter = AutoSettingAdapter::GetInstance();
	AutoSettingBundle bundle = pAdapter->GetAutoSettingBundle(handle);

	if (bundle.pAutoSetting != nullptr)
	{
		pAdapter->GetSetting(bundle, group, key, value, attachDator);
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

AutoSettingHandle AutoSettingAdapter::AddAutoSettingBundle(AutoSettingBundle bundle)
{
	m_AutoSettings.push_back(bundle);
	return (AutoSettingHandle)bundle.pAutoSetting;
}
AutoSettingBundle AutoSettingAdapter::GetAutoSettingBundle(AutoSettingHandle hAutoSetting)
{
	//look for the handle in the list
	std::vector<AutoSettingBundle>::iterator iter;
	for (iter = m_AutoSettings.begin(); iter != m_AutoSettings.end(); iter++)
	{
		if (iter->pAutoSetting == hAutoSetting)
		{
			return (*iter);
		}
	}
	//if we get here, we didn't find it
	AutoSettingBundle bundle;
	bundle.pAutoSetting = nullptr;
	bundle.pDators.clear();
	return bundle;
}
void AutoSettingAdapter::RemoveAutoSettingBundle(AutoSettingHandle hAutoSetting)
{
	//remove the handle from the list
	std::vector<AutoSettingBundle>::iterator iter;
	for (iter = m_AutoSettings.begin(); iter != m_AutoSettings.end(); iter++)
	{
		if (iter->pAutoSetting == hAutoSetting)
		{
			//delete the AutoSetting
			delete iter->pAutoSetting;
			 //delete all dators
			std::vector<IDator*>::iterator iterDator;
			for (iterDator = iter->pDators.begin(); iterDator != iter->pDators.end(); iterDator++)
			{
				delete (*iterDator);
			}

			m_AutoSettings.erase(iter);
			break;
		}
	}
}



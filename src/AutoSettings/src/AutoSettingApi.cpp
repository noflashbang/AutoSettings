#include "AutoSettingApi.h"
#include "AutoSettingAdapter.h"

AUTOSET_API AutoSettingHandle AutoSetting_Create(const std::string& iniContents)
{
	return AutoSettingAdapter::AutoSet_Create(iniContents);
}
AUTOSET_API AutoSettingHandle AutoSetting_Create()
{
	return AutoSettingAdapter::AutoSet_Create();
}
AUTOSET_API void AutoSetting_Destroy(const AutoSettingHandle handle)
{
	AutoSettingAdapter::AutoSet_Destroy(handle);
}
AUTOSET_API std::string AutoSetting_GetIniContents(const AutoSettingHandle handle, AutoSettingMode mode)
{
	return AutoSettingAdapter::AutoSet_GetIniContents(handle, mode);
}
AUTOSET_API void AutoSetting_DeleteSetting(const AutoSettingHandle handle, const std::string& group, const std::string& key)
{
	AutoSettingAdapter::AutoSet_DeleteSetting(handle, group, key);
}
AUTOSET_API void AutoSetting_DeleteGroup(const AutoSettingHandle handle, const std::string& group)
{
	AutoSettingAdapter::AutoSet_DeleteGroup(handle, group);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, int& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, double& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, bool& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, std::string& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, std::vector<int>& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, std::vector<double>& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, std::vector<bool>& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API std::shared_ptr<IDator> AutoSetting_CreateDator(const AutoSettingHandle handle, std::vector<std::string>& value)
{
	return AutoSettingAdapter::AutoSet_CreateDator(handle, value);
}
AUTOSET_API void AutoSetting_SetSetting(const AutoSettingHandle handle, const std::string& group, const std::string& key, const std::shared_ptr<IDator>& value)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value);
}
AUTOSET_API void AutoSetting_GetSetting(const AutoSettingHandle handle, const std::string& group, const std::string& key, const std::shared_ptr<IDator>& value)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value);
}


#include "AutoSettingApi.h"
#include "AutoSettingAdapter.h"

AUTOSET_API AutoSettingHandle AutoSet_Create(const std::string& path)
{
	return AutoSettingAdapter::AutoSet_Create(path);
}
AUTOSET_API void AutoSet_Destroy(AutoSettingHandle handle)
{
	AutoSettingAdapter::AutoSet_Destroy(handle);
}
AUTOSET_API void AutoSet_Save(AutoSettingHandle handle, const std::string& path, AutoSettingMode mode)
{
	AutoSettingAdapter::AutoSet_Save(handle, path, mode);
}
AUTOSET_API void AutoSetting_DeleteSetting(AutoSettingHandle handle, const std::string& group, const std::string& key)
{
	AutoSettingAdapter::AutoSet_DeleteSetting(handle, group, key);
}
AUTOSET_API void AutoSetting_DeleteGroup(AutoSettingHandle handle, const std::string& group)
{
	AutoSettingAdapter::AutoSet_DeleteGroup(handle, group);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_SetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator)
{
	AutoSettingAdapter::AutoSet_GetSetting(handle, group, key, value, attachDator);
}

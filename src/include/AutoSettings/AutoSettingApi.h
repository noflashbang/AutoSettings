//MIT License
//
//Copyright(c) 2024 noflashbang
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#pragma once

#include <string>
#include <vector>

#include "AutoSettingCore.h"

#ifdef AUTOSET_EXPORTS
#define AUTOSET_API __declspec(dllexport)
#else
#define AUTOSET_API __declspec(dllimport) 
#endif

AUTOSET_API AutoSettingHandle AutoSet_Create(const std::string& iniContents);
AUTOSET_API AutoSettingHandle AutoSet_Create();
AUTOSET_API void AutoSet_Destroy(AutoSettingHandle handle);
AUTOSET_API std::string AutoSet_GetIniContents(AutoSettingHandle handle, AutoSettingMode mode);
AUTOSET_API void AutoSetting_DeleteSetting(AutoSettingHandle handle, const std::string& group, const std::string& key);
AUTOSET_API void AutoSetting_DeleteGroup(AutoSettingHandle handle, const std::string& group);

AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value, bool attachDator = false);
AUTOSET_API void AutoSet_SetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator = false);

AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, int& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, double& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, bool& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::string& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<int>& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<double>& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<bool>& value, bool attachDator = false);
AUTOSET_API void AutoSet_GetSetting(AutoSettingHandle handle, const std::string& group, const std::string& key, std::vector<std::string>& value, bool attachDator = false);



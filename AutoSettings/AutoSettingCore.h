#pragma once 

typedef void* AutoSettingHandle;
typedef int AutoSettingMode;

#define AS_MODE_ALL    (-1)
#define AS_MODE_DATORED (1)
#define AS_MODE_LOADED  (2)
#define AS_MODE_ADDED   (4)
#define AS_MODE_UPDATE  (8)

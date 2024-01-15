#pragma once 

typedef void* AutoSettingHandle;
typedef int AutoSettingMode;

#define AS_MODE_ALL    (-1)
#define AS_MODE_DATORED (1)
#define AS_MODE_LOADED  (2)
#define AS_MODE_ADDED   (4)
#define AS_MODE_UPDATE  (8)

#define AS_TYPE_INT (0)
#define AS_TYPE_DOUBLE (1)
#define AS_TYPE_BOOL (2)
#define AS_TYPE_STRING (3)
#define AS_TYPE_VECTOR_INT (4)
#define AS_TYPE_VECTOR_DOUBLE (5)
#define AS_TYPE_VECTOR_BOOL (6)
#define AS_TYPE_VECTOR_STRING (7)

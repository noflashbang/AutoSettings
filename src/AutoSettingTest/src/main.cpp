
#include <AutoSettingApi.h>

int main()
{
	AutoSettingHandle handle = AutoSet_Create(".\\test.ini");
	AutoSet_Destroy(handle);
	return 0;
}

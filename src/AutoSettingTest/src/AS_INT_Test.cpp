#include <AutoSettingApi.h>
#include <catch2/catch_test_macros.hpp>

SCENARIO("int type settings can be gotten and set", "[AUTOSET_INT]")
{

	GIVEN("A simple INI with integer based settings")
	{
		AutoSettingHandle hSettings = 0;
		std::string ini = R"(
			[group1]
			key1 = 1
			key2 = 2
			key3 = 3
			key4 = 4
			key5 = 5
			)";
		hSettings = AutoSet_Create(ini);

		int value1 = 0;
		int value2 = 0;
		int value3 = 0;
		int value4 = 0;
		int value5 = 0;

		WHEN("the settings are retrieved")
		{
			AutoSet_GetSetting(hSettings, "group1", "key1", value1);
			AutoSet_GetSetting(hSettings, "group1", "key2", value2);
			AutoSet_GetSetting(hSettings, "group1", "key3", value3);
			AutoSet_GetSetting(hSettings, "group1", "key4", value4);
			AutoSet_GetSetting(hSettings, "group1", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(value1 == 1);
				REQUIRE(value2 == 2);
				REQUIRE(value3 == 3);
				REQUIRE(value4 == 4);
				REQUIRE(value5 == 5);
			}
		}

		WHEN("the settings are set")
		{
			value1 = 10;
			value2 = 20;
			value3 = 30;
			value4 = 40;
			value5 = 50;

			AutoSet_SetSetting(hSettings, "group1", "key1", value1);
			AutoSet_SetSetting(hSettings, "group1", "key2", value2);
			AutoSet_SetSetting(hSettings, "group1", "key3", value3);
			AutoSet_SetSetting(hSettings, "group1", "key4", value4);
			AutoSet_SetSetting(hSettings, "group1", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(value1 == 10);
				REQUIRE(value2 == 20);
				REQUIRE(value3 == 30);
				REQUIRE(value4 == 40);
				REQUIRE(value5 == 50);
			}
			AND_THEN("the ini is correct")
			{
				std::string ini = AutoSet_GetIniContents(hSettings, AS_MODE_ALL);
				std::string expected =
					R"([GROUP1]
KEY1=10
KEY2=20
KEY3=30
KEY4=40
KEY5=50
)";
				REQUIRE(ini == expected);
			}
		}

		WHEN("the settings are set and retrieved")
		{
			value1 = 95;
			value2 = 96;
			value3 = 97;
			value4 = 98;
			value5 = 99;

			AutoSet_SetSetting(hSettings, "group1", "key1", value1);
			AutoSet_SetSetting(hSettings, "group1", "key2", value2);
			AutoSet_SetSetting(hSettings, "group1", "key3", value3);
			AutoSet_SetSetting(hSettings, "group1", "key4", value4);
			AutoSet_SetSetting(hSettings, "group1", "key5", value5);

			AutoSet_GetSetting(hSettings, "group1", "key1", value1);
			AutoSet_GetSetting(hSettings, "group1", "key2", value2);
			AutoSet_GetSetting(hSettings, "group1", "key3", value3);
			AutoSet_GetSetting(hSettings, "group1", "key4", value4);
			AutoSet_GetSetting(hSettings, "group1", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(value1 == 95);
				REQUIRE(value2 == 96);
				REQUIRE(value3 == 97);
				REQUIRE(value4 == 98);
				REQUIRE(value5 == 99);
			}
		}

		WHEN("the settings are datored values update as expected")
		{
			value1 = 15;
			value2 = 25;
			value3 = 35;
			value4 = 45;
			value5 = 55;

			AutoSet_SetSetting(hSettings, "group1", "key1", value1, true);
			AutoSet_SetSetting(hSettings, "group1", "key2", value2, true);
			AutoSet_SetSetting(hSettings, "group1", "key3", value3, true);
			AutoSet_SetSetting(hSettings, "group1", "key4", value4, true);
			AutoSet_SetSetting(hSettings, "group1", "key5", value5, true);

			value2 = 99;

			AutoSet_GetSetting(hSettings, "group1", "key1", value1);
			AutoSet_GetSetting(hSettings, "group1", "key2", value2);
			AutoSet_GetSetting(hSettings, "group1", "key3", value3);
			AutoSet_GetSetting(hSettings, "group1", "key4", value4);
			AutoSet_GetSetting(hSettings, "group1", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(value1 == 15);
				REQUIRE(value2 == 99);
				REQUIRE(value3 == 35);
				REQUIRE(value4 == 45);
				REQUIRE(value5 == 55);
			}
			AND_THEN("the datored ini is correct")
			{
				std::string ini = AutoSet_GetIniContents(hSettings, AS_MODE_ALL);
				std::string expected =
					R"([GROUP1]
KEY1=15
KEY2=99
KEY3=35
KEY4=45
KEY5=55
)";
				REQUIRE(ini == expected);
			}
		}

		WHEN("the settings are datored other values update as expected")
		{
			value1 = 15;
			value2 = 25;
			value3 = 35;
			value4 = 45;
			value5 = 55;

			int valueother1 = 0;
			int valueother2 = 0;
			int valueother3 = 0;
			int valueother4 = 0;
			int valueother5 = 0;

			AutoSet_SetSetting(hSettings, "group1", "key1", value1, true);
			AutoSet_SetSetting(hSettings, "group1", "key2", value2, true);
			AutoSet_SetSetting(hSettings, "group1", "key3", value3, true);
			AutoSet_SetSetting(hSettings, "group1", "key4", value4, true);
			AutoSet_SetSetting(hSettings, "group1", "key5", value5, true);

			value1 = 99;
			value2 = 98;
			value3 = 97;
			value4 = 96;
			value5 = 95;

			AutoSet_GetSetting(hSettings, "group1", "key1", valueother1);
			AutoSet_GetSetting(hSettings, "group1", "key2", valueother2);
			AutoSet_GetSetting(hSettings, "group1", "key3", valueother3);
			AutoSet_GetSetting(hSettings, "group1", "key4", valueother4);
			AutoSet_GetSetting(hSettings, "group1", "key5", valueother5);

			THEN("the values are correct")
			{
				REQUIRE(valueother1 == 99);
				REQUIRE(valueother2 == 98);
				REQUIRE(valueother3 == 97);
				REQUIRE(valueother4 == 96);
				REQUIRE(valueother5 == 95);
			}
		}
	}
}
#include <AutoSettingApi.h>
#include <catch2/catch_test_macros.hpp>

SCENARIO("double type settings can be gotten and set", "[AUTOSET_DOUBLE]")
{

	GIVEN("A simple INI with double based settings")
	{
		AutoSettingHandle hSettings = 0;
		std::string ini = R"(
			[group2]
			key1 = 1.0
			key2 = 2.5
			key3 = 3.8
			key4 = 4.3
			key5 = 5.2
			)";
		hSettings = AutoSet_Create(ini);

		double value1 = 0L;
		double value2 = 0L;
		double value3 = 0L;
		double value4 = 0L;
		double value5 = 0L;

		WHEN("the settings are retrieved")
		{
			AutoSet_GetSetting(hSettings, "group2", "key1", value1);
			AutoSet_GetSetting(hSettings, "group2", "key2", value2);
			AutoSet_GetSetting(hSettings, "group2", "key3", value3);
			AutoSet_GetSetting(hSettings, "group2", "key4", value4);
			AutoSet_GetSetting(hSettings, "group2", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(DBL_EPSILON < abs(value1 - 1.0L));
				REQUIRE(DBL_EPSILON < abs(value2 - 2.5L));
				REQUIRE(DBL_EPSILON < abs(value3 - 3.8L));
				REQUIRE(DBL_EPSILON < abs(value4 - 4.3L));
				REQUIRE(DBL_EPSILON < abs(value5 - 5.5L));
			}
		}

		WHEN("the settings are set")
		{
			value1 = 10.5f;
			value2 = 20.7f;
			value3 = 30.9f;
			value4 = 40.2f;
			value5 = 50.5f;

			AutoSet_SetSetting(hSettings, "group2", "key1", value1);
			AutoSet_SetSetting(hSettings, "group2", "key2", value2);
			AutoSet_SetSetting(hSettings, "group2", "key3", value3);
			AutoSet_SetSetting(hSettings, "group2", "key4", value4);
			AutoSet_SetSetting(hSettings, "group2", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(DBL_EPSILON < abs(value1 - 10.5L));
				REQUIRE(DBL_EPSILON < abs(value2 - 20.7L));
				REQUIRE(DBL_EPSILON < abs(value3 - 30.9L));
				REQUIRE(DBL_EPSILON < abs(value4 - 40.2L));
				REQUIRE(DBL_EPSILON < abs(value5 - 50.5L));
			}
			AND_THEN("the ini is correct")
			{
				std::string ini = AutoSet_GetIniContents(hSettings, AS_MODE_ALL);
				std::string expected =
					R"([GROUP2]
KEY1=10.5
KEY2=20.7
KEY3=30.9
KEY4=40.2
KEY5=50.5
)";
				REQUIRE(ini == expected);
			}
		}

		WHEN("the settings are set and retrieved")
		{
			value1 = 95.5L;
			value2 = 96.5L;
			value3 = 97.5L;
			value4 = 98.5L;
			value5 = 99.5L;

			AutoSet_SetSetting(hSettings, "group2", "key1", value1);
			AutoSet_SetSetting(hSettings, "group2", "key2", value2);
			AutoSet_SetSetting(hSettings, "group2", "key3", value3);
			AutoSet_SetSetting(hSettings, "group2", "key4", value4);
			AutoSet_SetSetting(hSettings, "group2", "key5", value5);

			AutoSet_GetSetting(hSettings, "group2", "key1", value1);
			AutoSet_GetSetting(hSettings, "group2", "key2", value2);
			AutoSet_GetSetting(hSettings, "group2", "key3", value3);
			AutoSet_GetSetting(hSettings, "group2", "key4", value4);
			AutoSet_GetSetting(hSettings, "group2", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(DBL_EPSILON < abs(value1 - 95.5L));
				REQUIRE(DBL_EPSILON < abs(value2 - 96.5L));
				REQUIRE(DBL_EPSILON < abs(value3 - 97.5L));
				REQUIRE(DBL_EPSILON < abs(value4 - 98.5L));
				REQUIRE(DBL_EPSILON < abs(value5 - 99.5L));
			}
		}

		WHEN("the settings are datored values update as expected")
		{
			value1 = 15.5L;
			value2 = 25.5L;
			value3 = 35.5L;
			value4 = 45.5L;
			value5 = 55.5L;

			AutoSet_SetSetting(hSettings, "group2", "key1", value1, true);
			AutoSet_SetSetting(hSettings, "group2", "key2", value2, true);
			AutoSet_SetSetting(hSettings, "group2", "key3", value3, true);
			AutoSet_SetSetting(hSettings, "group2", "key4", value4, true);
			AutoSet_SetSetting(hSettings, "group2", "key5", value5, true);

			value2 = 99.5L;

			AutoSet_GetSetting(hSettings, "group2", "key1", value1);
			AutoSet_GetSetting(hSettings, "group2", "key2", value2);
			AutoSet_GetSetting(hSettings, "group2", "key3", value3);
			AutoSet_GetSetting(hSettings, "group2", "key4", value4);
			AutoSet_GetSetting(hSettings, "group2", "key5", value5);

			THEN("the values are correct")
			{
				REQUIRE(DBL_EPSILON < abs(value1 - 15.5L));
				REQUIRE(DBL_EPSILON < abs(value2 - 99.5L));
				REQUIRE(DBL_EPSILON < abs(value3 - 35.5L));
				REQUIRE(DBL_EPSILON < abs(value4 - 45.5L));
				REQUIRE(DBL_EPSILON < abs(value5 - 55.5L));
			}
			AND_THEN("the datored ini is correct")
			{
				std::string ini = AutoSet_GetIniContents(hSettings, AS_MODE_ALL);
				std::string expected =
R"([GROUP1]
KEY1=15.5
KEY2=99.5
KEY3=35.5
KEY4=45.5
KEY5=55.5
)";
				REQUIRE(ini == expected);
			}
		}

		WHEN("the settings are datored other values update as expected")
		{
			value1 = 15.7L;
			value2 = 25.7L;
			value3 = 35.7L;
			value4 = 45.7L;
			value5 = 55.7L;

			double valueother1 = 0L;
			double valueother2 = 0L;
			double valueother3 = 0L;
			double valueother4 = 0L;
			double valueother5 = 0L;

			AutoSet_SetSetting(hSettings, "group2", "key1", value1, true);
			AutoSet_SetSetting(hSettings, "group2", "key2", value2, true);
			AutoSet_SetSetting(hSettings, "group2", "key3", value3, true);
			AutoSet_SetSetting(hSettings, "group2", "key4", value4, true);
			AutoSet_SetSetting(hSettings, "group2", "key5", value5, true);

			value1 = 99.6L;
			value2 = 98.6L;
			value3 = 97.6L;
			value4 = 96.6L;
			value5 = 95.6L;

			AutoSet_GetSetting(hSettings, "group2", "key1", valueother1);
			AutoSet_GetSetting(hSettings, "group2", "key2", valueother2);
			AutoSet_GetSetting(hSettings, "group2", "key3", valueother3);
			AutoSet_GetSetting(hSettings, "group2", "key4", valueother4);
			AutoSet_GetSetting(hSettings, "group2", "key5", valueother5);

			THEN("the values are correct")
			{
				REQUIRE(DBL_EPSILON < abs(valueother1 - 99.6L));
				REQUIRE(DBL_EPSILON < abs(valueother2 - 98.6L));
				REQUIRE(DBL_EPSILON < abs(valueother3 - 97.6L));
				REQUIRE(DBL_EPSILON < abs(valueother4 - 96.6L));
				REQUIRE(DBL_EPSILON < abs(valueother5 - 95.6L));
			}
		}
	}
}
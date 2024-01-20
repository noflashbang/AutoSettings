#include <AutoSettingApi.h>
#include <catch2/catch_test_macros.hpp>

SCENARIO("Verify all setting types can be set and retieved", "[AUTOSET]")
{

	GIVEN("A simple INI with test settings")
	{
		AutoSettingHandle hSettings = 0;
		std::string ini = R"(
			[integers]
			key1=1
			key2=2
			[doubles]
			key1=1.0
			key2=2.5
			[bools]
			key1=true
			key2=false
			[strings]
			key1=one
			key2=two
			[vectors]
			key1=1,2,3,4,5
			key2=1.2,2.3,3.4,4.5,5.6
			key3=TRUE,FALSE,TRUE,FALSE,TRUE
			key4=one,two,three,four,five
			)";
		hSettings = AutoSetting_Create(ini);

		int ival1 = 0;
		int ival2 = 0;
		double dval1 = 0L;
		double dval2 = 0L;
		bool bval1 = false;
		bool bval2 = false;
		std::string sval1 = "";
		std::string sval2 = "";
		std::vector<int> vival1;
		std::vector<double> vdval1;
		std::vector<bool> vbval1;
		std::vector<std::string> vsval1;

		WHEN("the settings are retrieved")
		{
			auto pDator1 = AutoSetting_CreateDator(hSettings, ival1);
			auto pDator2 = AutoSetting_CreateDator(hSettings, ival2);
			auto pDator3 = AutoSetting_CreateDator(hSettings, dval1);
			auto pDator4 = AutoSetting_CreateDator(hSettings, dval2);
			auto pDator5 = AutoSetting_CreateDator(hSettings, bval1);
			auto pDator6 = AutoSetting_CreateDator(hSettings, bval2);
			auto pDator7 = AutoSetting_CreateDator(hSettings, sval1);
			auto pDator8 = AutoSetting_CreateDator(hSettings, sval2);
			auto pDator9 = AutoSetting_CreateDator(hSettings, vival1);
			auto pDator10 = AutoSetting_CreateDator(hSettings, vdval1);
			auto pDator11 = AutoSetting_CreateDator(hSettings, vbval1);
			auto pDator12 = AutoSetting_CreateDator(hSettings, vsval1);

			AutoSetting_GetSetting(hSettings, "integers", "key1", pDator1);
			AutoSetting_GetSetting(hSettings, "integers", "key2", pDator2);
			AutoSetting_GetSetting(hSettings, "doubles", "key1", pDator3);
			AutoSetting_GetSetting(hSettings, "doubles", "key2", pDator4);
			AutoSetting_GetSetting(hSettings, "bools", "key1", pDator5);
			AutoSetting_GetSetting(hSettings, "bools", "key2", pDator6);
			AutoSetting_GetSetting(hSettings, "strings", "key1", pDator7);
			AutoSetting_GetSetting(hSettings, "strings", "key2", pDator8);
			AutoSetting_GetSetting(hSettings, "vectors", "key1", pDator9);
			AutoSetting_GetSetting(hSettings, "vectors", "key2", pDator10);
			AutoSetting_GetSetting(hSettings, "vectors", "key3", pDator11);
			AutoSetting_GetSetting(hSettings, "vectors", "key4", pDator12);

			THEN("the values are correct")
			{
				REQUIRE(ival1 == 1);
				REQUIRE(ival2 == 2);
				REQUIRE(DBL_EPSILON >= abs(dval1 - 1.0L));
				REQUIRE(DBL_EPSILON >= abs(dval2 - 2.5L));
				REQUIRE(bval1 == true);
				REQUIRE(bval2 == false);
				REQUIRE(sval1 == "one");
				REQUIRE(sval2 == "two");
				REQUIRE(vival1.size() == 5);
				REQUIRE(vival1[0] == 1);
				REQUIRE(vival1[1] == 2);
				REQUIRE(vival1[2] == 3);
				REQUIRE(vival1[3] == 4);
				REQUIRE(vival1[4] == 5);
				REQUIRE(vdval1.size() == 5);
				REQUIRE(DBL_EPSILON >= abs(vdval1[0] - 1.2L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[1] - 2.3L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[2] - 3.4L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[3] - 4.5L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[4] - 5.6L));
				REQUIRE(vbval1.size() == 5);
				REQUIRE(vbval1[0] == true);
				REQUIRE(vbval1[1] == false);
				REQUIRE(vbval1[2] == true);
				REQUIRE(vbval1[3] == false);
				REQUIRE(vbval1[4] == true);
				REQUIRE(vsval1.size() == 5);
				REQUIRE(vsval1[0] == "one");
				REQUIRE(vsval1[1] == "two");
				REQUIRE(vsval1[2] == "three");
				REQUIRE(vsval1[3] == "four");
				REQUIRE(vsval1[4] == "five");
			}
		}
		WHEN("The settings are set and retrieved they are correct")
		{
			ival1 = 10;
			ival2 = 20;
			dval1 = 99.6L;
			dval2 = 99.5L;
			bval1 = true;
			bval2 = false;
			sval1 = "ten";
			sval2 = "twenty";
			vival1 = { 10,20,30,40,50 };
			vdval1 = { 10.1,20.2,30.3,40.4,50.5 };
			vbval1 = { true,false,true,false,true };
			vsval1 = { "ten","twenty","thirty","forty","fifty" };

			auto pDator1 = AutoSetting_CreateDator(hSettings, ival1);
			auto pDator2 = AutoSetting_CreateDator(hSettings, ival2);
			auto pDator3 = AutoSetting_CreateDator(hSettings, dval1);
			auto pDator4 = AutoSetting_CreateDator(hSettings, dval2);
			auto pDator5 = AutoSetting_CreateDator(hSettings, bval1);
			auto pDator6 = AutoSetting_CreateDator(hSettings, bval2);
			auto pDator7 = AutoSetting_CreateDator(hSettings, sval1);
			auto pDator8 = AutoSetting_CreateDator(hSettings, sval2);
			auto pDator9 = AutoSetting_CreateDator(hSettings, vival1);
			auto pDator10 = AutoSetting_CreateDator(hSettings, vdval1);
			auto pDator11 = AutoSetting_CreateDator(hSettings, vbval1);
			auto pDator12 = AutoSetting_CreateDator(hSettings, vsval1);

			AutoSetting_GetSetting(hSettings, "integers", "key1", pDator1);
			AutoSetting_GetSetting(hSettings, "integers", "key2", pDator2);
			AutoSetting_GetSetting(hSettings, "doubles", "key1", pDator3);
			AutoSetting_GetSetting(hSettings, "doubles", "key2", pDator4);
			AutoSetting_GetSetting(hSettings, "bools", "key1", pDator5);
			AutoSetting_GetSetting(hSettings, "bools", "key2", pDator6);
			AutoSetting_GetSetting(hSettings, "strings", "key1", pDator7);
			AutoSetting_GetSetting(hSettings, "strings", "key2", pDator8);
			AutoSetting_GetSetting(hSettings, "vectors", "key1", pDator9);
			AutoSetting_GetSetting(hSettings, "vectors", "key2", pDator10);
			AutoSetting_GetSetting(hSettings, "vectors", "key3", pDator11);
			AutoSetting_GetSetting(hSettings, "vectors", "key4", pDator12);

			AutoSetting_GetSetting(hSettings, "integers", "key1", pDator1);
			AutoSetting_GetSetting(hSettings, "integers", "key2", pDator2);
			AutoSetting_GetSetting(hSettings, "doubles", "key1", pDator3);
			AutoSetting_GetSetting(hSettings, "doubles", "key2", pDator4);
			AutoSetting_GetSetting(hSettings, "bools", "key1", pDator5);
			AutoSetting_GetSetting(hSettings, "bools", "key2", pDator6);
			AutoSetting_GetSetting(hSettings, "strings", "key1", pDator7);
			AutoSetting_GetSetting(hSettings, "strings", "key2", pDator8);
			AutoSetting_GetSetting(hSettings, "vectors", "key1", pDator9);
			AutoSetting_GetSetting(hSettings, "vectors", "key2", pDator10);
			AutoSetting_GetSetting(hSettings, "vectors", "key3", pDator11);
			AutoSetting_GetSetting(hSettings, "vectors", "key4", pDator12);

			THEN("the values are correct")
			{
				REQUIRE(ival1 == 10);
				REQUIRE(ival2 == 20);
				REQUIRE(DBL_EPSILON >= abs(dval1 - 99.6L));
				REQUIRE(DBL_EPSILON >= abs(dval2 - 99.5L));
				REQUIRE(bval1 == true);
				REQUIRE(bval2 == false);
				REQUIRE(sval1 == "ten");
				REQUIRE(sval2 == "twenty");
				REQUIRE(vival1.size() == 5);
				REQUIRE(vival1[0] == 10);
				REQUIRE(vival1[1] == 20);
				REQUIRE(vival1[2] == 30);
				REQUIRE(vival1[3] == 40);
				REQUIRE(vival1[4] == 50);
				REQUIRE(vdval1.size() == 5);
				REQUIRE(DBL_EPSILON >= abs(vdval1[0] - 10.1L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[1] - 20.2L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[2] - 30.3L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[3] - 40.4L));
				REQUIRE(DBL_EPSILON >= abs(vdval1[4] - 50.5L));
				REQUIRE(vbval1.size() == 5);
				REQUIRE(vbval1[0] == true);
				REQUIRE(vbval1[1] == false);
				REQUIRE(vbval1[2] == true);
				REQUIRE(vbval1[3] == false);
				REQUIRE(vbval1[4] == true);
				REQUIRE(vsval1.size() == 5);
				REQUIRE(vsval1[0] == "ten");
				REQUIRE(vsval1[1] == "twenty");
				REQUIRE(vsval1[2] == "thirty");
				REQUIRE(vsval1[3] == "forty");
				REQUIRE(vsval1[4] == "fifty");
			}
		}
	}
}
		
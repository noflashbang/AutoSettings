
#include "SerialIn.h"
#include "SerialOut.h"
#include "Dator.h"
#include "AutoSetting.h"

int main()
{
	AutoSetting as;

	//as.LoadSettings(".\\test.ini");

	bool val = true;
	std::vector<bool> valarray = { true, false, false, true, true };
	
	int val3 = 2345;
	std::vector<int> val3array = { 1, 2, 3, 4, 5 };
	
	double val4 = 72.8;
	std::vector<double> val4array = { 12.3, 4.56, 6.78, 9.12, 3.45 };
	
	std::string val5 = "test string";
	std::vector <std::string> val5array = { "test", "string", "is", "cool", "wooh" };

	as.SetSettingDirect("NEW", "val", val);
	as.SetSettingDirect("NEW", "valarray", valarray);
	
	as.SetSettingDirect("NEW", "val3", val3);
	as.SetSettingDirect("NEW", "val3array", val3array);
	
	as.SetSettingDirect("NEW", "val4", val4);
	as.SetSettingDirect("NEW", "val4array", val4array);
	
	as.SetSettingDirect("NEW", "val5", val5);
	as.SetSettingDirect("NEW", "val5array", val5array);


	bool gval = false;
	std::vector<bool> gvalarray = { false, false, false, false, false };

	int gval3 = 1;
	std::vector<int> gval3array = { 1, 1, 1, 1, 1 };

	double gval4 = 1;
	std::vector<double> gval4array = { 1, 1, 1, 1, 1 };

	std::string gval5 = "1";
	std::vector<std::string> gval5array = { "1", "1", "1", "1", "1" };

	as.GetSettingDirect("NEW", "val", gval);
	as.GetSettingDirect("NEW", "val3", gval3);
	as.GetSettingDirect("NEW", "val4", gval4);
	as.GetSettingDirect("NEW", "val5", gval5);
	as.GetSettingDirect("NEW", "valarray", gvalarray);
	as.GetSettingDirect("NEW", "val3array", gval3array);
	as.GetSettingDirect("NEW", "val4array", gval4array);
	as.GetSettingDirect("NEW", "val5array", gval5array);

	as.SetSettingDirect("NEW", "val", gval);
	as.SetSettingDirect("NEW", "valarray", gvalarray);

	as.SetSettingDirect("NEW", "val3", gval3);
	as.SetSettingDirect("NEW", "val3array", gval3array);

	as.SetSettingDirect("NEW", "val4", gval4);
	as.SetSettingDirect("NEW", "val4array", gval4array);

	as.SetSettingDirect("NEW", "val5", gval5);
	as.SetSettingDirect("NEW", "val5array", gval5array);

	bool test = false;
	Dator<bool> datortest(test);
	as.GetSetting("AUTO", "bool", &datortest);

	int test1 = 8;
	Dator<int> datortest1(test1);
	as.GetSetting("AUTO", "short", &datortest1);

	int test2 = 500;
	Dator<int> datortest2(test2);
	as.GetSetting("AUTO", "long", &datortest2);

	double test3 = 8.0f;
	Dator<double> datortest3(test3);
	as.GetSetting("AUTO", "float", &datortest3);

	std::string test4 = "THIS IS A TEST";
	Dator<std::string> datortest4(test4);
	as.GetSetting("AUTO", "string", &datortest4);

	test = true;
	test1 = 545;
	test2 = 56446;
	test3 = 48.2025f;
	test4 = "WHAT?!";

	as.SaveSettings(".\\test2.ini");
	
	AutoSetting as2;
	as2.LoadSettings(".\\test3.ini");

	return 0;
}


#include "SerialIn.h"
#include "SerialOut.h"
#include "Dator.h"
#include "AutoSetting.h"

int main()
{
	AutoSetting as;

	//as.LoadSettings(".\\test.ini");

	bool val = true;
	bool valarray[] = { true, false, false, true, true };

	char val2 = 'c';
	char val2array[] = { 'c', 'a', 'a', 't', 't' };
	
	int val3 = 2345;
	int val3array[] = { 1, 2, 3, 4, 5 };
	
	double val4 = 72.8;
	double val4array[] = { 12.3, 4.56, 6.78, 9.12, 3.45 };
	
	std::string val5 = "test string";
	std::string val5array[] = { "test", "string", "is", "cool", "wooh" };

	as.SetSettingDirect("NEW", "val", val);
	as.SetSettingDirectArray("NEW", "valarray", valarray, 5);

	as.SetSettingDirect("NEW", "val2", val2);
	as.SetSettingDirectArray("NEW", "val2array", val2array, 5);
	
	as.SetSettingDirect("NEW", "val3", val3);
	as.SetSettingDirectArray("NEW", "val3array", val3array, 5);
	
	as.SetSettingDirect("NEW", "val4", val4);
	as.SetSettingDirectArray("NEW", "val4array", val4array, 5);
	
	as.SetSettingDirect("NEW", "val5", val5);
	as.SetSettingDirectArray("NEW", "val5array", val5array, 5);


	bool gval = false;
	bool gvalarray[] = { false, false, false, false, false };

	char gval2 = '1';
	char gval2array[] = { '1', '1', '1', '1', '1' };

	int gval3 = 1;
	int gval3array[] = { 1, 1, 1, 1, 1 };

	double gval4 = 1;
	double gval4array[] = { 1, 1, 1, 1, 1 };

	std::string gval5 = "1";
	std::string gval5array[] = { "1", "1", "1", "1", "1" };

	as.GetSettingDirect("NEW", "val", gval);
	as.GetSettingDirect("NEW", "val2", gval2);
	as.GetSettingDirect("NEW", "val3", gval3);
	as.GetSettingDirect("NEW", "val4", gval4);
	as.GetSettingDirect("NEW", "val5", gval5);
	as.GetSettingDirectArray("NEW", "valarray", gvalarray, 5);
	as.GetSettingDirectArray("NEW", "val2array", gval2array, 5);
	as.GetSettingDirectArray("NEW", "val3array", gval3array, 5);
	as.GetSettingDirectArray("NEW", "val4array", gval4array, 5);
	as.GetSettingDirectArray("NEW", "val5array", gval5array, 5);

	as.SetSettingDirect("NEW", "val", gval);
	as.SetSettingDirectArray("NEW", "valarray", gvalarray, 5);

	as.SetSettingDirect("NEW", "val2", gval2);
	as.SetSettingDirectArray("NEW", "val2array", gval2array, 5);

	as.SetSettingDirect("NEW", "val3", gval3);
	as.SetSettingDirectArray("NEW", "val3array", gval3array, 5);

	as.SetSettingDirect("NEW", "val4", gval4);
	as.SetSettingDirectArray("NEW", "val4array", gval4array, 5);

	as.SetSettingDirect("NEW", "val5", gval5);
	as.SetSettingDirectArray("NEW", "val5array", gval5array, 5);

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

	bool ggval = false;
	bool ggvalarray[] = { false, false, false, false, false };

	char ggval2 = '1';
	char ggval2array[] = { '1', '1', '1', '1', '1' };

	int ggval3 = 1;
	int ggval3array[] = { 1, 1, 1, 1, 1 };

	double ggval4 = 1;
	double ggval4array[] = { 1, 1, 1, 1, 1 };

	std::string ggval5 = "1";
	std::string ggval5array[] = { "1", "1", "1", "1", "1" };

	as2.GetSettingDirect("NEW", "val", ggval);
	as2.GetSettingDirect("NEW", "val2", ggval2);
	as2.GetSettingDirect("NEW", "val3", ggval3);
	as2.GetSettingDirect("NEW", "val4", ggval4);
	as2.GetSettingDirect("NEW", "val5", ggval5);
	as2.GetSettingDirectArray("NEW", "valarray", ggvalarray, 5);
	as2.GetSettingDirectArray("NEW", "val2array", ggval2array, 5);
	as2.GetSettingDirectArray("NEW", "val3array", ggval3array, 5);
	as2.GetSettingDirectArray("NEW", "val4array", ggval4array, 5);
	as2.GetSettingDirectArray("NEW", "val5array", ggval5array, 5);



	return 0;
}

#include <iostream>
#include "LunarSolarConverter.h"
using namespace std;

int main(void){
	Solar sol = {24, 11, 2015 };
	Lunar lun = SolarToLunar(sol);
	cout << sol.solarYear << " " << sol.solarMonth << " " << sol.solarDay << endl;
	cout << lun.lunarYear << " " << lun.lunarMonth << " " << lun.lunarDay << endl;
}
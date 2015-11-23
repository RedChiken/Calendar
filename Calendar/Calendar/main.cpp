#include <iostream>
#include "LuniSolar.h"

using namespace std;

int main(void){
	LuniSolar temp(2015, 11, 23);
	cout << temp.getLunarYear() << "/" << temp.getLunarMonth() << "/" << temp.getLunarDay() << endl;
	
}
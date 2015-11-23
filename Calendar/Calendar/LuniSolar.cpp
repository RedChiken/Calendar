#include "LuniSolar.h"

//using namespace Region;

LuniSolar::LuniSolar(){

}
LuniSolar::LuniSolar(int yaer, int month, int day){
	temp = NULL;
	CoInitialize(NULL);
	hr = CoCreateInstance(CLSID_ConvertTo, NULL, CLSCTX_INPROC_SERVER, IID_Region, reinterpret_cast<void **>(&temp));
	m_issucceeded = SUCCEEDED(hr);
	std::cout << temp->koreanLunisolar(year, month, day) << std::endl;
	if (m_issucceeded){
		ParseDate(temp->koreanLunisolar(year, month, day));
	}
	
}
LuniSolar::LuniSolar(const LuniSolar &lst){
	//how to make it?

}
LuniSolar::~LuniSolar(){
	CoUninitialize();
}
void LuniSolar::ParseDate(int input){
	this->day = input % 100;
	this->month = (input % 10000) / 100;
	this->year = input / 10000;
}
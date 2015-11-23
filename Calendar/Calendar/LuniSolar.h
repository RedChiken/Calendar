#include <iostream>
#include <Windows.h>
#import "ConsoleApplication1.tlb" no_namespace named_guids

//struct Region;

class LuniSolar{
public:
	LuniSolar();
	LuniSolar(int year, int month, int day);
	LuniSolar(const LuniSolar &lst);
	virtual ~LuniSolar();
	inline int getLunarYear(){
		return this->year;
	};
	inline int getLunarMonth(){
		return this->month;
	};
	int getLunarDay(){
		return this->day;
	};
private:
	void ParseDate(int input);
	bool m_issucceeded;
	int year, month, day;
	Region *temp;
	HRESULT hr;
};
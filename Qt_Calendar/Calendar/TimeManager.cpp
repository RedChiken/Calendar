#include "TimeManager.h"
#include <sstream>
#include <iomanip>
//#pragma warning(disable:4996)

//default constructor
TimeManager::TimeManager()
{
	//initializing solar variables
	this->solarDate.solarDay = 0;
	this->solarDate.solarMonth = 0;
	this->solarDate.solarYear = 0;
	//initializing lunar variables
	this->lunarDate.lunarDay = 0;
	this->lunarDate.lunarMonth = 0;
	this->lunarDate.lunarYear = 0;
	//initializing repeating variables
	this->repeatDay = 0;
	this->repeatWeek = false;
	this->repeatMonth = false;
	this->repeatYear = false;
	//initializing time
	this->hour = 0;
	this->min = 0;
	this->sec = 0.0f;

}

//constructor. input : string
TimeManager::TimeManager(string input) {

	//initializing solar variables
	this->solarDate.solarDay = 0;
	this->solarDate.solarMonth = 0;
	this->solarDate.solarYear = 0;
	//initializing lunar variables
	this->lunarDate.lunarDay = 0;
	this->lunarDate.lunarMonth = 0;
	this->lunarDate.lunarYear = 0;
	//initializing repeating variables
	this->repeatDay = 0;
	this->repeatWeek = false;
	this->repeatMonth = false;
	this->repeatYear = false;
	//initializing time
	this->hour = 0;
	this->min = 0;
	this->sec = 0.0f;

	if (input.compare("0") == 0) return;

	const char* inputstr = input.c_str();

	//debugging
	//cout << inputstr << endl;

	char year[5] = { 0 }, month[3] = { 0 }, day[3] = { 0 },
		hour[3] = { 0 }, min[3] = { 0 }, sec[3] = { 0 };
	memcpy(year, inputstr, 4);
	memcpy(month, inputstr + 4, 2);
	memcpy(day, inputstr + 6, 2);
	memcpy(hour, inputstr + 8, 2);
	memcpy(min, inputstr + 10, 2);
	memcpy(sec, inputstr + 12, 2);

	this->solarDate.solarYear = atoi(year);
	this->solarDate.solarMonth = atoi(month);
	this->solarDate.solarDay = atoi(day);
	this->hour = atoi(hour);
	this->min = atoi(min);
	this->sec = atof(sec);
	//initializing repeating variables
	this->repeatDay = 0;
	this->repeatWeek = false;
	this->repeatMonth = false;
	this->repeatYear = false;
}

/*
* constructor.
* default parameter is zero, for time variable and true, for boolean variable isSolar.
*/
TimeManager::TimeManager(int year, int month, int day, int hour, int min, double sec, bool isSolar) {
	this->solarDate.solarYear = year;
	this->solarDate.solarMonth = month;
	this->solarDate.solarDay = day;
	this->hour = hour;
	this->min = min;
	this->sec = sec;
	//initializing repeating variables
	this->repeatDay = 0;
	this->repeatWeek = false;
	this->repeatMonth = false;
	this->repeatYear = false;
}

//copy constructor
TimeManager::TimeManager(const TimeManager& ttm) {

	//copy solar values
	this->solarDate.solarYear = ttm.solarDate.solarYear;
	this->solarDate.solarMonth = ttm.solarDate.solarMonth;
	this->solarDate.solarDay = ttm.solarDate.solarDay;
	//copy lunar values
	this->lunarDate.lunarYear = ttm.lunarDate.lunarYear;
	this->lunarDate.lunarMonth = ttm.lunarDate.lunarMonth;
	this->lunarDate.lunarDay = ttm.lunarDate.lunarDay;
	//copy time values
	this->hour = ttm.hour;
	this->min = ttm.min;
	this->sec = ttm.sec;
	//copy repeating values
	this->repeatDay = ttm.repeatDay;
	this->repeatMonth = ttm.repeatMonth;
	this->repeatYear = ttm.repeatYear;
	this->repeatWeek = ttm.repeatWeek;
}

//deconstructor
TimeManager::~TimeManager() {

}

/*setter for date.
* default parameter : bool isSolar = true
* if isSolar is true, set solarDate. If not, set lunarDate.
*/
void TimeManager::setDate(int year, int month, int day, bool isSolar) {
	if (isSolar) {
		this->solarDate.solarYear = year;
		this->solarDate.solarMonth = month;
		this->solarDate.solarDay = day;
	}
	else {
		this->lunarDate.lunarYear = year;
		this->lunarDate.lunarMonth = month;
		this->lunarDate.lunarDay = day;
	}
}

//setter for time
void TimeManager::setTime(int hour, int min, double sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

//setter for repeat
void TimeManager::setRepeatDate(bool year, bool month, bool week, int day) {
	this->repeatYear = year;
	this->repeatMonth = month;
	this->repeatDay = day;
	this->repeatWeek = week;
}
/*
* converts member variables to string
* if isSolar is true, convert solarDate and time variables.
* if isSolar is false, convert lunarDate and time variables.
* format : YearMonthDayHourMinuteSecond ( without spaces )
* each values should be represented in
* 4, 2, 2, 2, 2, 2 digits( total : 14 digits )
* Therefore, if month is January, it is represented as 01, not 1.
* ex. 2015. 11. 28. pm. 5 10 -> 20151128171000
*/
string TimeManager::toString(bool isSolar) {
	int year, month, day;
	if (isSolar) {
		year = this->solarDate.solarYear;
		month = this->solarDate.solarMonth;
		day = this->solarDate.solarDay;
	}
	else {
		year = this->lunarDate.lunarYear;
		month = this->lunarDate.lunarMonth;
		day = this->lunarDate.lunarDay;
	}
	stringstream ss;
	ss << year << setw(2) << setfill('0') << month
		<< setw(2) << setfill('0') << day <<
		setw(2) << setfill('0') << hour << setw(2)
		<< setfill('0') << min
		<< setw(2) << setfill('0') << sec;
	//stringstram str(): current stringstream 이 저장하고 있는 문자열의 복사본을 반환 
	return ss.str();
}

//global function for lunar solar conversion
int GetBitInt(int data, int length, int shift) {
	return (data & (((1 << length) - 1) << shift)) >> shift;
}

//convert member variable lunarDate to solar date
void TimeManager::toSolar() {
	this->solarDate = LunarToSolar(this->lunarDate);
}

//convert lunar date to solar date.
void TimeManager::toSolar(int year, int month, int day) {
	Lunar templunar = { false, year, month, day };
	this->solarDate = LunarToSolar(templunar);
}

//convert member variable solarDate to lunar date
void TimeManager::toLunar() {
	this->lunarDate = SolarToLunar(this->solarDate);
}

//convert solar date to lunar date.
void TimeManager::toLunar(int year, int month, int day) {
	Solar tempsolar = { year, month, day };
	this->lunarDate = SolarToLunar(tempsolar);
}

long SolarToInt(int y, int m, int d) {
	m = (m + 9) % 12;
	y = y - m / 10;
	return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

Solar SolarFromInt(long g) {
	long y = (10000 * g + 14780) / 3652425;
	long ddd = g - (365 * y + y / 4 - y / 100 + y / 400);
	if (ddd < 0) {
		y--;
		ddd = g - (365 * y + y / 4 - y / 100 + y / 400);
	}
	long mi = (100 * ddd + 52) / 3060;
	long mm = (mi + 2) % 12 + 1;
	y = y + (mi + 2) / 12;
	long dd = ddd - (mi * 306 + 5) / 10 + 1;
	Solar solar = {
		solar.solarYear = (int)y,
		solar.solarMonth = (int)mm,
		solar.solarDay = (int)dd,
	};
	return solar;
}

Solar LunarToSolar(Lunar lunar) {
	int days = lunar_month_days[lunar.lunarYear - lunar_month_days[0]];
	int leap = GetBitInt(days, 4, 13);
	int offset = 0;
	int loopend = leap;
	if (!lunar.isleap) {
		if (lunar.lunarMonth <= leap || leap == 0) {
			loopend = lunar.lunarMonth - 1;
		}
		else {
			loopend = lunar.lunarMonth;
		}
	}
	for (int i = 0; i < loopend; i++) {
		offset += GetBitInt(days, 1, 12 - i) == 1 ? 30 : 29;
	}
	offset += lunar.lunarDay;

	int solar11 = solar_1_1[lunar.lunarYear - solar_1_1[0]];

	int y = GetBitInt(solar11, 12, 9);
	int m = GetBitInt(solar11, 4, 5);
	int d = GetBitInt(solar11, 5, 0);

	return SolarFromInt(SolarToInt(y, m, d) + offset - 1);
}

Lunar SolarToLunar(Solar solar) {
	Lunar lunar;
	int index = solar.solarYear - solar_1_1[0];
	int data = (solar.solarYear << 9) | (solar.solarMonth << 5) | (solar.solarDay);
	int solar11 = 0;
	if (solar_1_1[index] > data) {
		index--;
	}
	solar11 = solar_1_1[index];
	int y = GetBitInt(solar11, 12, 9);
	int m = GetBitInt(solar11, 4, 5);
	int d = GetBitInt(solar11, 5, 0);
	long offset = SolarToInt(solar.solarYear, solar.solarMonth, solar.solarDay) - SolarToInt(y, m, d);

	int days = lunar_month_days[index];
	int leap = GetBitInt(days, 4, 13);

	int lunarY = index + solar_1_1[0];
	int lunarM = 1;
	int lunarD;
	offset += 1;

	for (int i = 0; i < 13; i++) {
		int dm = GetBitInt(days, 1, 12 - i) == 1 ? 30 : 29;
		if (offset > dm) {
			lunarM++;
			offset -= dm;
		}
		else {
			break;
		}
	}
	lunarD = (int)(offset);
	lunar.lunarYear = lunarY;
	lunar.lunarMonth = lunarM;
	lunar.isleap = false;
	if (leap != 0 && lunarM > leap) {
		lunar.lunarMonth = lunarM - 1;
		if (lunarM == leap + 1) {
			lunar.isleap = true;
		}
	}

	lunar.lunarDay = lunarD;
	return lunar;
}

int isDays(int month){
	int monthToDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return monthToDays[month];
}

TimeManager& TimeManager::operator=(TimeManager input) {

	this->solarDate = input.solarDate;
	this->lunarDate = input.lunarDate;

	this->hour = input.getHour();
	this->min = input.getMinute();
	this->sec = input.getSecond();

	this->repeatYear = input.repeatYear;
	this->repeatMonth = input.repeatMonth;
	this->repeatWeek = input.repeatWeek;
	this->repeatDay = input.repeatDay;

	return *this;
}

TimeManager& TimeManager::operator+ (TimeManager input) {

	//calculate time
	int hourt = this->hour + input.hour;
	int mint = this->min + input.min;
	double sect = this->sec + input.sec; //TimeManager 부분에서는 double로 선언되어있어서 double로 형변환을 해줌

	//calculate date. Only uses Solar dates
	int solarDayt = this->solarDate.solarDay + input.getSolarDay();
	int solarMontht = this->solarDate.solarMonth + input.getSolarMonth();
	int solarYeart = this->solarDate.solarYear + input.getSolarYear();

	if (sect >= 60) {
	sect -= 60;
	mint++;
	}
	if (mint >= 60) {
	mint -= 60;
	hourt++;
	}
	if (hourt >= 24) {
	hourt -= 24;
	solarDayt++;
	}

	//calculate # of days for given month
	int dayLimit = isDays(this->solarDate.solarMonth);
	if (isLeap(solarYeart)) dayLimit += 1;

	if (solarDayt > dayLimit) {
	solarDayt -= dayLimit;
	solarMontht++;
	}
	if (solarMontht > 12) {
	solarMontht -= 12;
	solarYeart++;
	}

	return TimeManager(solarYeart, solarMontht, solarDayt, hourt, mint, sect);
}

TimeManager& TimeManager::operator+= (TimeManager input) {

	this->hour += input.hour;
	this->min += input.min;
	this->sec += input.sec;
	this->solarDate.solarDay += input.solarDate.solarDay;
	this->solarDate.solarMonth += input.solarDate.solarMonth;
	this->solarDate.solarYear += input.solarDate.solarYear;

	if (this->sec >= 60.0) {
		this->sec -= 60;
		this->min++;
	}
	if (this->min >= 60) {
		this->min -= 60;
		this->hour++;
	}

	if (this->hour >= 24) {
		this->hour -= 24;
		this->solarDate.solarDay++;
	}

	//calculate # of days for given month
	int dayLimit = isDays(this->solarDate.solarMonth);
	if (isLeap(this->solarDate.solarYear)) dayLimit += 1;

	if (this->solarDate.solarDay > dayLimit) {
		this->solarDate.solarDay -= dayLimit;
		this->solarDate.solarMonth++;
	}
	if (this->solarDate.solarMonth > 12) {
		this->solarDate.solarMonth -= 12;
		this->solarDate.solarYear++;
	}

	return *this;
}

bool TimeManager::operator> (TimeManager input) {
	//2015.11.30 09.12.02 vs 2015.11.29 09.12.02
	//2015.11.30 09.12.02 vs 2015.11.30 09.12.22c
	//2014 2015 이면 당연히 
	if (this->solarDate.solarYear > input.getSolarYear()) { return true; }
	else if (this->solarDate.solarYear < input.getSolarYear()) { return false; } //연도 비교

	if (this->solarDate.solarMonth > input.getSolarMonth()) { return true; } //월 비교
	else if (this->solarDate.solarMonth < input.getSolarMonth()) { return false; }

	if (this->solarDate.solarDay > input.getSolarDay()) { return true; } //일 비교
	else if (this->solarDate.solarDay < input.getSolarDay()) { return false; }

	if (this->hour > input.getHour()) { return true; } //일 비교
	else if (this->hour < input.getHour()) { return false; }

	if (this->min > input.getMinute()) { return true; } //일 비교
	else if (this->min < input.getMinute()) { return false; }

	if (this->sec > input.getSecond()) { return true; } //일 비교
	else if (this->sec < input.getSecond()) { return false; }

	return false;
}

bool TimeManager::operator< (TimeManager input) {
	if (operator > (input) || operator==(input)) { return false; }
	else { return true; }
}

bool TimeManager::operator==(TimeManager input) {
	return ((this->hour == input.hour) && (this->min == input.min) && ((int)this->sec == (int)input.sec) && \
		(this->solarDate.solarDay == input.getSolarDay()) && (this->solarDate.solarMonth == input.getSolarMonth()) && \
		(this->solarDate.solarYear == input.getSolarYear()));
}

bool TimeManager::operator!=(TimeManager input) {
	return !(operator==(input));
}

//leap year calculator
bool isLeap(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year%400 == 0) return true;
	else return false;
}

//int TimeManager::isThirtyfirst(int month) {
//	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		return 31; //31일은 31 리턴 
//	else if (month == 4 || month == 6 || month == 9 || month == 11)
//		return 30;
//	else if (month == 2) {
//		if (lunarDate.isleap)
//			return 29;
//		else return 28;
//	}
//}

#include <iostream>
#include <string>

using namespace std;

/*
* this class can calculate about time.
* save times, make it to string, and also can calculate like normal integer.
* LunarSolar convering fucntion and constructor which converts lunar to solar should be included.
*/

//structures
typedef struct Lunar
{
	bool isleap;
	int lunarYear;
	int lunarMonth;
	int lunarDay;
} Lunar;

typedef struct Solar
{
	int solarYear;
	int solarMonth;
	int solarDay;
} Solar;

//global functions
long SolarToInt(int y, int m, int d);
Lunar SolarToLunar(Solar solar);
Solar LunarToSolar(Lunar lunar);
Solar SolarFromInt(long g);
long SolarToInt(int y, int m, int d);

class TimeManager {
public:
	TimeManager();
	TimeManager(int year, int month = 0, int day = 0, int hour = 0, int min = 0, double sec = 0, bool isSolar = true);
	//assume input date is solar date
	TimeManager(string dateTime);	//get string and converts it to Solar date and time
	TimeManager(const TimeManager& ttm); //copy constructor
	virtual ~TimeManager();

	//getters
	inline int getHour() { return this->hour; }
	inline int getMinute() { return this->min; }
	inline double getSecond() { return this->sec; }
	inline int getSolarYear() { return this->solarDate.solarYear; }
	inline int getSolarMonth() { return this->solarDate.solarMonth; }
	inline int getSolarDay() { return this->solarDate.solarDay; }
	inline int getLunarYear() { return this->lunarDate.lunarYear; }
	inline int getLunarMonth() { return this->lunarDate.lunarMonth; }
	inline int getLunarDay() { return this->lunarDate.lunarDay; }
	inline bool getIsLeap() { return this->lunarDate.isleap; }
	//setters
	void setDate(int year, int month, int day, bool isSolar = true);
	void setTime(int hour, int min, int sec);

	inline int isThirtyfirst(int month) { return isDays[month] + (lunarDate.isleap) ? 1 : 0; }

	//int isThirtyfirst(int month) {
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

	string toString(bool isSolar);
	void toSolar();
	void toSolar(int year, int month, int day);
	void toLunar();
	void toLunar(int year, int month, int day);

	//operator overloading
	(TimeManager&) operator+ (TimeManager input) {
		//int preSolarMonth = this->solarDate.solarMonth; //solarDate.solarMonth으로도 해결 가능할듯? 
		//if (getIsLeap()) isDays[2] += 1; //29일로 만들어 준다. //이부분이 좀 걸리긴 함 

		int hourt = this->hour + input.hour;
		int mint = this->min + input.min;
		double sect = this->sec + input.sec; //timemanager 부분에서는 double로 선언되어있어서 double로 형변환을 해줌 

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
		//정확한 input형태를 아직 모르겟음 
		//days판단
		if (solarDayt > isDays[solarDate.solarMonth]) {
			solarDayt -= isDays[solarDate.solarMonth];
			solarMontht++;
		}
		if (solarMontht > 12) {
			solarMontht -= 12;
			solarYeart++;
		}
		//(int year, int month = 0, int day = 0, int hour = 0, int min = 0, double sec = 0, bool isSolar = true)
		return TimeManager(solarYeart, solarMontht, solarDayt, hourt, mint, sect);
	};

	(TimeManager *) operator+=(TimeManager input) {
		this->hour += input.hour;
		this->min += input.min;
		this->sec += input.sec;
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

		if (this->solarDate.solarDay > isDays[solarDate.solarMonth]) {
			this->solarDate.solarDay -= isDays[solarDate.solarMonth];
			this->solarDate.solarMonth++;
		}
		if (this->solarDate.solarMonth > 12) {
			this->solarDate.solarMonth -= 12;
			this->solarDate.solarYear++;
		}

		return this;
	};

	bool operator> (TimeManager input) {
		//2015.11.30 09.12.02 vs 2015.11.29 09.12.02
		//2015.11.30 09.12.02 vs 2015.11.30 09.12.22c
		//2014 2015 이면 당연히 
		if (this->solarDate.solarYear < input.getSolarYear()) { return true; }
		else if (this->solarDate.solarYear > input.getSolarYear()) { return false; } //연도 비교 해야지 이제 ㅠㅠ 
		else {
			//11 vs 12 
			if (this->solarDate.solarMonth < input.getSolarMonth()) { return true; }
			else if (this->solarDate.solarMonth >  input.getSolarMonth()) { return false; }
			else {
				if (this->solarDate.solarDay < input.getSolarDay()) { return true; }
				else if (this->solarDate.solarDay>input.getSolarDay()) { return false; }
				else {
					//이 부에분 좀 걸리긴 한데 모게르음 잘해봐 ^^ 
					if (this->getHour() < input.hour) { return true; }
					else if (this->getHour() > input.hour) { return false; }
					else {
						if (this->getMinute() < input.min) { return true; }
						else if (this->getMinute() > input.min) { return false; }
						else {
							if (this->getSecond() < input.sec) { return true; }
							else if (this->getSecond() > input.sec) { return false; }
							else {
								std::cout << "eror r ";
							}
						}
					}
				}

			}
		}

		return (this);
	};

	bool operator< (TimeManager input) {
		if (operator>(input) || operator==(input)) { return false;	}
		else { return true; }
	};
	
	(TimeManager&) operator=(TimeManager input) {
	
		this->solarDate.solarYear = input.getSolarYear();
		this->solarDate.solarMonth = input.getSolarMonth();
		this->solarDate.solarDay = input.getSolarDay();
		this->hour = input.getHour();
		this->min = input.getMinute();
		this->sec = input.getSecond();
//		this->sec = input.sec;

		return *this;

	}
	

	
	//operator overiding.
	/*
	(TimeManager &) operator+(TimeManager input){
		int hourt = this->hour + input.hour;
		int mint = this->min + input.min;
		int sect = this->sec + input.sec;
		if (sect >= 60.0){
			sect -= 60;
			mint++;
		}
		if (mint >= 60){
			mint -= 60;
			hourt++;
		}
		return TimeManager(hourt, mint, sect);
	};
	(TimeManager &) operator-(TimeManager input){
		int hourt = this->hour - input.hour;
		int mint = this->min - input.min;
		int sect = this->sec - input.sec;
		if (sect < 0){
			sect += 60;
			mint--;
		}
		if (mint < 0){
			mint += 60;
			hourt--;
		}
		if (hourt < 0){
			hourt *= -1;
		}

		return TimeManager(hourt, mint, sect);
	};
	(TimeManager &) operator*(int&& input){
		int temp = 0;
		this->sec *= input;
		this->min *= input;
		this->min += this->sec / 60;
		this->sec = this->sec - (int)this->sec + (int)this->sec % 60;
		this->hour *= input;
		this->hour += this->min / 60;
		this->min = this->min % 60;
	};
	(TimeManager &) operator/(int&& input){
		this->min += (this->hour % input) * 60;
		this->hour /= input;
		this->sec += (this->min % input) * 60;
		this->min /= input;
		this->sec += (this->sec + 0.5) / input;
	};
	(TimeManager *) operator+=(TimeManager input){
		this->hour += input.hour;
		this->min += input.min;
		this->sec += input.sec;
		if (this->sec >= 60.0){
			this->sec -= 60;
			this->min++;
		}
		if (this->min >= 60){
			this->min -= 60;
			this->hour++;
		}
		return this;
	};
	(TimeManager *) operator-=(TimeManager input){
		this->hour -= input.hour;
		this->min -= input.min;
		this->sec -= input.sec;
		if (this->sec < 0){
			this->sec += 60;
			this->min--;
		}
		if (this->min < 0){
			this->min += 60;
			this->hour--;
		}
		return this;
	};
	(TimeManager &) operator*=(int&& input){
		int temp = 0;
		this->sec *= input;
		this->min *= input;
		this->min += this->sec / 60;
		this->sec = this->sec - (int)this->sec + (int)this->sec % 60;
		this->hour *= input;
		this->hour += this->min / 60;
		this->min = this->min % 60;
	};
	(TimeManager &) operator/=(int&& input){
		this->min += (this->hour % input) * 60;
		this->hour /= input;
		this->sec += (this->min % input) * 60;
		this->min /= input;
		this->sec += (this->sec + 0.5) / input;
	};
	*/

	bool operator==(TimeManager input) {
		return (this->hour == input.hour) && (this->min == input.min) && (this->sec == input.sec);
	};


	bool operator!=(TimeManager input) {
		return !(operator==(input));
	};

private:

	Lunar lunarDate;
	Solar solarDate;
	const int isDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int hour;		//	0 ~ 23
	int min;		//	0 ~ 59
	double sec;		//	0 ~ 60.00
};

static int lunar_month_days[] =
{
	1887, 0x1694, 0x16aa, 0x4ad5, 0xab6, 0xc4b7, 0x4ae, 0xa56, 0xb52a,
	0x1d2a, 0xd54, 0x75aa, 0x156a, 0x1096d, 0x95c, 0x14ae, 0xaa4d, 0x1a4c, 0x1b2a, 0x8d55, 0xad4, 0x135a, 0x495d,
	0x95c, 0xd49b, 0x149a, 0x1a4a, 0xbaa5, 0x16a8, 0x1ad4, 0x52da, 0x12b6, 0xe937, 0x92e, 0x1496, 0xb64b, 0xd4a,
	0xda8, 0x95b5, 0x56c, 0x12ae, 0x492f, 0x92e, 0xcc96, 0x1a94, 0x1d4a, 0xada9, 0xb5a, 0x56c, 0x726e, 0x125c,
	0xf92d, 0x192a, 0x1a94, 0xdb4a, 0x16aa, 0xad4, 0x955b, 0x4ba, 0x125a, 0x592b, 0x152a, 0xf695, 0xd94, 0x16aa,
	0xaab5, 0x9b4, 0x14b6, 0x6a57, 0xa56, 0x1152a, 0x1d2a, 0xd54, 0xd5aa, 0x156a, 0x96c, 0x94ae, 0x14ae, 0xa4c,
	0x7d26, 0x1b2a, 0xeb55, 0xad4, 0x12da, 0xa95d, 0x95a, 0x149a, 0x9a4d, 0x1a4a, 0x11aa5, 0x16a8, 0x16d4,
	0xd2da, 0x12b6, 0x936, 0x9497, 0x1496, 0x1564b, 0xd4a, 0xda8, 0xd5b4, 0x156c, 0x12ae, 0xa92f, 0x92e, 0xc96,
	0x6d4a, 0x1d4a, 0x10d65, 0xb58, 0x156c, 0xb26d, 0x125c, 0x192c, 0x9a95, 0x1a94, 0x1b4a, 0x4b55, 0xad4,
	0xf55b, 0x4ba, 0x125a, 0xb92b, 0x152a, 0x1694, 0x96aa, 0x15aa, 0x12ab5, 0x974, 0x14b6, 0xca57, 0xa56, 0x1526,
	0x8e95, 0xd54, 0x15aa, 0x49b5, 0x96c, 0xd4ae, 0x149c, 0x1a4c, 0xbd26, 0x1aa6, 0xb54, 0x6d6a, 0x12da, 0x1695d,
	0x95a, 0x149a, 0xda4b, 0x1a4a, 0x1aa4, 0xbb54, 0x16b4, 0xada, 0x495b, 0x936, 0xf497, 0x1496, 0x154a, 0xb6a5,
	0xda4, 0x15b4, 0x6ab6, 0x126e, 0x1092f, 0x92e, 0xc96, 0xcd4a, 0x1d4a, 0xd64, 0x956c, 0x155c, 0x125c, 0x792e,
	0x192c, 0xfa95, 0x1a94, 0x1b4a, 0xab55, 0xad4, 0x14da, 0x8a5d, 0xa5a, 0x1152b, 0x152a, 0x1694, 0xd6aa,
	0x15aa, 0xab4, 0x94ba, 0x14b6, 0xa56, 0x7527, 0xd26, 0xee53, 0xd54, 0x15aa, 0xa9b5, 0x96c, 0x14ae, 0x8a4e,
	0x1a4c, 0x11d26, 0x1aa4, 0x1b54, 0xcd6a, 0xada, 0x95c, 0x949d, 0x149a, 0x1a2a, 0x5b25, 0x1aa4, 0xfb52,
	0x16b4, 0xaba, 0xa95b, 0x936, 0x1496, 0x9a4b, 0x154a, 0x136a5, 0xda4, 0x15ac
};

static int solar_1_1[] =
{
	1887, 0xec04c, 0xec23f, 0xec435, 0xec649, 0xec83e, 0xeca51, 0xecc46, 0xece3a,
	0xed04d, 0xed242, 0xed436, 0xed64a, 0xed83f, 0xeda53, 0xedc48, 0xede3d, 0xee050, 0xee244, 0xee439, 0xee64d,
	0xee842, 0xeea36, 0xeec4a, 0xeee3e, 0xef052, 0xef246, 0xef43a, 0xef64e, 0xef843, 0xefa37, 0xefc4b, 0xefe41,
	0xf0054, 0xf0248, 0xf043c, 0xf0650, 0xf0845, 0xf0a38, 0xf0c4d, 0xf0e42, 0xf1037, 0xf124a, 0xf143e, 0xf1651,
	0xf1846, 0xf1a3a, 0xf1c4e, 0xf1e44, 0xf2038, 0xf224b, 0xf243f, 0xf2653, 0xf2848, 0xf2a3b, 0xf2c4f, 0xf2e45,
	0xf3039, 0xf324d, 0xf3442, 0xf3636, 0xf384a, 0xf3a3d, 0xf3c51, 0xf3e46, 0xf403b, 0xf424e, 0xf4443, 0xf4638,
	0xf484c, 0xf4a3f, 0xf4c52, 0xf4e48, 0xf503c, 0xf524f, 0xf5445, 0xf5639, 0xf584d, 0xf5a42, 0xf5c35, 0xf5e49,
	0xf603e, 0xf6251, 0xf6446, 0xf663b, 0xf684f, 0xf6a43, 0xf6c37, 0xf6e4b, 0xf703f, 0xf7252, 0xf7447, 0xf763c,
	0xf7850, 0xf7a45, 0xf7c39, 0xf7e4d, 0xf8042, 0xf8254, 0xf8449, 0xf863d, 0xf8851, 0xf8a46, 0xf8c3b, 0xf8e4f,
	0xf9044, 0xf9237, 0xf944a, 0xf963f, 0xf9853, 0xf9a47, 0xf9c3c, 0xf9e50, 0xfa045, 0xfa238, 0xfa44c, 0xfa641,
	0xfa836, 0xfaa49, 0xfac3d, 0xfae52, 0xfb047, 0xfb23a, 0xfb44e, 0xfb643, 0xfb837, 0xfba4a, 0xfbc3f, 0xfbe53,
	0xfc048, 0xfc23c, 0xfc450, 0xfc645, 0xfc839, 0xfca4c, 0xfcc41, 0xfce36, 0xfd04a, 0xfd23d, 0xfd451, 0xfd646,
	0xfd83a, 0xfda4d, 0xfdc43, 0xfde37, 0xfe04b, 0xfe23f, 0xfe453, 0xfe648, 0xfe83c, 0xfea4f, 0xfec44, 0xfee38,
	0xff04c, 0xff241, 0xff436, 0xff64a, 0xff83e, 0xffa51, 0xffc46, 0xffe3a, 0x10004e, 0x100242, 0x100437,
	0x10064b, 0x100841, 0x100a53, 0x100c48, 0x100e3c, 0x10104f, 0x101244, 0x101438, 0x10164c, 0x101842, 0x101a35,
	0x101c49, 0x101e3d, 0x102051, 0x102245, 0x10243a, 0x10264e, 0x102843, 0x102a37, 0x102c4b, 0x102e3f, 0x103053,
	0x103247, 0x10343b, 0x10364f, 0x103845, 0x103a38, 0x103c4c, 0x103e42, 0x104036, 0x104249, 0x10443d, 0x104651,
	0x104846, 0x104a3a, 0x104c4e, 0x104e43, 0x105038, 0x10524a, 0x10543e, 0x105652, 0x105847, 0x105a3b, 0x105c4f,
	0x105e45, 0x106039, 0x10624c, 0x106441, 0x106635, 0x106849, 0x106a3d, 0x106c51, 0x106e47, 0x10703c, 0x10724f,
	0x107444, 0x107638, 0x10784c, 0x107a3f, 0x107c53, 0x107e48
};
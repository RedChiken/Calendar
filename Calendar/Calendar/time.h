#include <iostream>
#include <string>
using namespace std;

/*
this class can calculate about time.
save times, make it to string, and also can calculate like normal integer.
*/
class SaveTime{
public:
	SaveTime();
	SaveTime(int H, int M, int S);
	SaveTime(string time);
	SaveTime(const SaveTime& ttm);
	virtual ~SaveTime();
	
	inline int getHour(){
		return this->hour;
	};
	inline int getMinute(){
		return this->min;
	};
	inline int getSecond(){
		return this->sec;
	};
	inline string clockSaveTime(){
		return to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
	};
	//operator overiding.
	/*
	(SaveTime &) operator+(SaveTime input){
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
		return SaveTime(hourt, mint, sect);
	};
	(SaveTime &) operator-(SaveTime input){
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

		return SaveTime(hourt, mint, sect);
	};
	(SaveTime &) operator*(int&& input){
		int temp = 0;
		this->sec *= input;
		this->min *= input;
		this->min += this->sec / 60;
		this->sec = this->sec - (int)this->sec + (int)this->sec % 60;
		this->hour *= input;
		this->hour += this->min / 60;
		this->min = this->min % 60;
	};
	(SaveTime &) operator/(int&& input){
		this->min += (this->hour % input) * 60;
		this->hour /= input;
		this->sec += (this->min % input) * 60;
		this->min /= input;
		this->sec += (this->sec + 0.5) / input;
	};
	(SaveTime *) operator+=(SaveTime input){
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
	(SaveTime *) operator-=(SaveTime input){
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
	(SaveTime &) operator*=(int&& input){
		int temp = 0;
		this->sec *= input;
		this->min *= input;
		this->min += this->sec / 60;
		this->sec = this->sec - (int)this->sec + (int)this->sec % 60;
		this->hour *= input;
		this->hour += this->min / 60;
		this->min = this->min % 60;
	};
	(SaveTime &) operator/=(int&& input){
		this->min += (this->hour % input) * 60;
		this->hour /= input;
		this->sec += (this->min % input) * 60;
		this->min /= input;
		this->sec += (this->sec + 0.5) / input;
	};
	*/
	bool operator==(SaveTime input){
		return (this->hour == input.hour) && (this->min == input.min) && (this->sec == input.sec);
	};
	bool operator!=(SaveTime input){
		return !operator==(input);
	};

private:
	int hour;		//	0 ~ 23
	int min;		//	0 ~ 59
	float sec;		//	0 ~ 60.00

};

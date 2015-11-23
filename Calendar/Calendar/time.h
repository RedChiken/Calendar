#include <iostream>

using namespace std;

/*
this class can calculate about time.
save times, make it to string, and also can calculate like normal integer.
*/
class SaveTime{
public:
	SaveTime();
	SaveTime(int H, int M, int S);
	SaveTime(const SaveTime& ttm);
	virtual ~SaveTime();
	
	int getHour();
	int getMinute();
	int getSecond();
	string clockSaveTime();

	(SaveTime &) operator+(SaveTime input);
	(SaveTime &) operator-(SaveTime input);
	(SaveTime &) operator*(int&& input);
	(SaveTime &) operator/(int&& input);
	(SaveTime &) operator+=(SaveTime input);
	(SaveTime &) operator-=(SaveTime input);
	(SaveTime &) operator*=(int&& input);
	(SaveTime &) operator/=(int&& input);
	bool operator==(SaveTime input);
	bool operator!=(SaveTime input);

private:
	int hour;		//	0 ~ 23
	int min;		//	0 ~ 59
	float sec;		//	0 ~ 60.00

};

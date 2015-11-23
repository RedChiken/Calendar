#include <iostream>
#include <time.h>
#include "Calendar.h"

using namespace std;

class Date{
public:
	//about interating
	Date();
	Date(const Date &dtp);
	virtual ~Date();

	//basic methods about date's information
	int getYear(); 
	int getMonth();
	int getDay();

	// methods about schedule and should be seperated from this class.
	void addSchedule();
	//SearchSchedule(...) 함수
	/*DB를 연결하여 RDB 명령어를 만들어 사용해보자*/
	/*
	1. 시작 시간
		1) 일정 시작시간에 시작하는 스케쥴
		2) 시작시간이 가장 빠른 스케쥴
		3) 시작시간이 가장 늦은 스케쥴
		4) 일정 시각 이전에 시작하는 스케쥴
		5) 일정 시각 이후에 시작하는 스케쥴
	2. 종료 시간
		1) 일정 종료시간에 시작하는 스케쥴
		2) 종료시간이 가장 빠른 스케쥴
		3) 종료시간이 가장 늦은 스케쥴
		4) 일정 시각 이전에 끝나는 스케쥴
		5) 일정 시각 이후에 끝나는 스케쥴
	3. 시간 범위
		1) 일정 범위 안에 존재하는 스케쥴들
		2) 시간 범위가 가장 좁은 스케쥴
		3) 시간 범위가 가장 넓은 스케쥴
		4) 일정 범위 밖에 존재하는 스케쥴들
	4. 스케쥴 명
	5. 우선도
		1) 일정 우선도를 가진 스케쥴들
		2) 일정 우선도 미만의 스케쥴들
		3) 일정 우선도 이상의 스케쥴들
		4) 가장 우선도가 높은 스케쥴
		5) 가장 우선도가 낮은 스케쥴

	*/
	void deleteSchedule();

private:
	time_t date;
	bool isExistSchedule();
	/*
	1. 스케쥴명 비교
	2. 기간 비교
	3. 키워드 비교
	*/

};
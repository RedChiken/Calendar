#include "JBsSchedule.h"
#include <string>
#include <time.h>
using namespace std;


JBsSchedule::JBsSchedule(){
	this->title = nullptr;
	this->context = nullptr;
	this->isInfinite = 0;
}
JBsSchedule::JBsSchedule(string title, TimeManager startTime, string context){
	this->title = title;
	this->startTime = startTime;
	this->context = context;
	this->isInfinite = true;
}
JBsSchedule::JBsSchedule(string title, TimeManager startTime, TimeManager endTime, string context){
	this->title = title;
	this->startTime = startTime;
	this->endTime = endTime;
	this->context = context;
	this->isInfinite = false;
}
JBsSchedule::JBsSchedule(const JBsSchedule &sch){
	this->title = sch.title;
	this->startTime = sch.startTime;
	this->endTime = sch.endTime;
	this->context = sch.context;
	this->isInfinite = sch.isInfinite;
}

JBsSchedule::~JBsSchedule(){

}

bool JBsSchedule::isEnd() {
	if (isInfinite == true) return false;

	time_t tNow = time(NULL);
	time_t tEnd;
	int nDiff; // compute time difference 시간 차이
	int eYear; // endTime's Year eT의 연도
	int eMonth; // endTime's Month eT의 월
	int eDay; // endTime's Day eT의 날짜
	int mFlag = 0; // total day for each month 각 월에 따른 날짜 계산

	eYear = endTime.getSolarYear();
	eMonth = endTime.getSolarMonth();
	eDay = endTime.getSolarDay();

	switch (eMonth) {
		// 전 월까지의 날짜를 계산하면 된다(compute last month's total day)
	case 2: mFlag += 31;
	case 3: { mFlag += 28;
		if (eYear % 400 == 0) mFlag += 1;
		else if (eYear % 100 == 0);
		else if (eYear % 4 == 0) mFlag += 1; }
	case 4: mFlag += 31;
	case 5: mFlag += 30;
	case 6: mFlag += 31;
	case 7: mFlag += 30;
	case 8: mFlag += 31;
	case 9: mFlag += 31;
	case 10: mFlag += 30;
	case 11: mFlag += 31;
	case 12: mFlag += 30;
	}
	tNow += 86400 + (9 * 3600);
	// 현재시간 :: 1970년 1월 1일 기준이라 + 1일, (GMF) 한국시간이므로 +9시간 
	tEnd = eYear * 86400 * 365 // 연도 시간
		+ mFlag * 86400 // 월 시간
		+ eDay * 86400 // 일 시간
		+ 9 * 3600; // 한국시간 + 9시간

	nDiff = difftime(tEnd, tNow); // 두 시간 간의 차이를 초(sec) 단위로 계산한다.
	if (nDiff > 0) end = false; // 시간차가 남아있을 경우
	else end = true; // 시간차가 남아있지 않거나 과거인 경우

	return end;
}
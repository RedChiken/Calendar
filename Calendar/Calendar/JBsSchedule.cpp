#include "JBsSchedule.h"
#include <string>
#include <time.h>
using namespace std;


JBsSchedule::JBsSchedule(){
	this->title = nullptr;
	this->startTime = nullptr;
	this->endTime = nullptr;
	this->context = nullptr;
	this->isInfinite = nullptr;
}
JBsSchedule::JBsSchedule(string title, string startTime, string context) {
	this->title = title;
	this->startTime = startTime;
	this->endTime = nullptr;
	this->context = context;
	this->isInfinite = true;
}
JBsSchedule::JBsSchedule(string title, string startTime, string endTime, string context){
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
	if (this->endTime == "") this->isInfinite = true;
	else isInfinite = false;
}

JBsSchedule::~JBsSchedule(){

}

bool JBsSchedule::isEnd() {
	if (isInfinite == true) return false;

	time_t tNow = time(NULL);
	time_t tEnd;
	int nDiff; // 시간의 차이를 계산
	int eYear; // endTime의 연도를 int형으로
	int eMonth; // endTime의 월을 int형으로
	int eDay; // endTime의 일을 int형으로
	int mFlag = 0; // 월에 따른 날짜 구분을 위하여 사용

	eYear = ((endTime[0] - '0') * 1000) + ((endTime[1] - '0') * 100) + ((endTime[2] - '0') * 10) + (endTime[3] - '0');
	eMonth = ((endTime[4] - '0') * 10) + (endTime[5] - '0');
	eDay = ((endTime[6] - '0') * 10) + (endTime[7] - '0');

	switch (eMonth) {
	case 1: mFlag += 31;
	case 2: { mFlag += 28;
		if (eYear % 400 == 0) mFlag += 1;
		else if (eYear % 100 == 0);
		else if (eYear % 4 == 0) mFlag += 1; }
	case 3: mFlag += 31;
	case 4: mFlag += 30;
	case 5: mFlag += 31;
	case 6: mFlag += 30;
	case 7: mFlag += 31;
	case 8: mFlag += 31;
	case 9: mFlag += 30;
	case 10: mFlag += 31;
	case 11: mFlag += 30;
	case 12: mFlag += 31;
	}
	tNow += 86400 + (9 * 3600);
	// 현재시간 :: 1970년 1월 1일 기준이라 + 1일, (GMF) 한국시간이므로 +9시간 
	tEnd += eYear * 86400 * 365 // 연도 시간
		+ mFlag * 86400 // 월 시간
		+ eDay * 86400 // 일 시간
		+ 9 * 3600; // 한국시간 + 9시간

	nDiff = difftime(tEnd, tNow); // 두 시간 간의 차이를 초(sec) 단위로 계산한다.
	if (nDiff > 0) end = false; // 시간차가 남아있을 경우
	else end = true; // 시간차가 남아있지 않거나 과거인 경우

	return end;
}
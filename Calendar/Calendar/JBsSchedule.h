#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <string>
#include "TimeManager.h"

using namespace std;
/*
form about schedule.
it contain title, startTime, endTime, and context.
also it has is this schedule is end or not.
you can check the status about each schedule.
*/
class JBsSchedule {
public:
	JBsSchedule();
	JBsSchedule(string title, TimeManager startTime, string context);
	JBsSchedule(string title, TimeManager startTime, TimeManager endTime, string context);
	JBsSchedule(const JBsSchedule &sch);

	virtual ~JBsSchedule();

	inline string getTitle() {
		return this->title;
	};
	inline TimeManager getStartTime() {
		return this->startTime;
	};
	inline TimeManager getEndTime() {
		return this->endTime;
	};
	inline string getContext() {
		return this->context;
	};
	bool isEnd();
	inline void endSchedule() {
		end = true;
	};
	inline bool getIsInfinite(){
		return isInfinite;
	}
	inline void delaySchedule(TimeManager input){
		this->startTime += input;
		this->endTime += input;
	}
	//setter
	inline void setIsInfinite(bool isInfinite){
		this->isInfinite = isInfinite;
	}

	bool operator==(JBsSchedule input) {
		return (this->title == input.title)
			&& (this->startTime == input.startTime)
			&& (this->endTime == input.endTime)
			&& (this->context == input.context);
	};
	bool operator!=(JBsSchedule input) {
		return !operator==(input);
	};

	JBsSchedule & operator+(JBsSchedule input) {

	};
	JBsSchedule & operator+=(JBsSchedule input) {

	};


private:
	string title; // 스케쥴 제목 (title of schedule)
	TimeManager startTime, endTime; // 스케쥴 시작시간, 종료시간 (startTime/endTime of schedule)
	string context; // 스케쥴 내용 (details of schedule)
	bool isInfinite; // 스케쥴이 무한인지 아닌지 판별하는 변수 (about this schedule is infinite)
	bool end; // 종료 여부 (whether this schedule is end or not)
};
#endif
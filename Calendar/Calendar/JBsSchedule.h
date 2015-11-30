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

	bool operator==(JBsSchedule input) {
		return (this->title == input.title)
			&& (this->startTime == input.startTime)
			&& (this->endTime == input.endTime)
			&& (this->context == input.context);
	};
	bool operator!=(JBsSchedule input) {
		return !operator==(input);
	};
	//operation overloading

	(JBsSchedule &) operator+(JBsSchedule input) {

	};
	(JBsSchedule &) operator+=(JBsSchedule input) {

	};


private:
	string title; // ������ ���� (title of schedule)
	TimeManager startTime, endTime; // ������ ���۽ð�, ����ð� (startTime/endTime of schedule)
	string context; // ������ ���� (details of schedule)
	bool isInfinite; // �������� �������� �ƴ��� �Ǻ��ϴ� ���� (about this schedule is infinite)
	bool end; // ���� ���� (whether this schedule is end or not)
};
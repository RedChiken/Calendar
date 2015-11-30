#include <iostream>
#include <string>

using namespace std;
/*
form about schedule.
it contain title, startTime, endTime, and context.
also it has is this schedule is end or not.
you can check the status about each schedule.
*/
class JBsSchedule{
public:
	JBsSchedule();
	JBsSchedule(string title, string startTime, string context);
	JBsSchedule(string title, string startTime, string endTime, string context);
	JBsSchedule(const JBsSchedule &sch);

	virtual ~JBsSchedule();

	inline string getTitle(){
		return this->title;
	};
	inline string getStartTime(){
		return this->startTime;
	};
	inline string getEndTime(){
		return this->endTime;
	};
	inline string getContext(){
		return this->context;
	};
	bool isEnd();
	inline void endSchedule(){
		end = true;
	};

	bool operator==(JBsSchedule input){
		return (this->title == input.title) 
			&& (this->startTime == input.title) 
			&& (this->endTime == input.endTime) 
			&& (this->context == input.context);
	};
	bool operator!=(JBsSchedule input){
		return !operator==(input);
	};

	bool operator>(JBsSchedule input) {
		int thisDayS, inputDayS;
		int thisDayE, inputDayE;

		thisDayS = ((startTime[0] - '0') * 1000) + ((startTime[1] - '0') * 100) + ((startTime[2] - '0') * 10) + (startTime[3] - '0') +
			((startTime[4] - '0') * 10) + (startTime[5] - '0') +
			((startTime[6] - '0') * 10) + (startTime[7] - '0');
		inputDayS = ((input.startTime[0] - '0') * 1000) + ((input.startTime[1] - '0') * 100) + ((input.startTime[2] - '0') * 10) + (input.startTime[3] - '0') +
			((input.startTime[4] - '0') * 10) + (input.startTime[5] - '0') +
			((input.startTime[6] - '0') * 10) + (input.startTime[7] - '0');

		if (thisDayS == inputDayS) {
			thisDayE = ((endTime[0] - '0') * 1000) + ((endTime[1] - '0') * 100) + ((endTime[2] - '0') * 10) + (endTime[3] - '0') +
				((endTime[4] - '0') * 10) + (endTime[5] - '0') +
				((endTime[6] - '0') * 10) + (endTime[7] - '0');
			inputDayE = ((input.endTime[0] - '0') * 1000) + ((input.endTime[1] - '0') * 100) + ((input.endTime[2] - '0') * 10) + (input.endTime[3] - '0') +
				((input.endTime[4] - '0') * 10) + (input.endTime[5] - '0') +
				((input.endTime[6] - '0') * 10) + (input.endTime[7] - '0');
			return (thisDayE < inputDayE) ? true : false;
		}
		else {
			return (thisDayS < inputDayS) ? true : false;
		}
	};


	bool operator<(JBsSchedule input) {
		int thisDayS, inputDayS;
		int thisDayE, inputDayE;

		thisDayS = ((startTime[0] - '0') * 10000000) + ((startTime[1] - '0') * 1000000) + ((startTime[2] - '0') * 100000) + ((startTime[3] - '0') * 10000)+
			((startTime[4] - '0') * 1000) + ((startTime[5] - '0') * 100) +
			((startTime[6] - '0') * 10) + (startTime[7] - '0');
		inputDayS = ((input.startTime[0] - '0') * 10000000) + ((input.startTime[1] - '0') * 1000000) + ((input.startTime[2] - '0') * 100000) + ((input.startTime[3] - '0') * 10000) +
			((input.startTime[4] - '0') * 1000) + ((input.startTime[5] - '0') * 100) +
			((input.startTime[6] - '0') * 10) + (input.startTime[7] - '0');

		if (thisDayS == inputDayS) {
			thisDayE = ((endTime[0] - '0') * 10000000) + ((endTime[1] - '0') * 1000000) + ((endTime[2] - '0') * 100000) + ((endTime[3] - '0') * 10000)+
				((endTime[4] - '0') * 1000) + ((endTime[5] - '0') * 100) +
				((endTime[6] - '0') * 10) + (endTime[7] - '0');
			inputDayE = ((input.endTime[0] - '0') * 10000000) + ((input.endTime[1] - '0') * 1000000) + ((input.endTime[2] - '0') * 100000) + ((input.endTime[3] - '0') * 10000) +
				((input.endTime[4] - '0') * 1000) + ((input.endTime[5] - '0') * 100) +
				((input.endTime[6] - '0') * 10) + (input.endTime[7] - '0');
			return (thisDayE > inputDayE) ? true : false;
		}
		else {
			return (thisDayS > inputDayS) ? true : false;
		}
	};

	//operation overloading
	/*
	(Schedule &) operator+(Schedule input){

	};
	(Schedule &) operator+=(Schedule input){

	};
	*/

private:
	string title; // (title of schedule)
	string startTime, endTime; // (startTime/endTime of schedule)
	string context; // (details of schedule)
	bool isInfinite; // (about this schedule is infinite)
	bool end; // (whether this schedule is end or not)
};
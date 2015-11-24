#include <iostream>

using namespace std;
/*
form about schedule.
it contain title, startTime, endTime, and context.
also it has is this schedule is end or not.
you can check the status about each schedule.
*/
class Schedule{
public:
	Schedule();
	Schedule(string title, string startTime, string endTime, string context);
	Schedule(const Schedule &sch);
	virtual ~Schedule();

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
	inline bool isEnd(){
		return end;
	};
	inline void endSchedule(){
		end = true;
	};

	bool operator==(Schedule input){
		return (this->title == input.title) 
			&& (this->startTime == input.title) 
			&& (this->endTime == input.endTime) 
			&& (this->context == input.context);
	};
	bool operator!=(Schedule input){
		return !operator==(input);
	};
	//operation overloading
	/*
	(Schedule &) operator+(Schedule input){

	};
	(Schedule &) operator+=(Schedule input){

	};
	*/

private:
	string title;
	string startTime, endTime;
	string context;
	bool end;
};
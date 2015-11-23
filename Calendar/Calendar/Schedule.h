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

	string getTitle();
	string getStartTime();
	string getEndTime();
	string getContext();
	bool isEnd();
	void endSchedule();

	bool operator==(Schedule input);
	bool operator!=(Schedule input);
	(Schedule &) operator+(Schedule input);
	(Schedule &) operator+=(Schedule input);

private:
	string title;
	string startTime, endTime;
	string context;
	bool isEnd;
};
#include "Schedule.h"

Schedule::Schedule(){
	this->title = nullptr;
	this->startTime = nullptr;
	this->endTime = nullptr;
	this->context = nullptr;
}
Schedule::Schedule(string title, string startTime, string endTime, string context){
	this->title = title;
	this->startTime = startTime;
	this->endTime = endTime;
	this->context = context;
}
Schedule::Schedule(const Schedule &sch){
	this->title = sch.title;
	this->startTime = sch.startTime;
	this->endTime = sch.endTime;
	this->context = sch.context;
}
Schedule::~Schedule(){

}
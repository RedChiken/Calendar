#include "JBsSchedule.h"

JBsSchedule::JBsSchedule(){
	this->title = nullptr;
	this->startTime = nullptr;
	this->endTime = nullptr;
	this->context = nullptr;
}
JBsSchedule::JBsSchedule(string title, string startTime, string endTime, string context){
	this->title = title;
	this->startTime = startTime;
	this->endTime = endTime;
	this->context = context;
}
JBsSchedule::JBsSchedule(const JBsSchedule &sch){
	this->title = sch.title;
	this->startTime = sch.startTime;
	this->endTime = sch.endTime;
	this->context = sch.context;
}
JBsSchedule::~JBsSchedule(){

}
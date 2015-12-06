#include <string.h>
#include "ScheduleManager.h"
#include "FileController.h"
#include <iostream>
#include <list>
#include "JBsSchedule.h"
#pragma warning(disable:4996)
#define SIZE 1000

ScheduleManager* ScheduleManager::lib = NULL;

ScheduleManager::ScheduleManager(){
	this->file = nullptr;
}
ScheduleManager::ScheduleManager(const ScheduleManager &flb){

}
ScheduleManager::~ScheduleManager(){

}
list<JBsSchedule> ScheduleManager::getScheduleList(TimeManager date){
	file = new FileController();
	list<JBsSchedule> temp = file->readFile();
	list<JBsSchedule> ret;
	for (int i = 0; i < temp.size(); i++){
		JBsSchedule schedule = temp.front();
		if (schedule.getStartTime().isSameDate(date) && schedule.getEndTime().isSameDate(date)){
			JBsSchedule same(schedule);
			ret.push_front(same);
		}
		temp.push_back(schedule);
	}
	file->writeFile(temp);
	delete file;
}
void ScheduleManager::recursiveWrite(JBsSchedule schedule, TimeManager cycle, int times){
	file = new FileController();
	bool flag = (times == 0);
	if (flag){
		recursiveWrite(schedule, cycle, 10);
	}
	else{
		list<JBsSchedule> temp = file->readFile();
		for (int i = 0; i < times; i++){
			temp.push_front(schedule);
			
			schedule.getStartTime() += cycle;
			schedule.getEndTime() += cycle;
			/*
			I think we need constructor JBsSchedule(JBsSchedule start, TimeManager cycle)
			that add startTime and endTime as much as cycle time.
			And we need += operator in JBsSchedule
			*/
		}
		file->writeFile(temp);
	}
	delete file;
}

bool ScheduleManager::addSchedule(JBsSchedule sched){
	file = new FileController();
	bool flag = file->isScheduleExist(sched);
	if (flag){
		list<JBsSchedule> temp = file->readFile();
		temp.push_front(sched);
		file->writeFile(temp);
	}
	delete file;
	return flag;
}
void ScheduleManager::deleteSchedule(JBsSchedule sched){
	file = new FileController();
	//JBsSchedule temp;
	list<JBsSchedule> list = file->readFile();
	std::list<JBsSchedule>::iterator findSchedule = std::find(list.begin(), list.end(), sched);
	list.erase(findSchedule);
	/*
	for (int i = 0; i < list.size(); i++){
		temp = list.front();
		if (temp != sched){
			list.push_back(temp);
		}
	}
	*/
	file->writeFile(list);
	delete file;
}
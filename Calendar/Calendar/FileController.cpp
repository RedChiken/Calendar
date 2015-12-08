#pragma warning(disable:4996)
#include "FileController.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;

#define SCHEDULE "schedule.txt"

/*
file format

- TITLE (제목)
- DETAIL (설명)
- DTSTART (시작 날짜. 년월일시분초 형태로 기록)
- DTEND (끝 날짜, 없을 시 무한대로 반복이 됨)
- RRULE (반복(있을 시))
RRULE : FREQ=DAILY, WEEKLY, MONTHLY, YEARLY; (반복 종류 : 일별, 주별, 월별, 연별)

1. 일별 반복의 경우 : 반복 주기 n 받기(n일마다 반복)
2. 주별 반복의 경우 : 해당 일정의 요일 반복
3. 월별 반복의 경우 : 해당 일정의 일 반복
4. 연별 반복의 경우 : 해당 일정의 월, 일 반복

private:
ofstream out;
ifstream in;
*/

FileController::FileController(){ }

FileController::FileController(const FileController &fc){ }

FileController::~FileController(){ }

void FileController::writeFile(list<JBsSchedule> &list){
	ofstream file(SCHEDULE);

	for (std::list<JBsSchedule>::iterator it = list.begin(); it != list.end(); it++){
		file << "TITLE " << it->getTitle() << endl;
		file << "DETAIL " << it->getContext() << endl;
		file << "DTSTART " << it->getStartTime().toString(true) << endl; //always assume the time as solar
		if (it->getIsInfinite() == true){
			file << "DTEND 0" << endl;
		}
		else{
			file << "DTEND " << it->getEndTime().toString(true) << endl; //always assume the time as solar
		}
		file << "RRULE ";
		if (it->getStartTime().getRepeatDay() != 0){
			file << "DAILY;" << it->getStartTime().getRepeatDay() << endl;
		}
		else if (it->getStartTime().getRepeatWeek() == true){
			file << "WEEKLY;" << endl;
		}
		else if (it->getStartTime().getRepeatMonth() == true){
			file << "MONTHLY;" << endl;
		}
		else if (it->getStartTime().getRepeatYear() == true){
			file << "YEARLY;" << endl;
		}
		else{
			file << "0" << endl;
		}
	}
	file.close();
}

list<JBsSchedule> FileController::readFile(){
	ifstream file(SCHEDULE);
	list<JBsSchedule> list;
	string line, title, context, startTime, endTime, repeat;

	while (getline(file, line))
	{
		istringstream iss(line);
		char *temp = new char[line.size() + 1];
		copy(line.begin(), line.end(), temp);
		temp[line.size()] = '0\n';
		char *keyword = strtok(temp, " ,=");
		if (strcmp(keyword, "TITLE") == 0){
			string temp(strtok(NULL, "\n"));
			title = temp;
		}
		else if (strcmp(keyword, "DETAIL") == 0){
			string temp(strtok(NULL, "\n"));
			context = temp;
		}
		else if (strcmp(keyword, "DTSTART") == 0){
			string temp(strtok(NULL, "\n"));
			startTime = temp;
		}
		else if (strcmp(keyword, "DTEND") == 0){
			string temp(strtok(NULL, "\n"));
			endTime = temp;
		}
		else if (strcmp(keyword, "RRULE") == 0){
			//put all data to schedule object
			TimeManager startT(startTime);
			TimeManager endT(endTime);
			JBsSchedule schedule(title, startT, endT, context);
			if (endTime.compare("0") == 0){
				schedule.setIsInfinite(true);
			}
			else{
				schedule.setIsInfinite(false);
			}
			string temp(strtok(NULL, "\n,;"));
			if (temp.compare("DAILY") == 0){
				string dayRepeat(strtok(NULL, "\n"));
				schedule.getStartTime().setRepeatDate(false, false, false, stoi(dayRepeat));
			}
			else if (temp.compare("WEEKLY") == 0){
				schedule.getStartTime().setRepeatDate(false, false, true);
			}
			else if (temp.compare("MONTHLY") == 0){
				schedule.getStartTime().setRepeatDate(false, true);
			}
			else if (temp.compare("YEARLY") == 0){
				schedule.getStartTime().setRepeatDate(true);
			}
			else{
				assert(temp.compare("0") == 0);
				schedule.getStartTime().setRepeatDate(false);
				//schedule.setIsInfinite(false);
			}
			list.push_back(schedule);
		}
		else{
			cout << "error occured while reading file" << endl;
		}

	}

	return list;
}

bool FileController::isScheduleExist(JBsSchedule &schedule){

	return true;
}

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

- TITLE (����)
- DETAIL (����)
- DTSTART (���� ��¥. ����Ͻú��� ���·� ���)
- DTEND (�� ��¥, ���� �� ���Ѵ�� �ݺ��� ��)
- RRULE (�ݺ�(���� ��))
RRULE : FREQ=DAILY, WEEKLY, MONTHLY, YEARLY; (�ݺ� ���� : �Ϻ�, �ֺ�, ����, ����)

1. �Ϻ� �ݺ��� ��� : �ݺ� �ֱ� n �ޱ�(n�ϸ��� �ݺ�)
2. �ֺ� �ݺ��� ��� : �ش� ������ ���� �ݺ�
3. ���� �ݺ��� ��� : �ش� ������ �� �ݺ�
4. ���� �ݺ��� ��� : �ش� ������ ��, �� �ݺ�

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
		if (it->getEndTime() == 0){
			file << "DTEND 0" << endl;
		}
		else{
			file << "DTEND " << it->getEndTime().toString(true) << endl; //always assume the time as solar
		}
		if (it->getIsInfinite() == true){
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
		}
		else{
			file << "RRULE 0" << endl;
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
			string temp(strtok(NULL, ";"));
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
				//assert(temp.compare("0") == 0);
				schedule.getStartTime().setRepeatDate(false);
				schedule.setIsInfinite(false);
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

#include "JBsSchedule.h"
#include <string>
#include <time.h>
using namespace std;


JBsSchedule::JBsSchedule(){
	this->title = nullptr;
	this->startTime = nullptr;
	this->endTime = nullptr;
	this->context = nullptr;
	this->isInfinite = nullptr;
}
JBsSchedule::JBsSchedule(string title, string startTime, string context) {
	this->title = title;
	this->startTime = startTime;
	this->endTime = nullptr;
	this->context = context;
	this->isInfinite = true;
}
JBsSchedule::JBsSchedule(string title, string startTime, string endTime, string context){
	this->title = title;
	this->startTime = startTime;
	this->endTime = endTime;
	this->context = context;
	this->isInfinite = false;
}
JBsSchedule::JBsSchedule(const JBsSchedule &sch){
	this->title = sch.title;
	this->startTime = sch.startTime;
	this->endTime = sch.endTime;
	this->context = sch.context;
	if (this->endTime == "") this->isInfinite = true;
	else isInfinite = false;
}

JBsSchedule::~JBsSchedule(){

}

bool JBsSchedule::isEnd() {
	if (isInfinite == true) return false;

	time_t tNow = time(NULL);
	time_t tEnd;
	int nDiff; // compute time difference �ð� ����
	int eYear; // endTime's Year eT�� ����
	int eMonth; // endTime's Month eT�� ��
	int eDay; // endTime's Day eT�� ��¥
	int mFlag = 0; // total day for each month �� ���� ���� ��¥ ���

	eYear = ((endTime[0] - '0') * 1000) + ((endTime[1] - '0') * 100) + ((endTime[2] - '0') * 10) + (endTime[3] - '0');
	eMonth = ((endTime[4] - '0') * 10) + (endTime[5] - '0');
	eDay = ((endTime[6] - '0') * 10) + (endTime[7] - '0');

	switch (eMonth) {
		// �� �������� ��¥�� ����ϸ� �ȴ�(compute last month's total day)
	case 2: mFlag += 31;
	case 3: { mFlag += 28;
		if (eYear % 400 == 0) mFlag += 1;
		else if (eYear % 100 == 0);
		else if (eYear % 4 == 0) mFlag += 1; }
	case 4: mFlag += 31;
	case 5: mFlag += 30;
	case 6: mFlag += 31;
	case 7: mFlag += 30;
	case 8: mFlag += 31;
	case 9: mFlag += 31;
	case 10: mFlag += 30;
	case 11: mFlag += 31;
	case 12: mFlag += 30;
	}
	tNow += 86400 + (9 * 3600);
	// ����ð� :: 1970�� 1�� 1�� �����̶� + 1��, (GMF) �ѱ��ð��̹Ƿ� +9�ð� 
	tEnd += eYear * 86400 * 365 // ���� �ð�
		+ mFlag * 86400 // �� �ð�
		+ eDay * 86400 // �� �ð�
		+ 9 * 3600; // �ѱ��ð� + 9�ð�

	nDiff = difftime(tEnd, tNow); // �� �ð� ���� ���̸� ��(sec) ������ ����Ѵ�.
	if (nDiff > 0) end = false; // �ð����� �������� ���
	else end = true; // �ð����� �������� �ʰų� ������ ���

	return end;
}
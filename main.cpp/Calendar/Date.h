#include <iostream>
#include <time.h>
#include "Calendar.h"

using namespace std;

class Date{
public:
	//about interating
	Date();
	Date(const Date &dtp);
	virtual ~Date();

	//basic methods about date's information
	int getYear(); 
	int getMonth();
	int getDay();

	// methods about schedule and should be seperated from this class.
	void addSchedule();
	//SearchSchedule(...) �Լ�
	/*DB�� �����Ͽ� RDB ��ɾ ����� ����غ���*/
	/*
	1. ���� �ð�
		1) ���� ���۽ð��� �����ϴ� ������
		2) ���۽ð��� ���� ���� ������
		3) ���۽ð��� ���� ���� ������
		4) ���� �ð� ������ �����ϴ� ������
		5) ���� �ð� ���Ŀ� �����ϴ� ������
	2. ���� �ð�
		1) ���� ����ð��� �����ϴ� ������
		2) ����ð��� ���� ���� ������
		3) ����ð��� ���� ���� ������
		4) ���� �ð� ������ ������ ������
		5) ���� �ð� ���Ŀ� ������ ������
	3. �ð� ����
		1) ���� ���� �ȿ� �����ϴ� �������
		2) �ð� ������ ���� ���� ������
		3) �ð� ������ ���� ���� ������
		4) ���� ���� �ۿ� �����ϴ� �������
	4. ������ ��
	5. �켱��
		1) ���� �켱���� ���� �������
		2) ���� �켱�� �̸��� �������
		3) ���� �켱�� �̻��� �������
		4) ���� �켱���� ���� ������
		5) ���� �켱���� ���� ������

	*/
	void deleteSchedule();

private:
	time_t date;
	bool isExistSchedule();
	/*
	1. ������� ��
	2. �Ⱓ ��
	3. Ű���� ��
	*/

};
// Tester

#include "FileController.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(void){
	FileController fc;
	list<JBsSchedule> list, readList;
	//list<JBsSchedule> readList;

	for (int i = 0; i < 10; i++){
		string s = to_string(i * 100);
		string c = "context";
		TimeManager tm;
		tm.setDate(2015, 12, 3);
		tm.setTime(3, 30, 30);
		tm.setRepeatDate(true, false, false, 0);
		JBsSchedule sc(s, tm, c);
		list.push_back(sc);
	}

	fc.writeFile(list);
	readList = fc.readFile();

	cout << "file is read\n";

	return 0;
}
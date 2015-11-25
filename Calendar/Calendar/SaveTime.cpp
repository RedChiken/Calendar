#include "SaveTime.h"
#include <string.h>
#pragma warning(disable:4996)

SaveTime::SaveTime(){
	this->hour = 0;
	this->min = 0;
	this->sec = 0;
}
SaveTime::SaveTime(string input){
	char temp[20];
	char *ptr;
	strcpy(temp, input.c_str());
	ptr = strtok(temp, ":");
	int H = atoi(ptr);
	ptr = strtok(NULL, ":");
	int M = atoi(ptr);
	ptr = strtok(NULL, ":");
	double S = atof(ptr);
	SaveTime(H, M, S);
}
SaveTime::SaveTime(int H, int M, double S){
	this->hour = H;
	this->min = M;
	this->sec = S;
}
SaveTime::SaveTime(const SaveTime& ttm){
	
}
SaveTime::~SaveTime(){

}
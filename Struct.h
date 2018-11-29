#ifndef STRUCT_H
#define STRUCT_H
#include<iostream>
using namespace std;

struct process {
	char name[10];
	int timeRL, timeCPU, priority;
	int timeOUT, timeIN, timewait, timesave;
	int index; //the index of pr[i]
};

typedef process *ListP;
#endif

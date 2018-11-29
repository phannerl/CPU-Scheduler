#ifndef PROCESS_PRIORITY_H
#define PROCESS_PRIORITY_H
#include<iostream>

#include"Struct.h"

void process_PRIORITY_nonpreemptive(ListP &pr, int n, int timeOUT, int sum);
void process_PRIORITY_preemptive(ListP &pr, ListP &RL, int n, int &m, int timeOUT, int sum);

#endif

#ifndef PROCESS_SJF_H
#define PROCESS_SJF_H
#include<iostream>

#include"Struct.h"

void process_SJF_nopreemptive(ListP &pr, int n, int timeOUT, int sum);
void process_SJF_preemptive(ListP &pr, ListP &RL, int n, int &m, int timeOUT, int sum);

#endif

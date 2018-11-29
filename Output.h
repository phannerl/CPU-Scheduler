#ifndef OUTPUT_H
#define OUTPUT_H
#include<iostream>

#include"Struct.h"

void output_Process(ListP pr, ListP RL, int n, int m, int timeOUT);

void output_FIFO(ListP pr, ListP RL, int n, int m, int timeOUT);
void output_RR(ListP pr, ListP RL, int n, int m, int timeOUT);
void output_PRIORITY_preemptive(ListP pr, ListP RL, int n, int m, int timeOUT);
void output_PRIORITY_nonpreemptive(ListP pr, ListP RL, int n, int m, int timeOUT);
void output_SJF_preemptive(ListP pr, ListP RL, int n, int m, int timeOUT);
void output_SJF_nopreemptive(ListP pr, ListP RL, int n, int m, int timeOUT);

void swt_result(int n);

#endif

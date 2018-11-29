#ifndef DEFINE_H
#define DEFINE_H
#include<iostream>

#include"Struct.h"

void INPUT(ListP &pr, int &n, int &timeOUT, int quantum);

void OUTPUT(ListP pr, ListP RL, int n, int m, int timeOUT, int set);

void PROCESS(ListP &pr, ListP &RL, int n, int &m, int timeOUT, int set, int quantum, int sum);

#endif

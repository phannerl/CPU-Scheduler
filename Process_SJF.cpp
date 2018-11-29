#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>

#include "Process_RR.h"

#define INP "input.txt"

using namespace std;

void process_SJF_nopreemptive(ListP &pr, int n, int timeOUT, int sum) {
	ListP RL = new process[n];
	ListP pr1 = pr; //list temp of pr
	int j = 0, m = 0;
	int temptime = 0;
	for (int t = 0; t <= timeOUT; t++) {
		if (m > 0 && j < m) {
			if (temptime < RL[j].timeCPU)
				temptime++;
			if (temptime == RL[j].timeCPU) {
				RL[j].timeIN = t - RL[j].timeCPU;
				RL[j].timeOUT = RL[j].timeIN + RL[j].timeCPU;
				RL[j].timewait = RL[j].timeOUT - (RL[j].timeRL + RL[j].timeCPU);
				RL[j].timesave = RL[j].timeOUT - RL[j].timeRL;
				temptime = 0;
				j++;
			}
		}
		for (int i = 0; i < n; i++)
			if (t == pr1[i].timeRL) {
				int k = m;
				while (k > j + 1 && pr1[i].timeCPU < RL[k - 1].timeCPU) {
					RL[k] = RL[k - 1];
					k--;
				}
				RL[k] = pr1[i];
				m++;
			}
	}
	pr = RL;
	for(int i=0; i<n; i++){
		sum += pr[i].timewait;
	}
}

void process_SJF_preemptive(ListP &pr, ListP &RL, int n, int &m, int timeOUT, int sum) {
	RL = new process;
	ListP pr1 = pr; //list temp of pr
	process temp;
	int j = 0;
	m = 0;
	int temptime = 0;
	for (int t = 0; t <= timeOUT; t++) {
		if (m > 0 && j < m) {
			if (temptime < RL[j].timeCPU)
				temptime++;
			if (temptime == RL[j].timeCPU) {
				RL[j].timeIN = t - RL[j].timeCPU;
				RL[j].timeOUT = RL[j].timeIN + RL[j].timeCPU;
				RL[j].timewait = RL[j].timeOUT - (RL[j].timeRL + RL[j].timeCPU);
				RL[j].timesave = RL[j].timeOUT - RL[j].timeRL;

				pr1[RL[j].index].timeOUT = t;
				pr1[RL[j].index].timewait = pr1[RL[j].index].timeOUT
						- (pr1[RL[j].index].timeRL + pr1[RL[j].index].timeCPU);
				pr1[RL[j].index].timesave = pr1[RL[j].index].timeOUT - pr1[RL[j].index].timeRL;

				temptime = 0;
				j++;
			}
		}
		for (int i = 0; i < n; i++)	{
			if (t == pr1[i].timeRL) {
				m++;
				int k = m - 1;
				RL = (process *) realloc(RL, m * sizeof(process));
				if (temptime > 0 && pr1[i].timeCPU < RL[j].timeCPU - temptime) {
					m++;
					k = m - 1;
					RL = (process *) realloc(RL, m * sizeof(process));
					for (k = m - 1; k > j + 1; k--)
						RL[k] = RL[k - 2];
					RL[j + 1] = pr1[i];

					RL[j + 2] = RL[j];
					RL[j + 2].timeCPU -= temptime;

					RL[j].timeIN = t - temptime;
					RL[j].timeOUT = t;
					RL[j].timeCPU = temptime;
					temptime = 0;
					j++;
				} else {
					while (k > j + 1 && pr1[i].timeCPU < RL[k - 1].timeCPU) {
						RL[k] = RL[k - 1];
						k--;
						if (k == j + 1
								&& pr1[i].timeCPU < RL[k - 1].timeCPU - temptime) {
							RL[k] = RL[k - 1];
							k--;
						}
					}
					RL[k] = pr1[i];
				}
			}
		}
	}
	for(int i=0; i<n; i++)	{
		sum += pr[i].timewait;
	}
}

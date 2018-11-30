#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>

#include "Process_RR.h"

using namespace std;

void process_RR(ListP &pr, ListP &RL, int n, int &m, int timeOUT, int quantum, int sum) //Round Robin
	{
		RL = new process;
		ListP pr1 = pr; //list temp of pr
		m = 0; // the number of element in RL
		int count = 0; //count time quantum
		int j = 0;
		int temptime = 0;
		
		for (int t = 0; t <= timeOUT; t++) {
			if (m > 0 && j < m) {
				count++;
				if (count <= quantum && RL[j].timeCPU - temptime > 0){
					temptime++;
					for (int i = 1; i < n; i++)	{
						if (t == pr1[i].timeRL) {
							m++;
							RL = (process *) realloc(RL, m * sizeof(process));
							RL[m - 1] = pr1[i];
						}
					}
				}
				if (count == quantum && RL[j].timeCPU - temptime > 0) {
					m++;
					RL = (process *) realloc(RL, m * sizeof(process));
					RL[m - 1] = RL[j];
					RL[m - 1].timeCPU -= temptime;
				}
				if (RL[j].timeCPU - temptime == 0) {
					pr1[RL[j].index].timeOUT = t;
					pr1[RL[j].index].timewait = pr1[RL[j].index].timeOUT - (pr1[RL[j].index].timeRL + pr1[RL[j].index].timeCPU);
					pr1[RL[j].index].timesave = pr1[RL[j].index].timeOUT - pr1[RL[j].index].timeRL;
				}
				if (count == quantum || RL[j].timeCPU - temptime == 0) {
					RL[j].timeOUT = t;
					RL[j].timeCPU = temptime;
					RL[j].timeIN = t - RL[j].timeCPU;
					j++;
					temptime = 0;
					count = 0;
				}
			}
			if(t == 0){
				m++;
				RL = (process *) realloc(RL, m * sizeof(process));
				RL[m - 1] = pr1[0];
			}
		}
		for(int i=0; i<n; i++)	{
				sum += pr[i].timewait;
			}
	}

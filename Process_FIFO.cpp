#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>

#include "Process_FIFO.h"

#define INP "input.txt"

using namespace std;

void process_FIFO(ListP &pr, int n, int timeOUT, int sum) {
	ListP RL = new process[n];
	int m = -1;
	for (int t = 0; t < timeOUT; t++) {
		for (int i = 0; i < n; i++)
			if (t == pr[i].timeRL)
				RL[++m] = pr[i];
	}
	timeOUT = 0;
	for (int i = 0; i <= m; i++) {
		if (timeOUT <= RL[i].timeRL) {
			timeOUT = RL[i].timeRL + RL[i].timeCPU;
			RL[i].timeIN = RL[i].timeRL;
		} else {
			timeOUT += RL[i].timeCPU;
			RL[i].timeIN = RL[i - 1].timeOUT;
		}
		RL[i].timeOUT = timeOUT;
		RL[i].timewait = RL[i].timeOUT - (RL[i].timeRL + RL[i].timeCPU);
		RL[i].timesave = RL[i].timeOUT - RL[i].timeRL;
	}
	pr = RL;
	for(int i=0; i<n; i++){
		sum += pr[i].timewait;
	}
}



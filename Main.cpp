#include<iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>

#include"Struct.h"
#include"Define.h"
#include"Process.h"
#include"Output.h"

#define INP "input.txt"

int main() {
	int quantum;
	ListP pr, RL;
	int n, m, timeOUT;
	
	timeOUT = 0;
	ifstream in(INP);
	if (in == NULL) {
		cout << "Not input file !";
		return 0;
	}
	in >> n;
	in >> quantum;
	pr = new process[n];
	for (int i = 0; i < n; i++) {
		in >> pr[i].name;
		in >> pr[i].timeRL;
		in >> pr[i].timeCPU;
		in >> pr[i].priority;
		if (timeOUT < pr[i].timeRL)
			timeOUT = pr[i].timeRL + pr[i].timeCPU;
		else
			timeOUT += pr[i].timeCPU;
		pr[i].index = i;
	}
	
	int key;
	int sum = 0;
	int a[6];
	
	INPUT(pr, n, timeOUT, quantum);
	do {
		cout << "Ban chon: ";
		key = getch() - 48;
		cout << key << endl << endl;
		if (key < 7) {
			PROCESS(pr, RL, n, m, timeOUT, key, quantum, sum);
			OUTPUT(pr, RL, n, m, timeOUT, key);
		}
		else if(key == 7) {
			for(int set = 1; set <= 6 ; set++){
				PROCESS(pr, RL, n, m, timeOUT, set, quantum, sum);
				OUTPUT(pr, RL, n, m, timeOUT, set);
			}
			swt_result(n);
		}
		else cout << "QUIT!!!";
	}while(key < 8);
	return 0;
}


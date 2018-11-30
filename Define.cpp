#include <iostream>
#include <iomanip>
#include <queue>

#include "Define.h"
#include "Output.h"
#include "Process.h"

using namespace std;

void INPUT(ListP &pr, int &n, int &timeOUT, int quantum) {
	cout << endl << "| ------------------------------INPUT------------------------------" << endl << "| " << endl;
	cout << "| Name" << setw(10) << "TimeRL" << setw(10) << "TimeCPU" << setw(10)
			<< "Priority" << endl;
	for (int i = 0; i < n; i++)
		cout << "| " << pr[i].name << setw(10) << pr[i].timeRL << setw(10)
				<< pr[i].timeCPU << setw(10) << pr[i].priority << endl;
	cout << "| Quantum = " << quantum << endl;
	cout << endl << "| -----------------------------OPTION------------------------------" << endl << endl;
	cout << "| Nhan 1 de thuc hien thuat toan FIFO!\n| Nhan 2 de thuc hien thuat toan RR!\n" 
	<< "| Nhan 3 de thuc hien thuat toan Priority preemptive!\n| Nhan 4 de thuc hien thuat toan Priority non-preemptive!\n"
	<< "| Nhan 5 de thuc hien thuat toan SJF non-preemptive!\n| Nhan 6 de thuc hien thuat toan SJF preemptive!\n" 
	<< "| Nhan 7 de in ra AWT cuar tat ca cac thuat toan\n| Nhan 8 de ket thuc chuong trinh\n";
}

void OUTPUT(ListP pr, ListP RL, int n, int m, int timeOUT, int select) {
	switch (select) {
	case 1:
		output_FIFO(pr, RL, n, m, timeOUT);
		break;
	case 2:
		output_RR(pr, RL, n, m, timeOUT);
		break;
	case 3:
		output_PRIORITY_preemptive(pr, RL, n, m, timeOUT);
		break;
	case 4:
		output_PRIORITY_nonpreemptive(pr, RL, n, n, timeOUT);
		break;
	case 5:
		output_SJF_nopreemptive(pr, RL, n, m, timeOUT);
		break;
	case 6:
		output_SJF_preemptive(pr, RL, n, m, timeOUT);
		break;
	}
	cout << endl << "| -----------------------------------END------------------------------------ |" << endl << endl;
}

void PROCESS(ListP &pr, ListP &RL, int n, int &m, int timeOUT, int select, int quantum, int sum) {
	switch (select) {
	case 1:
		process_FIFO(pr, n, timeOUT, sum);
		break;
	case 2:
		process_RR(pr, RL, n, m, timeOUT, quantum, sum);
		break;
	case 3:
		process_PRIORITY_preemptive(pr, RL, n, m, timeOUT, sum);
		break;
	case 4:
		process_PRIORITY_nonpreemptive(pr, n, timeOUT, sum);
		break;
	case 5:
		process_SJF_nopreemptive(pr, n, timeOUT, sum);
		break;
	case 6:
		process_SJF_preemptive(pr, RL, n, m, timeOUT, sum);
		break;
	}
}

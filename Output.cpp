#include <iostream>
#include <iomanip>

#include "Define.h"

using namespace std;

int sum = 0;
int a[6]; 

void output_Process(ListP pr, ListP RL, int n, int m, int timeOUT) 
{
	cout 	<< "| Name" 		<< setw(10) << "TimeRL" 	<< setw(10) << "TimeCPU" << setw(10)
			<< "Priority" 	<< setw(10) << "TimeIN" 	<< setw(10) 
			<< "TimeOUT"	<< setw(10) << "Timewait" 	<< setw(10) << "Timesave" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "| " << pr[i].name << setw(10) << pr[i].timeRL << setw(10)
				<< pr[i].timeCPU << setw(10) << pr[i].priority << setw(10)
				<< pr[i].timeIN << setw(10) << pr[i].timeOUT << setw(10)
				<< pr[i].timewait << setw(10) << pr[i].timesave << endl;
		sum += pr[i].timewait;
	}
	cout << "| Thoi gian cho TB: AWT= " << (float)sum/n << endl; 
	if(m==n) RL = pr;
	cout 	<< endl << endl << "| ---PROCESS---" 		<< endl 	<< endl;
	cout 	<< "| Name" 		<< setw(10) << "TimeRL" << setw(10) << "TimeCPU" << setw(10)
			<< "Priority" 	<< setw(10) << "TimeIN" << setw(10) << "TimeOUT"
			<< endl;
	for (int i = 0; i < m; i++)
		cout << "| " << RL[i].name << setw(10) << RL[i].timeRL << setw(10)
				<< RL[i].timeCPU << setw(10) << RL[i].priority << setw(10)
				<< RL[i].timeIN << setw(10) << RL[i].timeOUT << endl;
}

void output_FIFO(ListP pr, ListP RL, int n, int m, int timeOUT) {
	system("cls");
	cout << "| FIFO" << endl << endl << "| ----------------------------------OUTPUT---------------------------------- |" << endl << endl;
	output_Process(pr, RL, n, n, timeOUT); 
	a[0] = sum;
	sum = 0;
}

void output_RR(ListP pr, ListP RL, int n, int m, int timeOUT) {
	system("cls");
	cout << "| ROUND ROBIN" << endl << endl << "| ----------------------------------OUTPUT---------------------------------- |" << endl << endl;
	output_Process(pr, RL, n, m, timeOUT);
	a[1] = sum;
	sum = 0;
}

void output_PRIORITY_preemptive(ListP pr, ListP RL, int n, int m, int timeOUT) {
	system("cls");	
	cout << "| PRIORITY preemptive" << endl << endl << "| ----------------------------------OUTPUT---------------------------------- |" << endl << endl;
	output_Process(pr, RL, n, m, timeOUT);
	a[3] = sum;
	sum = 0;
}

void output_PRIORITY_nonpreemptive(ListP pr, ListP RL, int n, int m, int timeOUT) {
	system("cls");
	cout << "| PRIORITY non-preemptive" << endl << endl << "| ----------------------------------OUTPUT---------------------------------- |" << endl << endl;
	output_Process(pr, RL, n, n, timeOUT);
	a[2] = sum;
	sum = 0;
}

void output_SJF_preemptive(ListP pr, ListP RL, int n, int m, int timeOUT) {
	system("cls");
	cout << "| SJF preemptive" << endl << endl << "| ----------------------------------OUTPUT---------------------------------- |" << endl << endl;
	output_Process(pr, RL, n, m, timeOUT);
	a[4] = sum;
	sum = 0;
}

void output_SJF_nopreemptive(ListP pr, ListP RL, int n, int m, int timeOUT) {
	system("cls");
	cout << "| SJF non-preemptive" << endl << endl << "| ----------------------------------OUTPUT---------------------------------- |" << endl << endl;
	output_Process(pr, RL, n, m, timeOUT);
	a[5] = sum;
	sum = 0;
}
void swt_result(int n) {
	system("cls");
	cout << "| ---------------------------------------------------------- |" << endl; 
	cout << "| Thoi gian cho (AWT) cua moi thuat toan la: " << endl; 
	cout << "| ---------------------------------------------------------- |" << endl; 
	cout << "| Thoi gian cho TB cuaa FIFO: AWT= " << (float)a[0]/n << endl; 
	cout << "| Thoi gian cho TB cuaa RR: AWT= " << (float)a[1]/n << endl; 
	cout << "| Thoi gian cho TB cuaa PRIORITY_non preemptive: AWT= " << (float)a[2]/n << endl; 
	cout << "| Thoi gian cho TB cuaa PRIORITY_preemptive: AWT= " << (float)a[3]/n << endl; 
	cout << "| Thoi gian cho TB cuaa SJF_preemptive: AWT= " << (float)a[4]/n << endl;
	cout << "| Thoi gian cho TB cuaa SJF_nopreemptive: AWT= " << (float)a[5]/n << endl; 
	cout << "| ---------------------------------------------------------- |" << endl; 
}

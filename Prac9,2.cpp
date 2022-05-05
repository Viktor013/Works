#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class QueuePriority
{
	int * Wait;
	int priority, EmployeeNum, i, loop, M,K,P, count1,count2,count3;
	char EmployeeClass;
	int * Pri;
	char * Class;
	int MaxQueueLength;
	int QueueLength;

public:
	QueuePriority(int m);
	~QueuePriority();
	
	void Creation(int n);

	void Add(int c,int p, char g); 

	int Extract();        

	void Clear();    

	bool IsEmpty();    

	bool IsFull();     

	int GetCount();   

	void Show();
};


void QueuePriority::Creation(int n){
	M=0;	K=0;	P=0;	count1=0; count2=0;		count3=0;
	loop = n;
	for(i=0;i<loop;i++){
		priority = rand()%3+1;
		EmployeeNum = rand()%999;
		if (priority == 1) {
			EmployeeClass = 'P';
			P++;
			count3++;
		}
		else if (priority == 2) {
			EmployeeClass = 'K';
			K++;
			count2++;
		}
		else { 
			EmployeeClass = 'M';
			M++;
			count1++;
		}

		QueuePriority::Add(EmployeeNum,priority,EmployeeClass);
	}
	K += M;
	P += K;
}

void QueuePriority::Show(){
	cout << "\n\n" << "Номер сотрудника - Должность сотрудника - Приоритет сотрудника" << "\n\n";
	//демонстрация очереди
	for(int i=0;i<QueueLength;i++){
		cout<<Wait[i]<<" - "<< Class[i]<<" - "<< Pri[i]<< "\n\n";
	}
	cout<<"\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
	delete[]Class;
}

QueuePriority::QueuePriority(int m)
{
	MaxQueueLength=m;
	Wait=new int[MaxQueueLength];
	Pri=new int[MaxQueueLength];
	Class = new char[MaxQueueLength];
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	return QueueLength;
}

void QueuePriority::Add(int c,int p, char g)
{
	if(!IsFull()){
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		Class[QueueLength] = g;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{	
	if(!IsEmpty()){
		int max_pri=Pri[0];
		int pos_max_pri=0;
		for(int i=1;i<QueueLength;i++)
			if(max_pri<Pri[i]){
				max_pri=Pri[i];
				pos_max_pri=i;
			}
		int temp1=Wait[pos_max_pri];
		int temp2=Pri[pos_max_pri];
		for(int i=pos_max_pri;i<QueueLength-1;i++){
			Wait[i]=Wait[i+1];
			Pri[i]=Pri[i+1];
			Class[i]=Class[i+1];
		}
		M -= 1;
		K -= 1;
		P -= 1;
		if (M == 0)
			cout << "Обслуживание всех менеджеров заняло " << count1 + rand()%5 << " минут" << endl;
		if (K == 0)
			cout << "Обслуживание всех контроллеров заняло " << count2 + rand()%10 << " минут" << endl;
		if (P == 0)
			cout << "Обслуживание всех работников заняло " << count3 + rand()%15 << " минут" << endl;
		QueueLength--;	
		return temp1;		
	}
	else return -1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	
	cout << "Введите размер очереди: " << endl;
	cin >> n;
	int* line = new int [n];
	
	int priority, EmployeeNum;
	char EmployeeClass;
	
	QueuePriority QUP(n);
	QUP.Creation(n);

	for (int i=0; i<n; i++) {
		
	QUP.Show();
	QUP.Extract();
	
}
	return 0;
}

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n,i,j,temp;
	cout << "������� ������ �������: ";
	cin >> n;
	int* a = new int[n];
	cout << endl << "������ ������ �� ��������� �������������������:   ";
	for (i=0; i<n; i++)	{
		a[i] = rand() % 100; 
		cout << a[i] << "  "; 
	}
	
	for (i=0; i<n; i++)   
    {
          for(j = (i+1); j<n; j++)   
         {
                if (a[i]<a[j])          
               {
                        temp = a[i];          
                        a[i] = a[j];
                        a[j] = temp;
               }
          }
     }

	cout << endl << endl << "����� ���������� ������ ����� ��������� ���:      ";
	for (i=0; i<n; i++) {
		cout << a[i] << "  ";
	}
}

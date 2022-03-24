#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void heapify(int a[], int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 


    if (l < n && a[l] > a[largest])
        largest = l;
        
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i=n-1; i>=0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "¬ведите размер массива: ";
	cin >> n;
	int* a = new int[n];
	cout << endl << "ћассив создан со следующей последовательностью:   ";
	for (int i=0; i<n; i++)	{
		a[i] = rand() % 100;  
	}
	printArray(a, n);
	
    heapSort(a, n);
    cout << endl << endl << "ѕосле сортировки массив имеет следующий вид:      ";

    printArray(a, n);
}


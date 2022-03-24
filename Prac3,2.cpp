#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge(int* a, int low, int mid, int high)
{
    int low_copy = low;
    int mid_copy = mid;

    int size = high - low;
    int* sorted = new int[size];
    int i = 0;

    while(low_copy < mid && mid_copy < high) {
        if(a[low_copy] < a[mid_copy]) {
            sorted[i] = a[low_copy++];
        }
        else {
            sorted[i] = a[mid_copy++];
        }
        ++i;
    }

    while(low_copy < mid) {
        sorted[i++] = a[low_copy++];
    }
    while(mid_copy < high) {
        sorted[i++] = a[mid_copy++];
    }

    for(i = 0; i < size; ++i) {
        a[low + i] = sorted[i];
    }
}

void recursive_merge_sort(int* a, int low, int high) {
    if(low >= high - 1) { return; }

    int mid = (high + low) / 2;
    recursive_merge_sort(a, low, mid);
    recursive_merge_sort(a, mid, high);

    merge(a, low, mid, high);
}

void merge_sort(int* a, int n) {
    recursive_merge_sort(a, 0, n);
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	int* a = new int[n];
	cout << endl << "Массив создан со следующей последовательностью:    ";
	for (int i=0; i<n; i++)	{
		a[i] = rand() % 100; 
		cout << a[i] << "  "; 
	}
	
 //   int data[] = { 5, 1, 4, 3, 65, 6, 128, 9, 0 };
 //   int num_elements = 9;

    merge_sort(a, n);

    cout << endl << endl << "После сортировки массив имеет следующий вид:       ";
    for(int i=0; i < n; ++i) {
        cout << a[i] << "  ";
    }

    return 0;
}

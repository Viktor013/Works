#include <vector>
#include <iostream>
#include <locale.h>
#include <algorithm>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    vector <int> L1(0, 0);
    vector <int> L2(0, 0);
    vector <int> L(0, 0);
    int n1, n2, i;
    char s1 = ' ', s2 = ' ';
	cout << "¬ведите размер списка L1: " << endl;
	cin >> n1;
    for (i=0; i<n1; i++) {
        s1 = rand() % 10;
        L1.push_back(s1);
        }
    cout << endl;
    cout << "      L1: " << endl;
    for (i = 0; i < L1.size(); ++i) {
        cout << L1[i] << ' ';
        }
    cout << endl << endl;
	cout << "¬ведите размер списка L2: " << endl;
	cin >> n2;
    for (i=0; i<n2; i++) {
        s2 = rand() % 10;
        L2.push_back(s2);
        }
    cout << endl;
    cout << "      L2: " << endl;
    for (i = 0; i < L2.size(); ++i) {
        cout << L2[i] << ' ';
        }
    cout << endl;
    for (i = 0; i < L1.size(); ++i) {
        for (int h = 0; h < L2.size(); ++h) {
            if (L2[h] == L1[i]) {
                L.push_back(L1[i]);
                }
            }
        }
    cout << endl;
    vector<int>::iterator r;
    r = unique(L.begin(), L.end());
    L.resize(r - L.begin());
    if (L.size() > 0) {
        cout << "Ёлементы, содержащиес€ в обеих списках L:" << endl;
        for (i = 0; i < L.size(); ++i) {
            cout << L[i] << ' ';
            }
        cout << endl;
        }
    else
        cout << "—овпадений нет." << ' ' << endl;
    L.clear();
    return 0;
}


#include <iostream>
#include <string>
const int T_S = 200;
using namespace std;
struct HashTableEntry {
   int k;
   string v, d;
   HashTableEntry *n;
   HashTableEntry *p;
   HashTableEntry(int k, string v, string d) {
      this->k = k;
      this->v = v;
      this->d = d;
      this->n = NULL;
   }
};
class HashMapTable {
   public:
      HashTableEntry **ht, **top;
      HashMapTable() {
         ht = new HashTableEntry*[T_S];
         for (int i = 0; i < T_S; i++)
            ht[i] = NULL;
      }
      int HashFunc(int key) {
         return key % T_S;
      }
      void Insert(int k, string v, string d) {
         int hash_v = HashFunc(k);
         HashTableEntry* p = NULL;
         HashTableEntry* en = ht[hash_v];
         while (en!= NULL) {
            p = en;
            en = en->n;
         }
         if (en == NULL) {
            en = new HashTableEntry(k, v, d);
            if (p == NULL) {
               ht[hash_v] = en;
            } else {
               p->n = en;
            }
         } else {
            en->v = v;
            en->d = d;
         }
      }
      void Remove(int k) {
         int hash_v = HashFunc(k);
         HashTableEntry* en = ht[hash_v];
         HashTableEntry* p = NULL;
         if (en == NULL || en->k != k) {
            cout<<"������ �� ������� �� ������: "<<k<<endl;
            return;
         }
         while (en->n != NULL) {
            p = en;
            en = en->n;
         }
         if (p != NULL) {
            p->n = en->n;
         }
         delete en;
         cout<<"���������� � ��������� �������"<<endl;
      }
      void SearchKey(int k) {
         int hash_v = HashFunc(k);
         bool flag = false;
         HashTableEntry* en = ht[hash_v];
         if (en != NULL) {
            while (en != NULL) {
               if (en->k == k) {
                  flag = true;
               }
               if (flag) {
                  cout <<"������ �������� �� ������ "<< k << ": " << endl;
                  cout << "������� ���������: " << en->v << endl;
                  cout << "��������: " << en->d << endl << endl;
               }
               en = en->n;
            }
         }
         if (!flag)
            cout<<" ������ �� ������� �� ������: "<<k<<endl;
      }
      ~HashMapTable() {
         delete [] ht;
      }
};
int main() {
	setlocale(LC_ALL, "Russian");
	HashMapTable hash;
   int k;
   string v, d;
   int c;
   while (1) {	
   	  cout << "\n\n\n";
      cout<<"1. ������ ������ � ����� ��������� ���������� ������"<<endl;
      cout<<"2. ����� ��������� ���������� ������ �� ������"<<endl;
      cout<<"3. ������� ������ � ��������� �� ������"<<endl;
      cout<<"4. �����"<< endl << endl;
      cout<<" �������� �������� �� ������: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<" ������� ������� ������ ���������: ";
            cin>>v;
            cout << " ������� �������� ��������: ";
            cin >> d;
            cout<<" ������� �����: ";
            cin>>k;
            hash.Insert(k, v, d);
         break;
         case 2:
            cout<<"������� ����� �������� ���������: ";
            cin>>k;
            cout << endl << endl;
            hash.SearchKey(k);
         break;
         case 3:
            cout<<"������� ����� ��������� ��� ��� ��������: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\n ������������ ���� \n";
      }
   }
   return 0;
}

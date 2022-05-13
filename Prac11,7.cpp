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
            cout<<"Ничего не найдено по номеру: "<<k<<endl;
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
         cout<<"Информация о владельце удалена"<<endl;
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
                  cout <<"Найден владелец по номеру "<< k << ": " << endl;
                  cout << "Фамилия владельца: " << en->v << endl;
                  cout << "Компания: " << en->d << endl << endl;
               }
               en = en->n;
            }
         }
         if (!flag)
            cout<<" Ничего не найдено по номеру: "<<k<<endl;
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
      cout<<"1. Ввести данные о новом владельце страхового полиса"<<endl;
      cout<<"2. Найти владельца страхового полиса по номеру"<<endl;
      cout<<"3. Удалить данные о владельце по номеру"<<endl;
      cout<<"4. Выйти"<< endl << endl;
      cout<<" Выберете действие по номеру: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<" Введите Фамилию нового владельца: ";
            cin>>v;
            cout << " Введите название компании: ";
            cin >> d;
            cout<<" Введите номер: ";
            cin>>k;
            hash.Insert(k, v, d);
         break;
         case 2:
            cout<<"Введите номер искомого владельца: ";
            cin>>k;
            cout << endl << endl;
            hash.SearchKey(k);
         break;
         case 3:
            cout<<"Введите номер владельца для его удаления: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\n Некорректный ввод \n";
      }
   }
   return 0;
}

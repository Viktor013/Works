#ifndef cl_base_h
#define cl_base_h
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cl_base
{
 string name = ""; //имя
 cl_base* parent; //указатель на головной объект

public:
	
 static cl_base* root; // корневой объект
 vector <cl_base*> children; // вектор с указателями на подчиненные объекты


 cl_base(string name, cl_base* parent); // конструктор ( с параметрами )
 
 cl_base* search(string name); // поиск по имени
 
 void print_tree(); // печатаем дерево

 cl_base(){parent=nullptr;}  //  конструктор(без параметров)
 
 void setName(string name){this->name=name;} //изменение имени
 
 void setParent(cl_base* parent){this->parent=parent;} //изменение указателя на головной объект
 
 cl_base* getParent(){return parent;} //получаем головной объект
 
 string getName(){return name;} //получаем имя
 
};
#endif





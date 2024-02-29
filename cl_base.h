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
 string name = ""; //���
 cl_base* parent; //��������� �� �������� ������

public:
	
 static cl_base* root; // �������� ������
 vector <cl_base*> children; // ������ � ����������� �� ����������� �������


 cl_base(string name, cl_base* parent); // ����������� ( � ����������� )
 
 cl_base* search(string name); // ����� �� �����
 
 void print_tree(); // �������� ������

 cl_base(){parent=nullptr;}  //  �����������(��� ����������)
 
 void setName(string name){this->name=name;} //��������� �����
 
 void setParent(cl_base* parent){this->parent=parent;} //��������� ��������� �� �������� ������
 
 cl_base* getParent(){return parent;} //�������� �������� ������
 
 string getName(){return name;} //�������� ���
 
};
#endif





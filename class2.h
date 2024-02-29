#ifndef class2_h
#define class2_h

#include "cl_base.cpp"
#include "cl_base.h"
using namespace std;

class class2:public cl_base
{
	
	public:
		class2(string name, cl_base* parent, int status);
};
#endif

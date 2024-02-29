#ifndef class3_h
#define class3_h

#include "class2.h"
#include "cl_base.h"
using namespace std;

class class3:public cl_base
{
	
	public:
		class3(string name, cl_base* parent, int status);
};
#endif

#ifndef class6_h
#define class6_h

#include "class2.h"
#include "cl_base.h"
using namespace std;

class class6:public cl_base
{
	
	public:
		class6(string name, cl_base* parent, int status);
};
#endif

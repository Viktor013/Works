#ifndef class5_h
#define class5_h

#include "class2.h"
#include "cl_base.h"
using namespace std;

class class5:public cl_base
{
	
	public:
		class5(string name, cl_base* parent, int status);
};
#endif

#ifndef cl_application_h
#define cl_application_h

#include "cl_base.h"

using namespace std;

class cl_application:public cl_base
 {
 public:
 	cl_application(cl_base* parent);
 	
 	void build_tree_objects();
 	
 	int exec_app();
 };
 
#endif


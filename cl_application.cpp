#include "cl_application.h"
#include "cl_base.h"


#include "class2.cpp"
#include "class3.cpp"
#include "class4.cpp"
#include "class5.cpp"
#include "class6.cpp"



cl_application::cl_application(cl_base* parent=nullptr):cl_base("", parent, 0)
 { 
 
 }
 
 int cl_application::build_tree_objects()
 	{
 	int class_number;
 	string one,two;
 	cin>>one;
	this->setName(one);
 	while(true)
 		{
 			
 		cin>>one;
 		if(one=="endtree")
 		 {
 		 	while(true)
 		 	{
 		 		cl_base* red = this;
 		 		cin>>one;
 		 		if(!cin) {
					return 0;
					}
				cin>>status;
				red = getChild(one, this)==nullptr?red:getChild(one, this);
				if(red!=nullptr)
				{
					red->setStatus(status);
				}
 		 	}
		 }
		 
		cin>>two>>class_number;
 		
 		
 		cl_base * par = this->search(one);	
 		
 		if(class_number==2)
 		 {
 			par->add_child(new class2(two, par, status));
		 }
		 
		else if(class_number==3)
 		 {
 			par->add_child(new class3(two, par, status));
		 }
		 
		else if(class_number==4)
 		 {
 			par->add_child(new class4(two, par, status));	
		 }
		 
		else if(class_number==5)
 		 {
 			par->add_child(new class5(two, par, status));
		 }
		 
		else if(class_number==6)
 		 {
 			par->add_child(new class6(two, par, status));
		 }
		 
 		}
 	
 	}
 
 
int cl_application::exec_app()
 {
 this->print_tree();
print_status_tree();
 
 return 0;
 }
 

 
 

 
 

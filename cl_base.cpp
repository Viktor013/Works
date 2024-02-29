#include "cl_base.h"
#include <string>
#include <iomanip>


cl_base::cl_base(string name,cl_base* parent, int status=0)
 {
	this->name=name;
	this->parent=parent;
	this->status=status;
	
 }
 cl_base* cl_base::search(string name)
 {
 	cout << "string name = " << name << endl;
 	if (this->name == name){ 
	 	return this;  
	}
	for (int i = 0; i < this->children.size(); ++i){
		cl_base * b = children[i]->search(name);
		if (b != nullptr) {
			return b;
			}	
        }
        return nullptr;              
 }
 
void cl_base::print_tree(int space, int start)
 {

 	if(!this->children.size()) {
	 return;}
	 if(start == 1){
	 cout << "Object tree\n" << setw(space) << "" << this->getName() << "\n";
}
 	for (int i = 0; i < this->children.size(); ++i){
 		cout << setw(space+4) << "" << this->children[i]->getName();
 		if (this->children[i]->children.size()){
 			
 			cout << "\n";
 			this->children[i]->print_tree(space+4, 0);
 			}
 		else {
 			cout << endl;
		 }
 		}
 	return;	
 }
 
 

 
 
 
 void cl_base::add_child(cl_base * new_child)
 {
 this->children.push_back(new_child);
}


 
 
 void cl_base::print_status_tree(int space, int start) 
 {

 	if(!this->children.size()) {
	 return;}
	 if(start == 1){
	 	cout << "The tree of objects and their readiness\n" << setw(space) << "" << this->getName();
	 	if(this->status!=0){
	 		cout << " is ready" << "\n";
	 }
	 else if(this->status==0) {
	 		cout << " is not ready\n";
	 }
}
 	for (int i = 0; i < this->children.size(); ++i){
 		cout << setw(space+4) << "" << this->children[i]->getName();
 		if(this->children[i]->status!=0) {
	 		cout << " is ready";
	 }
	 else if(this->children[i]->status==0) {
	 		cout << " is not ready";
	 }
 		if (this->children[i]->children.size()){
 			
 			cout << "\n";
 			this->children[i]->print_status_tree(space+4, 0);
 			}
 		else {
 			cout << endl;
		 }
 		}
 	return;	
 }
 
 
 

 
 
 cl_base* cl_base::setStatus(int status)
 {
 	if(parent!=0)
 	{
 		if(parent!=nullptr)
	 	{
	 		if(getTreeStatus(parent))
	 		{
	 			this->status = status;
		 	}
    	}
		else 
		{
			this->status=status;
		}			
	}
	else
	{
		this->status = status;
		if(children.size()!=0);
		{
			for(auto& i : children)
			{
				i->setStatus(status);
			}
		}
	}
	
 }
 
 
 
 bool cl_base::getTreeStatus(cl_base* T)
 {
 	if(T->parent!=nullptr&&T->getStatus()==0)
 	{
 		return false;
 	}
 	else if(T->parent==nullptr || T==nullptr )
 	{
 		return true;
	}
	else 
	{
		return getTreeStatus(T->parent);
	}
	bool G;
	G = (T->getStatus()!=0);
 	if(T->parent!=nullptr&& G!=false)
 	{
 		G = getTreeStatus(T->parent);
	}
	return G;
 }
 
 
 
 cl_base* cl_base::getChild(string name, cl_base* parent)
 {
 	for(auto &i: parent->children)
 	{
 		if(i->children.size()!=0)
 		{
 			if(getChild(name, i)!=nullptr)
 			{
 				return getChild(name, i);
			}
		}
		if(i->getName()==name)
		{
			return i;
		}
	}
	return nullptr;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

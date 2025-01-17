#include <iostream>
#include <string>

using namespace std;

// Anyone may ask a Child for their name, but 
// only the Mother and the Child may change the name.
class Child
{
private:
	string name_;
protected:
	virtual void setName(string name)
	{ 
		name_ = name; 
	}
	friend class Mother;
public:
	const string& getName(void) { return name_; }
	Child(string name) :name_(name){ }
	Child(){}
};

class ChildsChild :public Child
{
public:
	ChildsChild(){}
	friend class ChildsChildFriend;
};

class ChildsChildFriend
{
public:
	ChildsChildFriend(){ cout <<"Inside Ctor" << endl; }
	void setN(ChildsChild& aChild, string name)
	{
		aChild.setName(name);
	}
};


class Mother
{
public:
	void setNameOfChile(Child& aChild, string childName)
	{
		aChild.setName(childName);
	}
};


int main(void) 
{ 
	Child aChild("Bruce");
	ChildsChild aChildChild;
	Mother aMother;
	
	//cout << "Child name is :" << aChild.getName() << endl;
	//cout << "Mother is about to change the child name from " 
	//	<< aChild.getName() << " to Pumba" << endl;
	//aMother.setNameOfChile(aChild, "Pumba");
	//cout << "Now the Child name is :" << aChild.getName() << endl;

	ChildsChildFriend aCCFreind;
	cout << "Setting the name of Child by Child's Child's Friend" << endl;
	aCCFreind.setN(aChildChild, "Doggy");
	cout << "Now the Child name is :" << aChildChild.getName() << endl;


	return 0; 
}


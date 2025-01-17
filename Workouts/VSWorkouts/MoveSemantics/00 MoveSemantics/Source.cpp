#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Resource
{
private:
	std::string name;
public:
	// Constructor
	Resource(std::string n) : name(n) { cout << "Constructing " << name << endl; }
	// Copy Constructor
	Resource(const Resource& r) : name(r.name) { cout << "Copy constructing " << name << endl; }
	// Copy Assignment Operator
	Resource& operator=(const Resource& r)
	{
		name = r.GetName();
		cout << "Copy assigning " << name << endl;
		return *this;
	}
	// Move Constructor 
	// We are taking resource as just rvalue reference. Not as const rvalue reference.
	// This is because, we are going the change the temporary. We are steeling the guts form temporary.
	Resource(Resource&& r) : name(std::move(r.name)) { cout << "Move constructing " << name << endl; }
	// Move Assignment Operator
	// We are taking resource as just rvalue reference. Not as const rvalue reference.
	// This is because, we are going the change the temporary. We are steeling the guts form temporary.
	Resource& operator=(Resource&& r)
	{
		cout << "Move assigning " << name << endl;
		if (this != &r)
		{
			name = std::move(r.name);
			r.name.clear();
		}
		return *this;
	}
	// Destructor
	~Resource(void) { cout << "destructing " << name << endl; }
	bool Resource::operator>(const Resource& r) { return name > r.name; }
	bool Resource::operator<(const Resource& r) { return name < r.name; }
	bool Resource::operator==(const Resource& r) { return name == r.name; }
	std::string GetName() const { return name; }
};

int main(void)
{
	Resource r("local");
	cout << "------------------------------" << endl;
	vector<Resource> resources;
	resources.push_back(r);
	cout << "------------------------------" << endl;
	resources.push_back(Resource("first"));
	cout << "------------------------------" << endl;
	std::for_each(begin(resources), end(resources),
		[](const Resource& res){cout << res.GetName() << endl; }
	);
	cout << endl;

	return 0;
}
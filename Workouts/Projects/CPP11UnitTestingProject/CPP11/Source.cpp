#include <memory>
#include <iostream>

using namespace std;

void Fun1(unique_ptr<int> up) { cout << " Value of up = " << *up << endl; }
void Fun2(unique_ptr<int>& up) { cout << " Value of up = " << *up << endl; }

auto main(void)->int
{

	unique_ptr<int> up1 = unique_ptr<int>(new int(10));

	//2. Assigning the unique pointer is not allowed
	//unique_ptr<int> up2 = up1;

	//3. Copy construction is not allowed. So cannot pass by value to a function 
	//Fun1(up1);

	//4. But can pass by reference
	Fun2(up1);

	return 0;
}
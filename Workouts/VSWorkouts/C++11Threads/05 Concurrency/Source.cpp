#include <iostream>
#include <thread>

using namespace std;
/************************************************************************
				Passing arguments to a thread function
************************************************************************/

/************************************************************************
	- By default the arguments are copied into internal storage, where they 
	can be accessed by the newly created thread of execution, even if the 
	corresponding parameter in the function is expecting a reference.
************************************************************************/

void doubleData(int w, int& data)
{
	data = w * 2;
}
void displayData(int data)
{
	cout << "Value is :" << data << endl;
}
void thisWillNotUpdateData(int w)
{
	int data = 0;
	/************************************************************************
		- Although thisWillNotUpdateData expects the second parameter to be 
		passed by reference, the std::thread constructor doesn’t know that;
		it's oblivious to the types of the arguments expected by the function
		and blindly copies the supplied values.	When it calls thisWillNotUpdateData, 
		it will end up passing a reference to the internal copy of data and 
		not a reference to data itself.
		- Consequently, when the thread finishes, these updates will be discarded 
		as the internal copies of the supplied arguments are destroyed, and 
		displayData will be passed an unchanged data rather than a correctly 
		updated version.
	************************************************************************/
	std::thread t(doubleData, w, data);
	t.join();
	displayData(data);
}

void thisWillUpdateData(int w)
{
	int data = 0;
	thread temp(doubleData, w, ref(data));
	temp.join();
	displayData(data);
}

int main(void)
{
	thisWillNotUpdateData(10);
	thisWillUpdateData(10);

	return 0;
}
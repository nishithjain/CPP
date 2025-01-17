#include <iostream>

using namespace std;

int main(void)
{
	int i = 5;
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	
	arr[i] = ++i;

	cout << arr[i] << endl;

	return 0;
}
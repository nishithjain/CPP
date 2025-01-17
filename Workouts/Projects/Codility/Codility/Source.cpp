#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int solution(int A, int B) 
{
	int count = 0;
	if (A > B) return -1;
	if (A < INT_MIN || A> INT_MAX || B < INT_MIN || B > INT_MAX) return -1;

	return ((int)(sqrt(abs(B))) - (int)ceil(sqrt(abs(A))) + 1);
}

int main(void) 
{ 
	cout << solution(4, 17) << endl;
	cout << solution(4, 16) << endl;
	cout << solution(25, 100) << endl;
	cout << solution(26, 100) << endl;



	return 0; 
}
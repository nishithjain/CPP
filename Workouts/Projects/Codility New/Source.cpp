//def isPrime(num) :
//if num in[2, 3] : return True
//elif num < 2 : return False
//for i in[2] + range(3, int(sqrt(num)), 2) :
//if not num % i : return False
//return True

#include <iostream>
#include <climits>
#include <math.h>
using namespace std;
#include <assert.h>

//bool isPrime(int num)
//{
//	for (int i = 2; i <= sqrt(num); ++i)
//		if (num%i == 0)
//			return false;
//	return true;
//}
//
//
//int solution(int A, int B) 
//{
//	if (A < 0 || B < 0) return -1;
//	if (A > B) return -1;
//	if (B > 500000) return -1;
//	int numOfPrims = 0;
//	for (int i = A; i <= B; i++)
//	{
//		if (isPrime(i))
//			numOfPrims++;
//	}
//
//	return numOfPrims;
//}



double myCubeRoot(int x)
{
	double result = 0;
	if (x > 0)
	{
		result = pow(x, 1 / 3.0);
	}
	else if (x < 0)
	{
		result = -pow(abs(x), 1 / 3.0);
	}
	if (result)
	{
		int roundedResult = int(round(result));
		cout << roundedResult << endl;
		if (pow(roundedResult, 3) == x)
			return roundedResult;
		else
			return result;
	}
	return 0;
}

int solution(int A, int B)
{
	if (A < -INT_MIN)
		return -1;
	if (B > INT_MAX)
		return -1;
	if (A > B)
		return -1;
	int cubeRootOfA = int(ceil(myCubeRoot(A)));
	int cubeRootOfB = int(floor(myCubeRoot(B)));

	if (cubeRootOfB >= cubeRootOfA)
		return cubeRootOfB - cubeRootOfA + 1;

	return 0;
}

int main(void)
{
	//cout << solution(11, 19) << endl;
	//cout << solution(1, 5) << endl;
	//cout << solution(-1, 5) << endl;
	//cout << solution(350000, 500001) << endl;
	cout<<solution(8, 65)  <<endl;
	cout<<solution(8, 64)  <<endl;
	cout<<solution(9, 12)  <<endl;
	cout<<solution(8, 12)  <<endl;
	cout<<solution(8, 8)   <<endl;
	cout<<solution(0, 1)   <<endl;
	cout<<solution(0, 0)   <<endl;
	cout<<solution(-1, 0)  <<endl;
	cout<<solution(-1, 1)  <<endl;
	cout<<solution(-8, -2) <<endl;
	cout<<solution(-65, -8)<<endl;
	cout<<solution(-64, -8)<<endl;

	assert(solution(8, 65) == 3);
	assert(solution(8, 64) == 3);
	assert(solution(9, 12) == 0);
	assert(solution(8, 12) == 1);
	assert(solution(8, 8) == 1);
	assert(solution(0, 1) == 2);
	assert(solution(0, 0) == 1);
	assert(solution(-1, 0) == 2);
	assert(solution(-1, 1) == 3);
	assert(solution(-8, -2) == 1);
	assert(solution(-65, -8) == 3);
	assert(solution(-64, -8) == 3);




	return 0;
}
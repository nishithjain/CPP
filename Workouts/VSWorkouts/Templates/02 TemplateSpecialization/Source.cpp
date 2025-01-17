#include <iostream>
#include <string>
using namespace std;

template <class T> 
class tType 
{
public:
	T value;
	T operator=(T val){ value = val; return value; }
	tType<T> operator=(tType<T> &val){ value = val.value; return *this; }
	operator T(){ return value; }
};

template<>
class tType<string>
{
public:
	string value;
	string operator=(string val) { value = val; return value; }
	//operator tType(){ return value; }
};

template <class T> bool operator==(const T val, tType<T>& tval){cout << "In Operator 5 == x: " << endl; return(val == tval.value); }
template <class T> bool operator==(tType<T>& tval, const T val){cout << "In Operator x == 5: " << endl; return(val == tval.value); }
template <class T> bool operator!=(const T val, tType<T>& tval){cout << "In Operator x != 6: " << endl; return(val != tval.value); }
template <class T> bool operator!=(tType<T>& tval, const T val){cout << "In Operator 6 != x: " << endl; return(val != tval.value); }
template <class T> T operator+(const T val, tType<T>& tval){	cout << "In Operator 5 + x: " << endl; return(val + tval.value); }
template <class T> T operator+(tType<T>& tval, const T val){	cout << "In Operator x + 5: " << endl; return(val + tval.value); }
template <class T> T operator-(const T val, tType<T>& tval){	cout << "In Operator 5 - x: " << endl; return(val - tval.value); }
template <class T> T operator-(tType<T>& tval, const T val){	cout << "In Operator x - 5: " << endl; return(val - tval.value); }
template <class T> T operator*(const T val, tType<T>& tval){	cout << "In Operator 5 * x: " << endl; return(val * tval.value); }
template <class T> T operator*(tType<T>& tval, const T val){	cout << "In Operator x * 5: " << endl; return(val * tval.value); }
template <class T> T operator/(const T val, tType<T>& tval){	cout << "In Operator 5 / x: " << endl; return(val / tval.value); }
template <class T> T operator/(tType<T>& tval, const T val){	cout << "In Operator x / 5: " << endl; return(val / tval.value); }

int main(void)
{
	{
		tType<int> x;
		x = 5;

		if (x == 5) cout << "Equal" << endl;
		if (x != 6) cout << "Not Equal" << endl;
		cout << "x + 5= " << x + 5 << endl;
		cout << "x - 5= " << x - 5 << endl;
		cout << "x * 5= " << x * 5 << endl;
		cout << "x / 5= " << x / 5 << endl;

		if (5 == x) cout << "Equal" << endl;
		if (6 != x) cout << "Not equal" << endl;
		cout << "5 + x= " << 5 + x << endl;
		cout << "5 - x= " << 5 - x << endl;
		cout << "5 * x= " << 5 * x << endl;
		cout << "5 / x= " << 5 / x << endl;
	}

	{
		tType<double> aDouble;
		aDouble = 10.22;

		if (aDouble == 1.5) cout << "Equal" << endl;
		if (aDouble != 6) cout << "Not Equal" << endl;
		cout << "aDouble + 1.5= " << aDouble + 1.5 << endl;
		cout << "aDouble - 1.5= " << aDouble - 1.5 << endl;
		cout << "aDouble * 1.5= " << aDouble * 1.5 << endl;
		cout << "aDouble / 1.5= " << aDouble / 1.5 << endl;

		if (1.5 == aDouble) cout << "Equal" << endl;
		if (6 != aDouble) cout << "Not equal" << endl;
		cout << "1.5 + aDouble= " << 1.5 + aDouble << endl;
		cout << "1.5 - aDouble= " << 1.5 - aDouble << endl;
		cout << "1.5 * aDouble= " << 1.5 * aDouble << endl;
		cout << "1.5 / aDouble= " << 1.5 / aDouble << endl;
	}

	return 0;
}
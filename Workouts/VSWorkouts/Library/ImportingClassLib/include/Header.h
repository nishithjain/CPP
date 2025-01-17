#ifdef MYFIRSTDLLEXPORT
#define MYDLLFUNCTION __declspec(dllexport) 
#else
#define MYDLLFUNCTION __declspec(dllimport) 
#endif

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

namespace myDLLClass
{
	class MyDllClass
	{
	public:
		MYDLLFUNCTION MyDllClass();
		MYDLLFUNCTION ~MyDllClass();
		static MYDLLFUNCTION void justPrintHello(string passString);
	private:

	};
}
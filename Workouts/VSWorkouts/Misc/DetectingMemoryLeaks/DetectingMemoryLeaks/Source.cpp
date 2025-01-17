#define  _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

using namespace std;


int main(void)
{
#ifdef _DEBUG
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF;	// Turn on leak-checking bit
	_CrtSetDbgFlag(flag);
	_CrtSetBreakAlloc(143);			// Comment or uncomment on need basis
#endif

	int* intPtr = new int;
	//delete(intPtr);
	_CrtDumpMemoryLeaks();
	return 0;
}
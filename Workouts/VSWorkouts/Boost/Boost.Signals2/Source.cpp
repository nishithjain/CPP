#include <iostream>
#include <boost/signals2.hpp>

using namespace std;
using namespace boost;
using namespace signals2;


void third()
{
	cout << "Third" << endl;
}

int main(void)
{
	//{
	//	signal<void()> s;
	//	s.connect(third);

	//	{
	//		auto c = s.connect(1, [](){cout << "First" << endl; });
	//		scoped_connection sc(c);
	//		s.connect(0, [](){cout << "Second" << endl; });
	//		s();
	//	}

	//	cout << "++++++++++++++++++" << endl;
	//	s.disconnect(third);
	//	s();
	//}
	return 0;
}
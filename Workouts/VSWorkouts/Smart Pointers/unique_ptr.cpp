#include <iostream>
#include <memory>

using namespace std;

class Hen
{
public:
	int id_;
	float avgEggs_;
	Hen(int ID, float AvgEggs) : id_{ ID }, avgEggs_{ AvgEggs }  { }
	~Hen() { cout << "Killing Hen\n"; }
};
struct HenDeleter
{
	void operator()(Hen* b) 
	{ 
		cout << "In DELETER\n";
		delete b; 
	}
};

auto updateHen(unique_ptr<Hen, HenDeleter> ptr) -> unique_ptr<Hen, HenDeleter>
{
	ptr->avgEggs_ += 2.2f;
	return ptr;
}

int main(void)
{
	auto hen = unique_ptr<Hen, HenDeleter>(new Hen(5, 6.7f));

	cout << "Average Eggs : " << (*hen.get()).avgEggs_ << endl;
	hen = updateHen(move(hen));
	cout << "Average Eggs : " << (*hen.get()).avgEggs_ << endl;

	return 0;
}
#include<iostream>
using namespace std;
class base
{
	private:
		int a;
	public:
		base()
		{
			cout<<"in base"<<endl;
		}
};

class derived:base
{
	private:
		base b;
	public:
		derived()
		{
			base();
			cout<<"in derived"<<endl;
		}
};

int main()
{
	derived d;
	return 0;
}

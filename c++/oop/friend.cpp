#include<iostream>
using namespace std;
class a;

class b
{
	public:
		void func(a & x)
		{
			cout<<x.avar<<endl;
		}
};
class a
{
	private:
		int avar;
	public:
		a()
		{
			avar=9;
		}
		friend void b::  func(a & x);
};

void b::func(a &x)
{
	cout<<"a:avar="<<x.avar<<endl;
}

int main()
{
	a aobj;
	b bobj;
	bobj.func(aobj);
	return 0;
}
		

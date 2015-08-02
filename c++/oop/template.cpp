#include<iostream>
#include <typeinfo>
using namespace std;

template<class T>
class type
{
	private:
		T var;
	public:
		//type(T const x)var(x);
		void show()
		{
			cout<<typeid(var).name()<<endl;
		}
};	
			
	
int main()
{
	type<int> t;
	t.show();
	type<float> t1;
	t1.show();
	type<char> t2;
	t2.show();
	type<bool> t3;
	t3.show();
	
	return 0;
}

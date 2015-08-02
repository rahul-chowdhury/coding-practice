#include<iostream>
using namespace std;
class a
{
static int count;
public:
a(){count++;}
~a(){count--;}
void display()
{cout<<count<<endl;}
};
int a::count=0;
int main()
{
a a1;
a1.display();
{
a a2;
a1.display();
a2.display();
}
a1.display();
}


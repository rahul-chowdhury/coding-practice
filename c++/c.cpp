#include<iostream>
using namespace std;

class a
{
public:
a()
{
cout<<"a"<<endl;
}
};

class b :public a
{
public:
b():a()
{
cout<<"b"<<endl;
}
};
main()
{
b B;
}

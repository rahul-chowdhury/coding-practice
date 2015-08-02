#include<iostream>
using namespace std;

class A
{
public:virtual void f()
{
cout<<"in A"<<endl;
}
A(){cout<<"cons of a"<<endl;}
 ~A(){cout<<"dest of a"<<endl;}

};

class B:public A
{
public:virtual void f()
{
cout<<"in B"<<endl;
}
B(){cout<<"cons of b"<<endl;}
~B(){cout<<"dest of b"<<endl;}
};

int main()
{
//B ob;
B *obj =new B();
delete obj;

}

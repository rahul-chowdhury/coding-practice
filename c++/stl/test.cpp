#include<set>
#include<iostream>
#define tr(s,i1) for(i1=s.begin();i1!=s.end();i1++)
using namespace std;

int main()
{
set <int> s;
int second;
for(int i=1;i<=100;i++)
s.insert(i);
set<int>:: iterator i1,i2;
i1=s.find(10);
i2=s.find(100);
s.erase(i1,i2);
//for(i1=s.begin();i1!=s.end();i1++)
tr(s,i1){
cout<<*i1<<endl;
}
return 0;
}

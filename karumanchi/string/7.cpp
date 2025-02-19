#include<bits/stdc++.h>
using namespace std;

void string_reverse(string *s)
{
	int end=s->length()-1,start=0;
	while(start<end)
	{
		(*s)[start] ^=(*s)[end];
		(*s)[end] ^= (*s)[start];
		(*s)[start] ^=(*s)[end];
		start++;
		end--;
	}
}




void reverse_every_word(string *s)
{
	int length=s->length(),i=0,start,end;
	if(length==0 || length==1)
		return;
	while(i<length)
	{
		while(i<length && (*s)[i]==' ')
			i++;
		if(i==length)
			break;
		start=i;
		while(i<length && (*s)[i]!=' ')
			i++;
		end=i-1;
		while(start<end)
		{
			(*s)[start] ^=(*s)[end];
			(*s)[end] ^= (*s)[start];
			(*s)[start] ^=(*s)[end];
			start++;
			end--;
		}
	}
}

int main()
{
	string s= "            radish       is        a         pear               ";
	reverse_every_word(&s);
	cout<<s<<endl;
	return 0;
}

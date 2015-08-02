#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int iter,red,blue;
	scanf("%lld",&iter);
	long long int girls[iter],tiles[iter];
	for(long long int i=0;i<iter;i++)
	{
        scanf("%lld",&girls[i]);
        scanf("%lld",&tiles[i]);
		
		
	}
	for(long long int i=0;i<iter;i++)
	{
        blue=0;
        red=0;
        long long int red_left=tiles[i],j=1;
		while(j<=girls[i] && red_left>=2)
        {
                 //printf("%lld %lld %lld\n",red_left,red,blue);
            if(red_left%2==0)
                {
                blue++;
            }
            else
                {
                red++;
            }
            if(red_left%2==0)
                {red_left=red_left/2;}
            else
                {red_left=red_left/2+1;}
		j++;
            
		 
        }
        if(red+blue!=girls[i])
        {
       red = girls[i]-blue;}
         printf("%lld %lld\n",red,blue);
		
	}	  
    return 0;
}


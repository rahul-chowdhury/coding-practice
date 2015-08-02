#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//From Rosetta code the LCS routine. 
char* lcs(const char *a, const char *b, char *out)
{
	int longest = 0;
	
    int match(const char *a, const char *b, int dep) 
    {
		if (!a || !b) return 0;
		if (!*a || !*b) {
			if (dep <= longest) return 0;
			out[ longest = dep ] = 0;
			return 1;
		}
 
		if (*a == *b)
			return match(a + 1, b + 1, dep + 1) && (out[dep] = *a);
 
		return	match(a + 1, b + 1, dep) + 
			match(strchr(a, *b), b, dep) +
			match(a, strchr(b, *a), dep);
	}
	return match(a, b, 0) ? out : 0;
}
 char s[100000],t[100000],u[100000];
int main()
{
    int t1;
    scanf("%d",&t1);
    while(t1--)
        {
        scanf("%s%s",s,t);
        lcs(s,t,u);
        int s1=strlen(s);
        int u1=strlen(u);
        if(s1==u1)
            printf("0\n");
        else
        printf("%d\n",strlen(s)-strlen(u));
    }
	return 0;
}

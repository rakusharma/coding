/*all recurrsion functions here */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*recurrsion function to reverse string*/
void rev(char *s, int i, char *p, int l)
{
		if (s[1] != '\0') rev(s + 1, i + 1, p, l);
		p[l - i - 1]= s[0];
}



int main()
{
		char *s = "hello world";
		char *r = (char *)malloc(strlen(s) + 1);
		int i = 0;
		rev(s, i, r, strlen(s));
		printf("strings %s %s %d\n", s, r, sizeof(*r));
		free(r);

}


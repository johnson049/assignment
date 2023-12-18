#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int l=0;
	printf("enter the first string\n");
	scanf("%s",str);
	int h=strlen(str)-1;
	while(h>1)
	{
		if (str[l++]!=str[h--])
		{
			printf("%s is not a palindrome\n",str);
			return 0;
		}
	printf("%s,is a palindrome\n",str);
	}	
}

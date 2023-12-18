#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20];
	char str2[20];
	int value;
	printf("enter the first string\n");
	scanf("%s",str1);
	printf("enter the second string\n");
	scanf("%s",str2);
	value=strcmp(str1,str2);
	if(value==0)
		printf("strings are same\n");
	else
		printf("strings are not same\n");
}

#include<stdio.h>
#include<string.h>
void check_palindrome(char str[])
{
int i,j,k,pos,flag;
char new_str[20];
int len=strlen(str);
for(i=0;i<len;)
{	
	j=0;flag=0;pos=i;
	while(pos<len-1 && str[pos]!=' ')
	{
		new_str[j]=str[pos];
		j++;pos++;
	}
	for(k=0;k<j/2;k++)
	{
		if(new_str[k]!=new_str[j-k-1])
		flag++;
	}
	if(flag==0)
	{
		printf("There exists a word which is palindrome\n");
		return;
	}
	i=i+j+1;
}
printf("There does not exists any palindrome word\n");
}
int main()
{
char str[100];
printf("Enter a string\n");
fgets(str,99,stdin);
check_palindrome(str);
return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
int search(char a[])
{
	int i;
	int num=0;
	for(i=0;i<(int)strlen(a);i++)
	{
		if(a[i]=='1')num++;
	}
	return num;
}
int main()
{
	int n,i,j,k;
	int max=0;
	scanf("%d",&n);
	char *a=(char *)malloc(n+1);
	char *b=(char *)malloc(n+1);
	for(i=0;i<n;)
	{
		scanf("%c",&a[i]);
		if(a[i]=='0'||a[i]=='1')i++;
	}
	a[i]='\0';
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			strcpy(b,a);
			for(k=i;k<=j;k++)
			{
				if(b[k]=='1')b[k]='0';
				else if(b[k]=='0')b[k]='1';
			}
			if(max<search(b))max=search(b);
		}
	}
	for(i=0;i<n;i++)
	{
		strcpy(b,a);
		if(b[i]=='0')b[i]='1';
		else if(b[i]=='1')b[i]='0';
		if(max<search(b))max=search(b);
	}
	printf("%d",max);
	return 0;
} 

#include<iostream>

using namespace std;
int sum(int *a,int lenth)
{
	int k;
	int tem=0;
	for(k=0;k<lenth;k++)
	{
		tem+=a[k];
	}
	return tem;
}
void prin(int *a,int lenth)
{
	int k;
	for(k=lenth-1;k>=0;k--)
	{
		cout<<a[k];
	}
}
int main()
{
	int m,s;
	int max=-1,min=-1;
	cin>>m>>s;
	if(m==1&&s==0)
	{
		cout<<0<<" "<<0;
	}
	else if(s<1||m*9<s)
	{
		cout<<min<<" "<<max;
	}
	else
	{
		int a[101];
		int i,j;
		for(i=0;i<m;i++)
		{
			a[i]=0;
		}
		a[i-1]++;
		for(i=0;i<m;i++)
		{
			for(j=0;j<9;j++)
			{
				if(sum(a,m)==s)
				{
					break;
				}
				else a[i]++;
			}
			if(sum(a,m)==s)
				{
					break;
				}
		}
		prin(a,m);
		cout<<" ";
		for(i=0;i<m;i++)
		{
			a[i]=9;
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<9;j++)
			{
				if(sum(a,m)==s)
				{
					break;
				}
				else a[i]--;
			}
			if(sum(a,m)==s)
				{
					break;
				}
		}
		prin(a,m);
	}
	return 0;
}

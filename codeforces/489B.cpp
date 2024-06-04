#include<iostream>
#include<math.h>
using namespace std;

void px(int *a,int lenth)
{
	int i,j;
	int temlenth=lenth;
	int tem;
	for(i=0;i<lenth-1;i++)
	{
		for(j=0;j<temlenth-1;j++)
		{
			if(a[j]>a[j+1])
			{
				tem=a[j];
				a[j]=a[j+1];
				a[j+1]=tem;
			}
		}
		temlenth--;
	}
}
int main()
{
	int n,m;
	int a[101],b[101];
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>b[i];
	}
	i=0;
	j=0;
	int sum=0;
	px(a,n);
	px(b,m);
	while(i<n&&j<m)
	{
		if(abs(a[i]-b[j])<=1)
		{
			sum++;
			i++;
			j++;
		}
		else if(a[i]>b[j])
		{
			j++;
		}
		else if(a[i]<b[j])
		{
			i++;
		}
	}
	cout<<sum;
}


//配对题   先排序   然后从小的开始  有配对就配对   没配对就小的角标++去接近大的 

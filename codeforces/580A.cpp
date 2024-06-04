#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int b[100001];//题目提示范围为10的五次方，就大开小用，别直接b[n]，或动态创建数组，可能会limit exceeded 
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}

	int max=1;
	for(i=0;i<n;i++)
	{
		int tem=1;
		for(j=i;j<n-1;j++)
		{
			if(b[j]<=b[j+1]) tem++;
			else break;	
		}
		if(tem>max) max=tem;
	}
	cout<<max;
	return 0;
}

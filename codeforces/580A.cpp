#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int b[100001];//��Ŀ��ʾ��ΧΪ10����η����ʹ�С�ã���ֱ��b[n]����̬�������飬���ܻ�limit exceeded 
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

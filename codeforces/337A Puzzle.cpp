#include<iostream>
//#include<algorithm>������ĺ��� 
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int* a=new int [m];  //��̬���� 
	int i=0,j=0;
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	
	for(i=0;i<m;i++)  //ѡ������  ð������һ����a[i]��a[i+1]�ȣ�����дa[i]��a[j] 
	{
		int min=i;
		for(j=i;j<m;j++)
		{
			if(a[j]<=a[min])min=j;
		}
		swap(a[i],a[min]);
	}
	
	int min1=996;
	for(i=0;i<=m-n;i++)
	{
		
		if(a[i+n-1]-a[i]<=min1)min1=(a[i+n-1]-a[i]);
		
	}
	cout<<min1;
	return 0;
}

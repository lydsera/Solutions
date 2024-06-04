#include<iostream>
using namespace std;
int mymax(int a,int b,int c)
{
	int max=0;
	if(a>max)max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	return max;
}
int main()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int *f=new int [n+1];
	f[0]=0;
	int i;
	for(i=1;i<n+1;i++)
	{
		int d,e,g;
		if(i-a<0)d=0;
		else d=i-a;
		if(i-b<0)e=0;
		else e=i-b;
		if(i-c<0)g=0;
		else g=i-c;
		//if(i-a>=0||i-b>=0||i-c>=0){
		
		f[i]=mymax(f[d],f[e],f[g]);
		if(f[i]!=0||i-a==0||i-b==0||i-c==0)f[i]++;
	//}
		//else f[i]=0;
	}
	cout<<f[n];
	return 0;
}

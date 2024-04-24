#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string N;//数据为10的100次方，无法用任何整型类型存储
    cin>>N;
    int sum=0;
    for(int i=0;i<N.length();i++)
    {
        sum+=N[i]-'0';
    }
    stack<int> s;
    if(sum==0) cout<<"zero";//特殊值
    while(sum>0)
    {
        s.push(sum%10);
        sum/=10;
    }
    while(!s.empty())
    {
        switch(s.top())
        {
            case 0:cout<<"zero";break;
            case 1:cout<<"one";break;
            case 2:cout<<"two";break;
            case 3:cout<<"three";break;
            case 4:cout<<"four";break;
            case 5:cout<<"five";break;
            case 6:cout<<"six";break;
            case 7:cout<<"seven";break;
            case 8:cout<<"eight";break;
            case 9:cout<<"nine";break;
        }
        s.pop();
        if(!s.empty())cout<<" ";
    }
}
#include<iostream>
#include<stack>

using namespace std;

// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     a=a+b;
//     stack<int> s;
//     if(a==0) cout<<0;
//     if(a<0)
//     {
//         cout<<"-";
//         a=-a;
//     } 
//     while(a!=0)
//     {
//         s.push(a%10);
//         a/=10;
//     }
//     int tmp=s.size()%3;
//     while(tmp!=0)
//     {
//         tmp--;
//         cout<<s.top();
//         s.pop();
//         if(tmp==0&&!s.empty()) cout<<",";
//     }
//     while(!s.empty())
//     {
//         cout<<s.top();
//         s.pop();
//         tmp++;
//         if((tmp%=3)==0&&!s.empty()) cout<<",";
//     }
// }

//不用这么麻烦，数字当作字符即可
int main()
{
    int a,b;
    cin>>a>>b;
    a=a+b;
    stack<char> s;
    int tmp=0;
    if(a<0)
    {
        cout<<"-";
        a=-a;
    }
    do
    {
        s.push(a%10+'0');//把数字转换为数字对应的ascii码
        a/=10;
        tmp++;
        if((tmp%=3)==0&&a!=0) s.push(',');
    }while(a!=0);
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
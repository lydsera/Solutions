#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int,double,greater<int>> m;
    int K;
    cin>>K;
    while(K--)
    {
        int N;
        double a;
        cin>>N>>a;
        // m[N]=a;//同行可能有一样key
        if(m.find(N)==m.end()) m[N]=a;
        else m[N]+=a;
    }
    cin>>K;
    while(K--)
    {
        int N;
        double a;
        cin>>N>>a;
        if(m.find(N)==m.end()) m[N]=a;
        else m[N]+=a;
    }
    /*
    cout<<m.size();//为0系数不打印
    for(auto it : m)
        printf(" %d %.1lf",it.first,it.second);
    */
    int len=m.size();
    for(auto it : m)
        if(it.second==0) len--;
    cout<<len;
    for(auto it : m)
        if(it.second!=0)
            printf(" %d %.1lf",it.first,it.second);
}
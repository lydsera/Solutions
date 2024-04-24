#include<iostream>

using namespace std;

int main()
{
    int M;
    cin>>M;
    int min=23*60*60+59*60+59;
    int max=0;
    string first,last;
    while(M--)
    {
        string tmp,in,out;
        cin>>tmp>>in>>out;
        /*转成秒去比大小就好了，
        一开始以为一个人可以多次进进出出，开锁上锁的人可能有多个
        （比如某中间某一时段就没人，而非一定到晚上）
        结果没那么复杂
        */
        int tmp1=(in[0]-'0')*36000+(in[1]-'0')*3600+(in[3]-'0')*600+(in[4]-'0')*60+(in[6]-'0')*10+(in[7]-'0');
        int tmp2=(out[0]-'0')*36000+(out[1]-'0')*3600+(out[3]-'0')*600+(out[4]-'0')*60+(out[6]-'0')*10+(out[7]-'0');
        if(tmp1<min)
        {
            min=tmp1;
            first=tmp;
        }
        if(tmp2>max)
        {
            max=tmp2;
            last=tmp;
        }
    }
    cout<<first<<" "<<last;
}


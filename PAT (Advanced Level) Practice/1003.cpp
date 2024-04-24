#include<iostream>
#include<vector>

using namespace std;

const int INF=0x7fffffff;

class edge{
    public:
    int len;//边的长度
    int nxt;//边的目的地，即下一个节点
};

int N,M,C1,C2;
vector<vector<int>> prio;//记录某个点在最短路径上的上一个节点（可有多个）


int cal(int pos)
{
    if(pos==C1) return 1;
    int tmp=0;
    for(auto p:prio[pos])
    {
        tmp+=cal(p);
    }
    return tmp;
}

int main()
{
    cin>>N>>M>>C1>>C2;
    vector<int> team_len;
    vector<vector<edge>> edges(N);//下标表示对应节点，记录每个节点出发的边
    prio=vector<vector<int>>(N);//在外面初始化会错
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        team_len.push_back(tmp);
    }
    while(M--)
    {
        int a,b,len;
        cin>>a>>b>>len;
        edge tmp;
        tmp.nxt=b;
        tmp.len=len;
        edges[a].push_back(tmp);
        edge tmp1;
        tmp1.nxt=a;
        tmp1.len=len;
        edges[b].push_back(tmp1);
         
    }
    vector<int> dist(N,INF);//记录起点到每个节点的最短距离
    vector<bool> flag(N,false);//dijkstra算法的标记，每次标记距离最近的节点为true
    dist[C1]=0;//起点到起点的距离为0
    flag[C1]=true;
    int cnt=0;//cnt==N时每个节点都已被标记为true
    int tmp=C1;//此时被标记的节点，遍历该节点出去的边，松弛dist
    while(cnt<N)
    {
        for(auto e:edges[tmp])
        {
            if(e.len+dist[tmp]<dist[e.nxt])//松弛
            {
                dist[e.nxt]=e.len+dist[tmp];
                prio[e.nxt]=vector<int>();
                prio[e.nxt].push_back(tmp);
            }
            else if(e.len+dist[tmp]==dist[e.nxt])
            {
                prio[e.nxt].push_back(tmp);
            }
        }
        int min=INF;
        int min_pos=-1;
        for(int i=0;i<N;i++)
        {
            if(flag[i]) continue;
            if(dist[i]<min)
            {
                min=dist[i];
                min_pos=i;
            }
        }
        if(min_pos==-1) break;
        flag[min_pos]=true;
        int sum=0;
        for(auto it:prio[min_pos])
        {
            if(team_len[it]>sum) sum=team_len[it];
        }
        team_len[min_pos]+=sum;
        tmp=min_pos;
        cnt++;
    }
    int ans=cal(C2);//多少最短路径
    cout<<ans<<" "<<team_len[C2];

}
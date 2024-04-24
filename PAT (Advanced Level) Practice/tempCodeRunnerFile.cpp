#include<iostream>
#include<vector>

using namespace std;

int N,M;
vector<vector<int>> nodes;
vector<int> ans;
int level=0;
int height=0;

void dfs(int node)
{
    if(nodes[node].size()==0)
    {
        ans[level]++;
        return ;
    }
    for(auto child:nodes[node])
    {
        level++;
        if(level>height) height=level;
        dfs(child);
        level--;
    }
}

int main()
{
    cin>>N;
    if(N==0) return 0;
    nodes=vector<vector<int>>(N);
    ans=vector<int>(N,0);
    cin>>M;
    while(M--)
    {
        char root[2];
        cin>>root;
        int pos=(root[0]-'0')*10+(root[1]-'0');
        int len;
        cin>>len;
        while(len--)
        {
            char child[2];
            cin>>child;
            int tmp=(child[0]-'0')*10+(child[1]-'0');
            nodes[pos].push_back(tmp);
        }
    }
    dfs(1);
    cout<<ans[0];
    for(int i=1;i<=height;i++)
    {
        cout<<" "<<ans[i];
    }
}
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={vector<int>{1}};
        if(numRows>=2) ans.push_back(vector<int>{1,1});
        if(numRows==1||numRows==2) return ans;
        for(int i=2;i<numRows;i++)
        {
            vector<int> tmp;
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i) tmp.push_back(1);
                else
                {
                    tmp.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans=s.generate(2);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
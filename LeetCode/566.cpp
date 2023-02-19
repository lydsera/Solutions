#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        int m=mat.size();
        int n=mat[0].size();
        int x=0;
        int y=0;
        if(m*n!=r*c) return mat;
        for(x=0;x<r;x++)
        {
            vector<int> tmp;
            for(y=0;y<c;y++)
            {
                tmp.push_back(mat[i][j]);
                j=(j+1)%n;
                if(j==0)
                {
                    i++;
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> mat={vector<int>{1,2},vector<int>{3,4}};
    int r=4;
    int c=1;
    Solution s;
    vector<vector<int>> ans=s.matrixReshape(mat,r,c);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
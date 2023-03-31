#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans={1};
        if(rowIndex==0) return ans;
        ans.push_back(1);
        for(int i=2;i<=rowIndex;i++)
        {
            int tmp=1;
            for(int j=1;j<i;j++)
            {
                int tmptmp=ans[j];
                ans[j]+=tmp;
                tmp=tmptmp;
            }
            ans.push_back(1);
        }
        return ans;
    }
};

int main()
{
    
}
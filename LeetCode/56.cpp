#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int len=intervals.size();
        int i=1;
        int start=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>> ans;
        while(i<len)
        {
            if(end>=intervals[i][0])
            {
               if(end<intervals[i][1])end=intervals[i][1]; 
            } 
            else
            {
                ans.push_back(vector<int>{start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            i++;
        }
        ans.push_back(vector<int>{start,end});
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals={vector<int>{1,3},vector<int>{2,6},vector<int>{8,10},vector<int>{15,18}};
    Solution s;
    s.merge(intervals);
    for(int i=0;i<intervals.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<intervals[i][j]<<" ";
        }
        cout<<endl;
    }
}
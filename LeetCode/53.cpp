#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp.push_back(max(dp[i-1]+nums[i],nums[i]));
            if(dp[i]>ans) ans=dp[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={5,4,-1,7,8};
    Solution s;
    cout<<s.maxSubArray(nums);

}
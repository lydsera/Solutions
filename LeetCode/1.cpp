#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])==m.end())
            {
                m.insert(pair<int,int>(nums[i],i));
            }
            else
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;

    }
};

int main()
{
    vector<int> nums={3,3};
    int target=6;
    Solution s;
    vector<int> ans=s.twoSum(nums,target);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
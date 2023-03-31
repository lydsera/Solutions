#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ans=-1;
        unordered_map<int,int> m;
        int len=nums.size();
        if(len==1) return nums[0];
        for(int i=0;i<len;i++)
        {
            if(m.find(nums[i])==m.end()) m.insert(pair<int,int>(nums[i],1));
            else{
                int tmp=++m[nums[i]];
                if(tmp>cnt)
                {
                    cnt=tmp;
                    ans=nums[i];
                }
            }
        }
        return ans;
    }
};
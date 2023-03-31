#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp=nums.size();
        int ans=0;
        for(int i=0;i<tmp;i++)
        {
            ans^=nums[i];//异或运算，出现两次就会抵消，出现一次就会保留
        }
        return ans;
    }
};
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //纯为了AC的代码，有更好的方法，有空再想
        int num1=0,num2=0;
        int len=nums.size();
        vector<int> ans;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==0) ans.push_back(0);
            else if(nums[i]==1) num1++;
            else num2++;
        }
        for(int i=0;i<num1;i++) ans.push_back(1);
        for(int i=0;i<num2;i++) ans.push_back(2);
        nums=ans;
    }
};
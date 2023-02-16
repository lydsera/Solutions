#include<iostream>
#include<unordered_map>//STL哈希表
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                return true;
            }
            m.insert(pair<int,int>(nums[i],1));
        }
        return false;
    }
};

int main()
{
    vector<int> nums={1,2,3,4};
    Solution s;
    if(s.containsDuplicate(nums)) cout<<"true";
    else cout<<"false";
}
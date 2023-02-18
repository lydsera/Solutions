#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            unordered_map<int,int>::iterator it;
            it=m.find(nums1[i]);
            if(it==m.end())
            {
                m.insert(pair<int,int>(nums1[i],1));
            }
            else
            {
                int cnt=it->second;
                m[nums1[i]]=cnt+1;
            }
        }
        for(int i=0;i<nums2.size();i++)
        {
            unordered_map<int,int>::iterator it;
            it=m.find(nums2[i]);
            if(it!=m.end())
            {
                ans.push_back(nums2[i]);
                int cnt=it->second;
                cnt--;
                if(cnt<=0) m.erase(nums2[i]);
                else
                {
                    m[nums2[i]]=cnt;
                }
            }
        }
        return ans;
    }
    
};

int main()
{
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    Solution s;
    vector<int> ans;
    ans=s.intersect(nums1,nums2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp=nums1;
        int i=0,j=0;
        while(i<m||j<n)
        {
            if(j>=n||(tmp[i]<=nums2[j]&&i<m))
            {
                nums1[i+j]=tmp[i];
                i++;
            }
            else
            {
                nums1[i+j]=nums2[j];
                j++;
            }
        }
    }
};

int main()
{
    vector<int> nums1={0};
    int m=0;
    vector<int> nums2={1};
    int n=1;
    Solution s;
    s.merge(nums1,m,nums2,n);
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }
}
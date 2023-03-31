#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //想不出比O(n^2)快的算法。。
        //比如对于[-8,9,6,1,4,3,2,0,-2]，先排序[-8,-2,0,1,2,3,4,6,9]
        //然后先选-8作为三个数最小的数left
        //从-2，0，1...向右逼近选三个数中间的数mid
        //从9，6，4...向左逼近选三个数最大的数right
        //找三数和为0的情况，直至mid和right重合
        //然后选left的下一个数-2，mid从0开始，right又从9开始，以此类推
        //听上去不难但有很多去重的细节
        sort(nums.begin(),nums.end());
        int len=nums.size();
        vector<vector<int>> ans;
        if(len<=2) return ans;//不够三个数直接返回空
        int l=0;
        while(l<len-2)
        {
            
            if(nums[l]>0) break;//如果left即最小的数都大于0了，和必然大于0，就没必要再找了
            int m=l+1;
            int r=len-1;
            int left=nums[l];
            while(m!=r)
            {
                
                int mid=nums[m];
                int right=nums[r];
                int sum=left+mid+right;
                if(sum>0) while(nums[r]==right&&m!=r) r--;//如果sum大于0，说明right太大了，要左移，相同的right会得到同样sum大于0的结果，此处直接跳到不同的right为止
                else if(sum<0) while(nums[m]==mid&&m!=r) m++;//同上类似
                else if(sum==0)
                {
                    vector<int> tmp;
                    tmp.push_back(left);
                    tmp.push_back(mid);
                    tmp.push_back(right);
                    ans.push_back(tmp);
                    while(nums[m]==mid&&m!=r) m++;//sum等于0我们选择右移mid，或者左移right也可以，此处同样要找到不同的mid为止，否则会出现重复
                }
                /*r，m不能同时减或加 否则[1,-1,-1,0]过不了
                while(nums[r]==right&&m!=r) r--;
                while(nums[m]==mid&&m!=r) m++;*/
            }
            l++;
            while(l<len&&nums[l]==left) l++;//同样是去重，这里条件是l<len而不是len-2
            //如果是len-2，例如[0,0,0,0,0]会先选择前两个零和最后一个零，然后left去重到第三个0就停止，末尾三个零会被再加一次
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={0,0,0,0};
    Solution s;
    vector<vector<int>> ans=s.threeSum(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
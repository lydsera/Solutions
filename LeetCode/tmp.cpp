#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res=0;
        int len=ratings.size();
        vector<int> can=vector<int>(len,1);
        for(int i=0;i<len-1;i++)
        {
            if(ratings[i]>ratings[i+1]) can[i]++;
            else if(ratings[i]<ratings[i+1]) can[i+1]++;
        }
        for(int c : can)
        {
            res+=c;
        }
        return res;
    }
};

int main()
{
    

    return 0;
}
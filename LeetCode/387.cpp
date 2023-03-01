#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> m;
        int ans=0;
        int tmp=s.size();
        for(int i=0;i<tmp;i++)
        {
            if(m.find(s[i])==m.end())
            {
                m.insert(pair<char,int>(s[i],1));
            }
            else{
                m[s[i]]++;
            }
        }
        
        while(m[s[ans]]!=1&&ans!=tmp) ans++;
        if(ans!=tmp) return ans;
        else return -1;
    }
};

int main()
{
    string s="abc";
    Solution sol;
    cout<<sol.firstUniqChar(s);
}
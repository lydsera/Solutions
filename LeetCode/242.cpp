#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            char tmp=s[i];
            if(m.find(tmp)==m.end()) m.insert(pair<char,int>(tmp,1));
            else m[tmp]++;
        }
        len=t.size();
        for(int i=0;i<len;i++)
        {
            char tmp=t[i];
            if(m.find(tmp)==m.end()) return false;
            else
            {
                if(--m[tmp]==0) m.erase(tmp);
            }
        }
        if(m.empty()) return true;
        return false;

    }
};
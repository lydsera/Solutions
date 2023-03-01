#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len=magazine.size();
        unordered_map<char,int> m;
        for(int i=0;i<len;i++)
        {
            char tmp=magazine[i];
            if(m.find(tmp)==m.end()) m.insert(pair<char,int>(tmp,1));
            else m[tmp]++;
        }
        len=ransomNote.size();
        for(int i=0;i<len;i++)
        {
            char tmp=ransomNote[i];
            if(m.find(tmp)==m.end()) return false;
            else if(m[tmp]>0)
            {
                m[tmp]--;                
            }
            else return false;
        }
        return true;
    }
};

int main()
{
    string ransomNote="ab";
    string magazine="aa";
    Solution s;
    cout<<s.canConstruct(ransomNote,magazine);
}
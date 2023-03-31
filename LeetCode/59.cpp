#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    char dir[4]={'r','d','l','u'};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans=vector<vector<int>>(n,vector<int>(n));
        int index=1;
        int end=n*n;
        int i=0,j=0;
        char d='r';
        while(index<=end)
        {
            ans[i][j]=index;
            index++;
            switch (d)
            {
            case 'r':
                if(j==n-1||ans[i][j+1]!=0)
                {
                    d='d';
                    i++;
                }
                else j++;
                break;
            case 'd':
                if(i==n-1||ans[i+1][j]!=0)
                {
                    d='l';
                    j--;
                }
                else i++;
                break;
            case 'l':
                if(j==0||ans[i][j-1]!=0)
                {
                    d='u';
                    i--;
                }
                else j--;
                break;
            case 'u':
                if(i==0||ans[i-1][j]!=0)
                {
                    d='r';
                    j++;;
                }
                else i--;
                break;
            }
        }
        return ans;
    }
};
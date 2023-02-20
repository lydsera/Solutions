#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool> row;
        unordered_map<int,bool> col;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(pair<int,bool>(i,true));
                    col.insert(pair<int,bool>(j,true));
                }
                
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(row.find(i)!=row.end())
                {
                    matrix[i][j]=0;
                    continue;
                }
                if(col.find(j)!=col.end())
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};

int main()
{

}
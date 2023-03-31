#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //上下对称翻转，再对角线对称翻转
        int len=matrix.size();
        for(int i=0;i<len/2;i++)
        {
            vector<int> tmp=matrix[i];
            matrix[i]=matrix[len-i-1];
            matrix[len-i-1]=tmp;
        }
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
    }
};

int main()
{

}
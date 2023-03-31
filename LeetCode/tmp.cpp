#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> tmp;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       tmp=matrix;
       return search(0,0,matrix.size()-1,matrix[0].size()-1);
    }
    bool search(int be_i,int be_j,int en_i,int en_j)
    {
        int i=(be_i+en_i)/2;
        int j=(be_j+en_j)/2;
    }
};
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,bool>> row;
        vector<unordered_map<char,bool>> col;
        vector<unordered_map<char,bool>> grid;
        for(int j=0;j<9;j++)
        {
            unordered_map<char,bool> tmp1,tmp2;
            col.push_back(tmp1);
            grid.push_back(tmp2);
        }
        for(int i=0;i<9;i++)
        {
            unordered_map<char,bool> tmp;
            row.push_back(tmp);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                else
                {
                    if(row[i].find(board[i][j])==row[i].end())
                    {
                        row[i].insert(pair<char,bool>(board[i][j],true));
                    }
                    else{
                        return false;
                    } 
                    if(col[j].find(board[i][j])==col[j].end())
                    {
                        col[j].insert(pair<char,bool>(board[i][j],true));
                    }
                    else{
                        return false;
                    }
                    int grid_pos=(i/3)*3+j/3;
                    if(grid[grid_pos].find(board[i][j])==grid[grid_pos].end())
                    {
                        grid[grid_pos].insert(pair<char,bool>(board[i][j],true));
                    }
                    else{
                        return false;
                    } 
                }
            }
        }
        return true;
    }
};

/*
['.','.','.','.','5','.','.','1','.'],
['.','4','.','3','.','.','.','.','.'],
['.','.','.','.','.','3','.','.','1'],
['8','.','.','.','.','.','.','2','.'],
['.','.','2','.','7','.','.','.','.'],
['.','1','5','.','.','.','.','.','.'],
['.','.','.','.','.','2','.','.','.'],
['.','2','.','9','.','.','.','.','.'],
['.','.','4','.','.','.','.','.','.']]
false*/
/*
vector<vector<char>> board={vector<char>{'5','3','.','.','7','.','.','.','.'},
                                vector<char>{'6','.','.','1','9','5','.','.','.'},
                                vector<char>{'.','9','8','.','.','.','.','6','.'},
                                vector<char>{'8','.','.','.','6','.','.','.','3'},
                                vector<char>{'4','.','.','8','.','3','.','.','1'},
                                vector<char>{'7','.','.','.','2','.','.','.','6'},
                                vector<char>{'.','6','.','.','.','.','2','8','.'},
                                vector<char>{'.','.','.','4','1','9','.','.','5'},
                                vector<char>{'.','.','.','.','8','.','.','7','9'}};*/
int main()
{
    vector<vector<char>> board={vector<char>{'.','.','.','.','5','.','.','1','.'},
                                vector<char>{'.','4','.','3','.','.','.','.','.'},
                                vector<char>{'.','.','.','.','.','3','.','.','1'},
                                vector<char>{'8','.','.','.','.','.','.','2','.'},
                                vector<char>{'.','.','2','.','7','.','.','.','.'},
                                vector<char>{'.','1','5','.','.','.','.','.','.'},
                                vector<char>{'.','.','.','.','.','2','.','.','.'},
                                vector<char>{'.','2','.','9','.','.','.','.','.'},
                                vector<char>{'.','.','4','.','.','.','.','.','.'}};
    Solution s;
    if(s.isValidSudoku(board)) cout<<"true";
    else cout<<"false";
}
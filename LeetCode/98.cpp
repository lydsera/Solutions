#include<iostream>
#include<queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    long long pre = (long long)INT_MIN - 1;
    bool isValidBST(TreeNode* root) {
        //二叉搜索树的中序遍历就是从小到大的序列，可以利用此特点
        if(root==NULL) return true;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        bool flag=isValidBST(left);
        if(!flag) return false;
        if(pre>=root->val) return false;
        pre=root->val;
        return isValidBST(right);
    }
};
//原本想用广搜，但是[5,4,6,null,null,3,7]过不了
    // bool isValidBST(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         TreeNode* tmp=q.front();
    //         TreeNode* left=tmp->left;
    //         TreeNode* right=tmp->right;
    //         q.pop();
    //         if(left!=NULL)
    //         {
    //             if(left->val>=tmp->val) return false;
    //             else q.push(left);
    //         }
    //         if(right!=NULL)
    //         {
    //             if(right->val<=tmp->val) return false;
    //             else q.push(right);
    //         }
            
    //     }
    //     return true;
    // }
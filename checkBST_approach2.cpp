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
class Solution {
public:
    bool isBST(TreeNode* root,long long  min,long long max)
    //max and min are 2 functions of C++,better not to use them as parameter
    {
        if(root==nullptr) return true;
        if(root->val > min && root->val < max && isBST(root->left,min,root->val) && isBST(root->right,root->val,max))
        return true;
        else return false;
    }
    bool isValidBST(TreeNode* root){
     return isBST(root,LLONG_MIN,LLONG_MAX);
    }
};  

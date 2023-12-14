//this code checks if a given Binary tree a BST or not
//the question is from Leetcode,kindly check the question --> https://leetcode.com/problems/validate-binary-search-tree/description/
//Kindly do keep in mind that it doesn''t allow duplicate values and strict inequality is to be maintained i.e. 
/*
      5
    /   \
   5     5 
   is NOT a BST 
*/

//code:

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
vector<int> a;
void inOrder(TreeNode* root)
{
    if(root==nullptr)
        return;
    inOrder(root->left);
    a.push_back(root->val);
    inOrder(root->right);
}
    bool isValidBST(TreeNode* root){
        inOrder(root);
        vector<int> b=a;
        sort(b.begin(),b.end());
        if(a==b) {
            for(int i=1;i<a.size();i++)
            {
                if(a[i]==a[i-1])
                    return false;
            }
            return true;
        }
        else return false;
    }
};  

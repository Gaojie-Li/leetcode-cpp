/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) 
            return;
            
        if (root -> left == NULL && root -> right == NULL) 
            return;
        
        TreeNode* rt = root;
        TreeNode* temp;
        while (rt != NULL) {
            if (rt -> left != NULL) {
                temp = rt -> left;
                while (temp -> right != NULL) {
                    temp = temp -> right;
                }
                temp -> right = rt -> right;
                rt -> right = rt -> left;
                rt -> left = NULL;
            }
            
            rt = rt -> right;
        }
    }
};
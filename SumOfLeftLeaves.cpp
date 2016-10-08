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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root -> left && !root -> right)
            return 0;
         
        int result = 0;   
        if (root -> left) {
            if (!root -> left -> left && !root -> left -> right) {
                    result = result + root -> left -> val;
            }
            
            result = result + sumOfLeftLeaves(root -> left);
        }
        if (root -> right) {
            result = result + sumOfLeftLeaves(root -> right);
        }
        
        return result;
    }
};
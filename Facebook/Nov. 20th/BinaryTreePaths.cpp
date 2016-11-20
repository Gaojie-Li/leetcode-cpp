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
    void binaryTreePath(TreeNode* root, string res, vector<string>& result) {
        if (!root -> left && !root -> right) {
            result.push_back(res);
            return;
        }
        
        if (root -> left) {
            binaryTreePath(root -> left, res + "->" + to_string(root -> left -> val), result);
        }
        
        if (root -> right) {
            binaryTreePath(root -> right, res + "->" + to_string(root -> right -> val), result);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        
        binaryTreePath(root, to_string(root -> val), result);
        return result;
    }
};
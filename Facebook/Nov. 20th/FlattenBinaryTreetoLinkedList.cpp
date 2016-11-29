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
        if (root == NULL) {
            return;
        }
        
        if (root -> left == NULL && root -> right == NULL) {
            return;
        }
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur -> right == NULL && cur -> left != NULL) {
                cur -> right = cur -> left;
                cur -> left = NULL;
            }
            else if (cur -> right != NULL && cur -> left != NULL) {
                TreeNode* temp = cur -> left;
                while (temp -> right != NULL) {
                    temp = temp -> right;
                }
                temp -> right = cur -> right;
                cur -> right = cur -> left;
                cur -> left = NULL;
            }
            cur = cur -> right;
        }
    }
};
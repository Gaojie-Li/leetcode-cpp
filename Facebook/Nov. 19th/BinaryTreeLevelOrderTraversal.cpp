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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> stk;
        
        stk.push(root);
        while (!stk.empty()) {
            vector<int> level;
            int n = stk.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = stk.front();
                if (cur -> left != NULL) {
                    stk.push(cur -> left);
                }
                if (cur -> right != NULL) {
                    stk.push(cur -> right);
                }
                level.push_back(cur -> val);
                stk.pop();
            }
            result.push_back(level);
        }
        
        return result;
    }
};
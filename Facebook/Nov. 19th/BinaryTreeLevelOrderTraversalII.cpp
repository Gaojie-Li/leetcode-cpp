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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> nodeq;
        nodeq.push(root);
        
        while (!nodeq.empty()) {
            vector<int> level;
            int n = nodeq.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = nodeq.front();
                if (cur -> left) {
                    nodeq.push(cur -> left);
                }
                if (cur -> right) {
                    nodeq.push(cur -> right);
                }
                level.push_back(cur -> val);
                nodeq.pop();
            }
            result.push_back(level);
        }
        
        for (int i = 0; i < result.size() / 2; i++) {
            swap(result[i], result[result.size() - 1 - i]);
        }
        
        return result;
    }
};
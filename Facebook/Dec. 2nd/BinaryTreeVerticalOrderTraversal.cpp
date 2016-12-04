/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int minIndex = 100000;
class Solution {
public:
    void BFS(unordered_map<int, vector<int> >& index, queue<pair<int, TreeNode*>>& myQueue) {
        auto temp = myQueue.front();
        TreeNode* cur = temp.second;
        int key = temp.first;
        myQueue.pop();
        
        if (index.find(key) == index.end()) {
            vector<int> newIndex;
            newIndex.push_back(cur->val);
            index[key] = newIndex;
        }
        else {
            index[key].push_back(cur->val);
        }
        if (cur -> left) {
            myQueue.push({key - 1, cur -> left});
        }
        if (cur -> right) {
            myQueue.push({key + 1, cur -> right});
        }

        minIndex = min(minIndex, key);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        
        unordered_map<int, vector<int> > index;
        queue<pair<int, TreeNode*> > myQueue;
        
        myQueue.push({0, root});
        BFS(index, myQueue);
        
        while (!myQueue.empty()) {
            BFS(index, myQueue);
        }
        
        while (index.find(minIndex) != index.end()) {
            result.push_back(index[minIndex]);
            minIndex++;
        }
        
        return result;
    }
};
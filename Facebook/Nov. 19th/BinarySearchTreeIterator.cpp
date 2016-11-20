/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> nodes;
    int curNode;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorder(root -> left);
        nodes.push_back(root -> val);
        inorder(root -> right);
    }
    BSTIterator(TreeNode *root) {
        inorder(root);
        curNode = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curNode < nodes.size();
    }

    /** @return the next smallest number */
    int next() {
        return nodes[curNode++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
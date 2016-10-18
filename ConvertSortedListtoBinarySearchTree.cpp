/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        if (head -> next == NULL) {
            TreeNode* root = new TreeNode(head -> val);
            return root;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;
        
        // slow should be the middle element of the list
        while (fast != NULL && fast -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // cut the list into two half
        ListNode* mid = slow -> next;
        prev -> next = NULL;

        TreeNode* root = new TreeNode(slow -> val);
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(mid);
        
        return root;
    }
};
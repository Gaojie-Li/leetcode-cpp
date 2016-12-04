/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        
        while (cur != NULL) {
            if (cur == head && cur->val == val) {
                head = cur -> next;
                cur = head;
                continue;
            }
            
            if (cur->val == val) {
                pre -> next = cur -> next;
                cur = pre -> next;
                continue;
            }
            pre = cur;
            cur = cur -> next;
        }
        
        return head;
    }
};
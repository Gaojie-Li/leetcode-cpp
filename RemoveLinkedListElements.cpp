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
        if (head == NULL) {
            return head;
        }
        
        ListNode* cur = head;
        while (cur != NULL) {
            if (head -> val == val) {
                head = head -> next;
                cur = head;
                continue;
            }
            
            if (cur -> next != NULL && cur -> next -> val == val) {
                ListNode* temp = cur;
                while (temp -> next != NULL && temp -> next -> val == val) {
                    temp = temp -> next;
                }
                cur -> next = temp -> next;
            }

            cur = cur -> next;
        }
        
        return head;
    }
};
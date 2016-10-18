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
    ListNode* reverseList(ListNode* head) {
        ListNode* reversed = NULL;
        
        while (head != NULL) {
            ListNode* insert = new ListNode(head -> val);
            insert -> next = reversed;
            reversed = insert;
            head = head -> next;
        }
        
        return reversed;
    }
    
    bool compareLists(ListNode* origin, ListNode* reversed) {
        ListNode* cur1 = origin;
        ListNode* cur2 = reversed;
        while (cur1 != NULL && cur2 != NULL) {
            if (cur1 -> val != cur2 -> val) {
                return false;
            }
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        // Solution 1: Reverse and Compare.
        ListNode* reverse = reverseList(head);
        
        bool result = compareLists(head, reverse);
        
        return result;
        
        // Solution 2: Iterative Approach.
        
    }
};
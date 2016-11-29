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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode* pre = NULL;
        ListNode* start = head;
        int i = 0;
        for (; i < m-1; i++) {
            pre = start;
            start = start -> next;
        }
        
        ListNode* end = start;
        ListNode* endPre = NULL;
        for (; i < n-1; i++) {
            ListNode* tempNext = end -> next;
            end -> next = endPre;
            endPre = end;
            end = tempNext;
        }
        
        ListNode* upNext = end -> next;
        end -> next = endPre;
        
        if (pre != NULL)
            pre -> next = end;
        start -> next = upNext;
        
        // if no pre, return last node to be reversed. -> start from first element
        // if has pre, return head -> start from at least second element.
        return pre == NULL ? end:head;
    }
};
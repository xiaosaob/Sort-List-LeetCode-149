// Sort a linked list in O(n log n) time using constant space complexity.

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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *walker = head, *runner = head;
        while(runner->next && runner->next->next) {
            runner = runner->next->next;
            walker = walker->next;
        }
        ListNode *head2 = walker->next;
        walker->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head,head2);
    }
    
    ListNode *merge(ListNode *head, ListNode *head2) {
        ListNode *newHead = NULL;
        ListNode *prev = NULL;
        while(head && head2) {
            if(head->val < head2->val) {
                if(!newHead) newHead = head;
                if(prev) prev->next = head;
                prev = head;
                head = head->next;
            } else {
                if(!newHead) newHead = head2;
                if(prev) prev->next = head2;
                prev = head2;
                head2 = head2->next;
            }
        }
        if(head) prev->next = head;
        if(head2) prev->next = head2;
        return newHead;
    }
};

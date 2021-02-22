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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL) {
            slow = slow->next;
            if(fast->next == NULL)
                return NULL;
            fast = fast->next->next;
            if(fast == slow) {
                ListNode *ptr = head;
                while(slow != ptr) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};
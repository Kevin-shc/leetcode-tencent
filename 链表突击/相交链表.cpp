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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode *ptr_a = headA;
        ListNode *ptr_b = headB;
        int val_a = 0, val_b = 0;
        bool flag_a = false, flag_b = false;
        while(ptr_a->next != NULL) {
            ptr_a = ptr_a->next;
        }
        val_a = ptr_a->val;
        ptr_a = headA;
        while(ptr_b->next != NULL) {
            ptr_b = ptr_b->next;
        }
        val_b = ptr_b->val;
        ptr_b = headB;
        if(val_a != val_b) {
            return NULL;
        }

        while(ptr_a != ptr_b) {
            if(ptr_a->next == NULL) {
                ptr_a = flag_a ? headA : headB;
                flag_a = flag_a ? false : true;
            } else {
                ptr_a = ptr_a->next;
            }
            
            if(ptr_b->next == NULL) {
                ptr_b = flag_b ? headB : headA;
                flag_b = flag_b ? false : true;
            } else {
                ptr_b = ptr_b->next;
            }
        }
        return ptr_a;
    }
};
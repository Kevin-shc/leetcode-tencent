/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) 
            return l2;
        if(l2 == NULL)
            return l1;
        int carry_flag = 0;
        ListNode *ans = new ListNode;
        ListNode *a = ans;
        while(l1 != NULL && l2 != NULL) {
            int num = 0;
            num = l1->val + l2->val + carry_flag;
            carry_flag = num / 10;
            num = num % 10;
            ListNode *p = new ListNode;
            p->val = num;
            p->next = NULL;
            ans->next = p;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL) {
            while(l2 != NULL) {
                int num = 0;
                num = l2->val + carry_flag;
                carry_flag = num / 10;
                num = num % 10;
                ListNode *p = new ListNode;
                p->val = num;
                p->next = NULL;
                ans->next = p;
                ans = ans->next;
                l2 = l2->next;
            }
        } else if (l2 == NULL) {
            while(l1 != NULL) {
                int num = 0;
                num = l1->val + carry_flag;
                carry_flag = num / 10;
                num = num % 10;
                ListNode *p = new ListNode;
                p->val = num;
                p->next = NULL;
                ans->next = p;
                ans = ans->next;
                l1 = l1->next;
            }
        }
        if(carry_flag) {
            ListNode *p = new ListNode;
            p->val = 1;
            p->next = NULL;
            ans->next = p;
            ans = ans->next;
        }
        return a->next;
    }
};
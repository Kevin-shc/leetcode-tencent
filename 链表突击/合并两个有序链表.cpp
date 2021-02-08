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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode;
        ListNode *q = new ListNode;
        ans = q;
        while(l1 || l2) {
            int num1 = l1 ? l1->val : INT_MAX;
            int num2 = l2 ? l2->val : INT_MAX;
            if(num1 <= num2) {
                ListNode *p = new ListNode(num1);
                q->next = p;
                q = q->next;
            } else if(num2 < num1){
                ListNode *p = new ListNode(num2);
                q->next = p;
                q = q->next;
            }
            if(l1 && num1 <= num2) {
                l1 = l1->next;
            }
            if(l2 && num2 < num1) {
                l2 = l2->next;
            }
        }
        return ans->next;
    }
};
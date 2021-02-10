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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k)
            return head;
        int length = 1;
        ListNode *p = head;
        while(p->next) {
            p = p->next;
            length++;
        }
        int num = k % length;
        if(num == 0)
            return head;
        p->next = head;
        for(int i = 0; i < length - num - 1; i++) {
            head = head->next;
        }
        ListNode *ans = head->next;
        head->next = NULL;
        return ans;

        // 感觉没问题，但是输出很奇怪
        // ListNode *ans_front = new ListNode;
        // ListNode *ans = ans_front;
        // ListNode *ans_back = head;
        // for(int i = 0; i < length - num; i++) {
        //     ans_front = ans_back;
        //     ans_back = ans_back->next;
        //     ListNode *q = new ListNode;
        //     ans_front->next = q;
        //     ans_front = ans_front->next;
        // }
        // ans_front = NULL;
        // p = ans_back;
        // while(p->next != NULL) {
        //     p = p->next;
        // }
        // p->next = ans;
        // return ans_back;
    }
};
        
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = new ListNode;
        ListNode *p = new ListNode;
        ans = p;
        if(lists.size() == 0)
            return NULL;
        int k = lists.size();
        while(1) {
            int num = INT_MAX;
            int pos = 0;
            int flag = 1;
            for(int i = 0; i < k; i++) {
                if(lists[i] == NULL)
                    continue;
                if(lists[i]->val < num) {
                    num = lists[i]->val;
                    pos = i;
                    flag = 0;
                }
            }
            if(flag)
                return ans->next;
            ListNode *q = new ListNode(num);
            p->next = q;
            p = p->next;
            lists[pos] = lists[pos]->next;
        }
        return ans->next;
    }
};
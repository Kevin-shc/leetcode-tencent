struct List_Node {
    char c;
    List_Node* next;
};

class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) 
            return false;
        List_Node* head = new List_Node;
        head->next = NULL;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
                List_Node* p = new List_Node;
                p->c = s[i];
                p->next = head;
                head = p;
            } else if (s[i] == ']' || s[i] == ')' || s[i] == '}') {
                if((s[i] == ')' && head->c == '(') || 
                   (s[i] == ']' && head->c == '[') || 
                   (s[i] == '}' && head->c == '{')) {
                    head = head->next;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return head->next == NULL ? true : false;
    }
};
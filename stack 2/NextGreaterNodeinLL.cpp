class Solution {
    public:
    int Length(ListNode*head){
        int len = 0;
        while(head){
        len++;
        head = head->next;
        }
        return len;
    }
    ListNode* ReverseLL(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = ReverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    vector<int> nextLargerNodes(ListNode* head) {
       stack<int>st;
       int len = Length(head);
       vector<int>v(len , 0);
       head = ReverseLL(head);
        int i = 0;
       while(head){
            while(!st.empty() && head->val >= st.top())
                st.pop();
            if(!st.empty())  v[i] = st.top();
            st.push(head->val);
            head = head->next;   
            i++;
       }
       reverse(v.begin() , v.end());
       return v;
    }
};

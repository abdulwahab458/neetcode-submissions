class Solution {
public:
    ListNode* mergeLL(ListNode* h1, ListNode* h2) {
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;

        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(h1 && h2) {
            if(h1->val <= h2->val) {
                temp->next = h1;
                h1 = h1->next;
            }
            else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }

        if(h1) temp->next = h1;
        if(h2) temp->next = h2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;

        for(int i = 0; i < lists.size(); i++) {
            ans = mergeLL(ans, lists[i]);
        }

        return ans;
    }
};
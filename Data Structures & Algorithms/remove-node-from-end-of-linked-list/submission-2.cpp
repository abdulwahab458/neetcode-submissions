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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* curr = head;
        int len = 0 ; 
        while(curr!=NULL){
            len+= 1;
            curr = curr->next;
        }
        ListNode* temp = head;
        int k = 0 ; 
        ListNode* prev = NULL;
        while(temp != NULL){
            if(len - k == n ){
                if (prev == NULL) {
                    return head->next;
                }
                prev->next = temp->next;
                break;
            }
            prev = temp;
            temp = temp->next;
            k++;
            
        }
        return head;
    }
};

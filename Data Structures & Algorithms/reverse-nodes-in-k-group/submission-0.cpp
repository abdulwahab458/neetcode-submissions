class Solution {
public:
    ListNode* reverseLL(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        int count = 1;
        ListNode* temp = head;

        while (temp != NULL) {
            if (count == k) {
                break;
            }
            temp = temp->next;
            count++;
        }

        if (temp == NULL) return head;

        ListNode* toconnect = temp->next;
        temp->next = NULL;

        ListNode* prevHead = head;
        ListNode* newHead = reverseLL(prevHead, temp);

        // prevHead is now the tail of the reversed group
        prevHead->next = reverseKGroup(toconnect, k);

        return newHead;
    }
};
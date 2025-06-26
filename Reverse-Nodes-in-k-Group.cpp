class Solution {
public:
    // Reverse a group of k nodes and return new head
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Check if there are at least k nodes remaining
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count == k) {
            // Reverse first k nodes
            ListNode* reversedHead = reverseLinkedList(head, k);
            // head becomes the end of the reversed group, connect it to the result of next group
            head->next = reverseKGroup(curr, k);
            return reversedHead;
        }

        // Less than k nodes left, don't reverse
        return head;
    }
};

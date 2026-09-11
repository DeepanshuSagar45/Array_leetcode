class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || left == right)
            return head;

        // Dummy node handles the case where left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Move prev to the node just before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Reverse the nodes from left to right
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;
    }
};
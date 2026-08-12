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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode deepanshu(0);
        deepanshu.next = head;

        ListNode* prev = &deepanshu;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Check if current value is duplicated
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                int duplicate = curr->val;

                // Remove all nodes with this value
                while (curr != nullptr && curr->val == duplicate) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                // Current value is unique
                prev = curr;
                curr = curr->next;
            }
        }

        return deepanshu.next;
    }
};
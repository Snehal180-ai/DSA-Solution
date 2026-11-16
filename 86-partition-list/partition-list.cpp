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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);

        ListNode* dummy1 = before;
        ListNode* dummy2 = after;

        while (head != NULL) {
            if (head->val < x) {
                dummy1->next = head;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = head;
                dummy2 = dummy2->next;
            }

            head = head->next;
        }

        dummy2->next = NULL;
        dummy1->next = after->next;

        return before->next;
    }
};
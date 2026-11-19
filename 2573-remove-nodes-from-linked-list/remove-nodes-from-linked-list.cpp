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
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* curr = head;

//         while (curr != nullptr) {
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         head = prev;

//         int maxValue = 0;
//         ListNode* dummy = new ListNode(0);
//         ListNode* tail = dummy;

//         curr = head;

//         while (curr != nullptr) {
//             if (curr->val >= maxValue) {
//                 maxValue = curr->val;
//                 tail->next = curr;
//                 tail = tail->next;
//             }

//             curr = curr->next;
//         }

//         tail->next = nullptr;

//         prev = nullptr;
//         curr = dummy->next;

//         while (curr != nullptr) {
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         return prev;
//     }
// };



class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        head->next = removeNodes(head->next);

        if (head->val < head->next->val)
            return head->next;

        return head;
    }
};
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int pos = 1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        int first = -1;
        int prevCritical = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next != NULL) {

            ListNode* nextNode = curr->next;

            if ((curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val)) {

                if (first == -1) {
                    
                    first = pos;
                }
                else {
                    minDist = min(minDist, pos - prevCritical);

                    maxDist = max(maxDist, pos - first);
                }

                prevCritical = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        if (first == -1 || first == prevCritical) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};
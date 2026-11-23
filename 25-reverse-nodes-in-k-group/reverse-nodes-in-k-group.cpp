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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // check the length of curr group
        ListNode* temp = head;
        int cnt=0;
        while(cnt<k) {
            // base case
            if (temp == nullptr)
                return head;
            temp = temp->next;
            cnt++;
        }
        // go ahead for rest of ll
        ListNode* prev = reverseKGroup(temp, k);
        // now reverse the curr group and fit
        temp=head;
        cnt=0;
        while(cnt<k){
            ListNode* nxt = temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
            cnt++;
        }
        return prev;

    }
};
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
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5){
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }
        ListNode* curr = head;
        while(curr){
            curr->val = (curr->val*2)%10;
            if(curr->next && curr->next->val >= 5){
                curr->val += 1;
            }
            curr = curr->next;
        }
        return head;
    }
};
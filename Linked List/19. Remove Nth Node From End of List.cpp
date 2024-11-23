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
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
        int i= 0;
        while(i<n){
            fastPointer = fastPointer->next;
            i++;
        }
        if(fastPointer == NULL){                // if we have to delete the head node or a node which doesn't even exist
            return head->next;
        }
        while(fastPointer!= NULL && fastPointer->next != NULL){
            slowPointer= slowPointer->next;
            fastPointer = fastPointer->next;
        }
        if(slowPointer->next != NULL){           //member access within null pointer of type 'struct ListNode'
           slowPointer->next = slowPointer->next->next;
        }
        
        return head;
    }
};
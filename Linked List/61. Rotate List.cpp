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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        ListNode *tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        if(k == 0 || k%len == 0){       // if k(rotation number) is same of the length of list
            return head;
        }

        if(k>len){
           k = k%len;                  // if k(rotation number) is more than length of the list
        }
                            
        tail->next= head;
        ListNode *temp = head;
        int cnt = 1;
        while(cnt<(len-k)){
            temp = temp->next;
            cnt++;
        }
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
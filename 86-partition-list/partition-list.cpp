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
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);

        ListNode *lTail = left;
        ListNode *rTail = right;

        while(head !=NULL){
            if(head->val <x){
                lTail->next = head;
                lTail = lTail->next;
            }
            else{
                rTail->next = head;
                rTail = rTail->next;
            }
            head = head->next;
        }

        lTail->next = right->next;
        rTail->next = NULL;

        return left->next;
    }
};
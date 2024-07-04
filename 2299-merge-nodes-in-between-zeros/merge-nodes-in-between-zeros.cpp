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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        while(curr){
            ListNode* traverse = curr;
            int sum=0;
            while(traverse->val!=0){
                sum+=traverse->val;
                traverse = traverse->next;
            }
            curr->val = sum;
            curr->next = traverse->next;
            curr = traverse->next;
        }
        return head->next;
    }
};
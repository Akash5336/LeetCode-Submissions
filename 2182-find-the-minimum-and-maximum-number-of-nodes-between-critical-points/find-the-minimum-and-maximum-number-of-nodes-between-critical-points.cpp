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
        int minD = INT_MAX;
        int fI=-1,pI=-1,idx=1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr->next){
            if(curr->val > prev->val && curr->val > curr->next->val || 
            curr->val < prev->val && curr->val < curr->next->val){
                if(fI==-1)
                    fI = idx;
                if(pI!=-1)
                    minD = min(minD,idx-pI);
                pI=idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if(minD==INT_MAX)
            return {-1,-1};
        return {minD,pI-fI};
    }
};
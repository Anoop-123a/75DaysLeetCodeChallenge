// 75 LeetCode Challenge-->>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // no cycle ->fast=NULL
        // cycle ->fast=slow
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast=fast->next->next;
            slow=slow->next;
            // check whether they are meeting or not
            if(slow==fast){
                return true;
            }
        }
        // loop se bhaar tabhi ayega ,jab fast Null hoga
        return false;
    }
};
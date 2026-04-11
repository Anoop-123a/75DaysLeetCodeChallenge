// 75 Leetcode challenge-->>

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
//  Slow -fast approach-->
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // your code goes here
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast!=NULL &&fast->next!=NULL){
       
        fast=fast->next->next;
         slow=slow->next;
      } 
     return slow;  //this is the middle node
    }
};
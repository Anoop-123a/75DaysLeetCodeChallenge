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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        if (list1 == NULL) {
            return list2;
        }


        if (list2 == NULL) {
            return list1;
        } 
        ListNode* ans=new ListNode(-1); //New node for merge sorted list

        if (list1 != NULL && list2 != NULL) {
           
            ListNode* temp=ans; //  Point to that new node
            ListNode* left=list1; //point head of first list 
            ListNode* right=list2;  //point to head of second list
            while(left!=NULL && right!=NULL){
                if(left->val<=right->val){
                    temp->next=left;
                    temp=left;
                    left=left->next;

                }
                else{
                    temp->next=right;
                    temp=right;
                    right=right->next;

                }
            }
            if(left!=NULL && right==NULL){
                temp->next=left;
            }
            else{
                temp->next=right;
            }

            
            }
        
        return ans->next;
    }
};
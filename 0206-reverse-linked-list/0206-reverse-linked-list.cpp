// 75 leetcode challenge-->>

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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // your code goes here
//     if(head==NULL){
//             return NULL ;
//         }
//         ListNode* prev=NULL;
//       ListNode* curr=head;

//     //   updated links
//     while(curr!=NULL){
//         ListNode* forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;

//     }
//     // upadted head
//     head=prev;
//     return head; //we always return head only

//      }
// };


// recursive approach-->>
class Solution {
public:

      ListNode* solve(ListNode* prev, ListNode* curr) {

        // base case
        if (curr == NULL) {
            return prev;   // new head
        }

        ListNode* forward = curr->next;
        curr->next = prev;

        return solve(curr, forward);
    }

    ListNode* reverseList(ListNode* head) {

        return solve(NULL, head);
    }
  };
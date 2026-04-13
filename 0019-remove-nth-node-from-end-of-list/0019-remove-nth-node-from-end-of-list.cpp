// 75 Days leetcode challenge-->>


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
    int length(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head->next;
        ListNode* prev = head;
        int size = length(head);

        // if linked list have one element -->>
        if (size == 1) {

            // deletion logic-->>
            head = NULL;
            return NULL;
        }

        // if we want to delete the first node-->
        else if (n == 1) {
            ListNode* temp = head->next;
            ListNode* prev = head;

            //  set the pointer-->>
            while (temp->next != NULL) {
                temp = temp->next;
                prev = prev->next;
            }
            // deletion logic-->>
            prev->next = NULL;
            delete temp;
            return head;
        }

        // if we want to delete the last node-->>
        else if (size == n) {
            // deletion logic-->>
            ListNode* temp = head->next;
            delete head;
            return temp;

        }
        
         else {
            // if we want to delete any node which is between two node-->>
            // set pointer-->
            for (int i = 0; i < size - n - 1; i++) {
                temp = temp->next;
                prev = prev->next;
            }

            // deletion logic-->>
            ListNode* curr = temp;
            prev->next = temp->next;
            temp->next = NULL;
            delete curr;

            return head;
        }
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* j = NULL;
        while(head != NULL){
            if(head -> next != NULL && head -> val == head -> next -> val){
                j = head;
                while (head != NULL && head -> val == j -> val){
                    head = head->next;
                }
            }
            else {
                temp->next = head;
                temp  = temp-> next;
                head = head-> next;
            }
        }
        temp->next = NULL;
        return dummy -> next;
    }
};
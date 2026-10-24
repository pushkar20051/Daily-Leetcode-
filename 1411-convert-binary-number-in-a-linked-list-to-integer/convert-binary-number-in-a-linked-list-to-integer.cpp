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
    int getDecimalValue(ListNode* head) {
        vector<int> bit(30);
        int i =0;
        while(head != NULL){
            bit[i] = head->val;
            i++;
            head = head->next;
        }
        int n = i;
        int sum =0;

        for(int i =0;i<n;i++){
            int idx = n - i -1;
            sum += bit[i] * pow(2, idx);
        }
        return sum;
    }
};
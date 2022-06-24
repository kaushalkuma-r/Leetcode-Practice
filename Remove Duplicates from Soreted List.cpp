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
        ListNode* curr_node=head;
        while(curr_node && curr_node->next){
        ListNode* next_node = curr_node->next;
        
        if (curr_node->val == next_node->val){
                curr_node->next = next_node->next;
                delete next_node;
         }
         else{
                curr_node = next_node;
         }
        }
        return head;
    }
};
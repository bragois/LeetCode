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
        if(head == nullptr){
            return head;
        }
        ListNode* retList = head;
        while(head != nullptr){
            ListNode* ref = head->next;
            while(ref != nullptr && ref->val == head->val){
                ref = ref->next;
            }
            head->next = ref;
            if(head != nullptr){
                head = head->next;
            }
        }
        return retList;
    }
};
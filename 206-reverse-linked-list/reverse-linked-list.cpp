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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        if(head != nullptr){
            ListNode* l2 = head->next;
            head->next = nullptr;
            while(l2){
                temp =  l2->next;
                l2->next = head;
                head = l2;
                l2 = temp;
            }
        }
        return head;
    }
};
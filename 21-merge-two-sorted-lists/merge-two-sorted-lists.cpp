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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = 0;
        ListNode* prev = 0;
        ListNode* current = 0;
        
        if(l1 != nullptr && l2 != nullptr){
            head = new ListNode();
            prev = new ListNode();
            current = new ListNode();
            if(l1->val <= l2->val){
                head = l1;
                prev = l1;
                current = l1;
            }
            else{
                head = l2;
                prev = l2;
                current = l2;
            }
        }
        else if(l1 != nullptr){
            return l1;
        }
        else if(l2 != nullptr){
            return l2;
        }
        
        while(l1 != nullptr && l2 != nullptr){
           if(l1->val <= l2->val){
               current = l1;
               l1 = l1->next;
            }
            else{
                current = l2;
                l2 = l2->next;
            }
            if((prev != current) && 
               (prev->next != current)){
                prev->next = current;
            }
            prev = current;
        }
        if(l1 != nullptr && prev != nullptr)
        {
            prev->next = l1;
        }
        else if(l2 != nullptr && prev != nullptr){
            prev->next = l2;
        }
        return head;
    }
};
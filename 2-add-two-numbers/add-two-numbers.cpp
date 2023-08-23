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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(0, nullptr);
        ListNode* result_cpy = result;

        while((l1 != nullptr)
            &&(l2 != nullptr)){
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            result->next = new ListNode(l1->val % 10, nullptr);

            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        /* 
        Process the remaining digits in the lists, in case the list have different sizes.
        */
        while(l1 != nullptr){
            l1->val += carry;
            carry = l1->val / 10;
            result->next = new ListNode(l1->val % 10, nullptr);
            
            result = result->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            l2->val += carry;
            carry = l2->val / 10;
            result->next = new ListNode(l2->val % 10, nullptr);
            
            result = result->next;
            l2 = l2->next;
        }

        if(carry){
            result->next = new ListNode(1, nullptr);
            result = result->next;
        }
        
        /* 
        Return initial copy to the next element after the head of the list.
        For ease of implementation and improved readability of the code, the first 
        element was deliberatly created with value 0.
        */
        return result_cpy->next;
    }
};
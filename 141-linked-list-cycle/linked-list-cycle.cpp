/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<struct ListNode*, int> mp;
        while(head){
            if(mp.find(head) != mp.end()){
                return true;
            }
            else{
                mp.insert(make_pair(head, 0));
            }
            head = head->next;
        }
        return false;
    }
};
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

        ListNode *ans = new ListNode(-1);
        ListNode *it = ans;

        int carry=0;

        while(l1 || l2 || carry){

            //sum = a + b +carry
            //a ki val tabhi lo jab l1 is available, warna 0 lo
            int a = l1 ? l1->val:0;
            int b = l2 ? l2->val:0;

            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;

            //now ans me -1 stored hai *it me
            it->next = new ListNode(digit);
            l1 = l1 ? l1->next: nullptr;
            l2 = l2 ? l2->next:nullptr;
            it = it->next;

        }

        return ans->next;        
    }
};
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

    //referred from soln -https://leetcode.com/submissions/detail/1110936412/
    ListNode* middleNode(ListNode* head) {

        //this is TORTOISE Algorithm - fast ptr agar 2 steps chala tab slow 1 step chalega

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow=  slow->next;
            }
        }
        
        return slow; //jaha slow hai wahi middle hai
    }

    //referred from sol - https://leetcode.com/submissions/detail/1110729542/
    ListNode* reverseList(ListNode* head) {

        ListNode *prev=NULL;
        ListNode *curr=head;

        while(curr != NULL){
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;      

    }

    bool compareLL(ListNode *head1, ListNode *head2){

        while(head1 != NULL && head2 != NULL){

            if(head1->val != head2->val){
                return false;
            }else{

                head1 = head1 -> next;
                head2 = head2 -> next;

            }

        }

        return true;

    }

    bool isPalindrome(ListNode* head) {

        //break into 2 halfs - Tortoise Algo
        ListNode *midNode = middleNode(head);
        ListNode *head2= midNode->next;

        //break LL in middle
        midNode ->next = NULL;

        // reverse 2nd half
        //ListNode *prev=NULL;
        ListNode *curr=head2;
        head2 = reverseList(head2);

        //compare ll
        bool ans = compareLL(head, head2);

        return ans;
        
    }
};
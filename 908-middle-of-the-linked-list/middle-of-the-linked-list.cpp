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

    int getLength(ListNode *head){

        ListNode *temp=head;
        int count=0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;

    }

    ListNode* middleNode(ListNode* head) {

        //this is TORTOISE Algorithm - fast ptr agar 2 steps chala tab slow 1 step chalega

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast->next;
                //that is fast 2 step chala hai
                slow = slow->next;
            }    

        }
        return slow; //jaha slow hai wahi middle hai

        //*********we can solve with below approach also --> LL*****************
        // int n=getLength(head);
        // int position = n/2 + 1;

        // int currPos = 1;
        // ListNode *temp = head;

        // while(currPos != position){
        //     currPos++;
        //     temp = temp->next;
        // }
        // return temp;        
    }
};
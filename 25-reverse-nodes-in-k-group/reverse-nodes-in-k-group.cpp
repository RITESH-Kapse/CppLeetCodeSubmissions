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
        ListNode *temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        //base cases
        if(head == NULL ){
            return head;
        }

        if(head->next == NULL){
            return head;
        }

        //solve 1 case [reverse shuruwati K nodes] - baki recursion dekhega
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *nextNode = curr->next; //ye first half break honepe kam aaega - to join back
        int pos = 0;
        int len = getLength(head);

        if(len < k){
            return head;
        }


        while(pos < k){
            pos++;
            nextNode=curr->next;
            curr->next=prev;
            prev=curr ;
            curr=nextNode;
        }

        ListNode *RecursionAns = NULL;
        //aab recursion dekhega
        if(nextNode != NULL){

            RecursionAns=reverseKGroup(nextNode, k);
            head->next=RecursionAns;

        }

        return prev;
        
    }
};
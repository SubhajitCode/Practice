/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* merge(ListNode* first,ListNode* second)
 {
     if(!first)
        return second;
     if(!second)
        return first;
     ListNode* head=NULL;
     if(first->val>second->val)
     {
         head=second;
         second=second->next;
     }
     else
     {
         head=first;
         first=first->next;
     }
     ListNode* ret=head;
    while(first&&second)
    {
        if(first->val>second->val)
         {
             head->next=second;
             second=second->next;
         }
         else
         {
             head->next=first;
             first=first->next;
         }
         head=head->next;
    }
    if(first)
    head->next=first;
    else
    head->next=second;
    return ret;
         
 }
ListNode* Solution::sortList(ListNode* A) {
    if(!A||!A->next)
    return A;
    ListNode *end=A->next;
    ListNode* middle=A;
    ListNode* head=A;
    while(end&&end->next)
    {
        middle=middle->next;
        end=end->next->next;
    }
    ListNode* head2=middle->next;
    middle->next=NULL;
    return merge(sortList(head),sortList(head2));
    
    
}

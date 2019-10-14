#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    void insert(Node **t,int value)
    {
        Node *newnode,*temp;
        newnode= new Node;
        newnode->data=value;
        newnode->next=NULL;
        temp=*t;
        if(*t==NULL)
        {
            *t=newnode;
             
        }
        else
        {
            while(temp->next!=NULL)
            {
            temp=temp->next;
            }
            temp->next=newnode;
        }
        
    }
    
    void mergelink(Node **a, Node **b)
    {
        Node *temp = new Node;
        temp->next = NULL;
        Node *dummy=temp;
        

        while((*a)!=NULL && (*b)!=NULL)
        {
            if((*a)->data < (*b)->data)
            {
                if(dummy->next==NULL)
                 dummy->next=(*a);
                temp->next=(*a);
                temp=temp->next;
                (*a)=(*a)->next;
            }
            else
            {
                if(dummy->next==NULL)
                 dummy->next=(*b);
                temp->next=(*b);
                temp=temp->next;
                (*b)=(*b)->next;
            }
        }
        while((*a)!=NULL)
        temp->next=(*a);

        while((*b)!=NULL)
        temp->next = (*b);
        Node *newHead = dummy;

        while(dummy!=NULL)
        {
            
            dummy=dummy->next;
            cout<<dummy->data<<" ";
        }
        free(newHead);
    }

};
void print(Node* head)
{
   while(head!=NULL)
   {

   	cout<<head->data<<" ";
	head=head->next;
   }
   cout<<endl;
}
int main()
{
    Node *temp,*head1=NULL,*head2=NULL;
    temp->insert(&head1,1);
    temp->insert(&head1,2);
    temp->insert(&head1,4);
    temp->insert(&head1,6);
    temp->insert(&head2,3);
    temp->insert(&head2,5);
    temp->insert(&head2,7);

    temp->mergelink(&head1,&head2);
/*    else
    temp->mergelink(&head2,&head1);*/
    
  return 0;



}

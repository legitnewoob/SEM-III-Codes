#include <stdlib.h>
#include <stdio.h>


struct Node
{
   int data;
   struct Node* next;
};


void insertatbegg(struct Node** pointertohead,int x)
{
   struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
   temp->data= x;
   // alter-->
   temp->next=*pointertohead;
   
   *pointertohead=temp;
   // temp->next=head;
   // head=temp; 
   
}
void insertatbeg( struct Node** head, int x)
{
    struct Node* temp1= *head;
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next= NULL;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;

}

void revLL(struct Node** head)
{
   struct Node *current,* next, *prev;
   current=*head;
   prev= NULL;
   while(current!=NULL)
{
    next= current->next;
    current->next= prev;
    prev=current;
    current= next; 
}
*head= prev;
}

// void revLLrec(struct Node** head)
// {
  
//    struct Node* temp1=*head;
//     if(temp1->next==NULL)
//     {
        
//         return;
//     }
//     revLLrec(&(temp->next));
   

// }
void printrec(struct Node* head)
{
    // struct Node* a=*head;
    if(head==NULL)
    {
      printf("\n");
      return;
    }
    printf("%d ",head -> data);
    printrec(head -> next); 
    
}
void print(struct Node ** head)
{ 
    struct Node* temp1=*head;
    while(temp1)
    {
        printf("%d ", temp1 -> data);
        temp1 = temp1 -> next;
    }
    printf("\n");
}
int main()
{
     struct Node * head= NULL;
     insertatbegg(&head,10);   
     insertatbegg(&head,6);     
     insertatbegg(&head,7);     
     insertatbegg(&head,8);
     insertatbegg(&head,4);  
    //  printf("5");   
     
     print(&head);
     revLLrec(head); 
     print(&head);
}

#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

 void push(struct Node** head, int x)
{

    
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));

    temp->data=x;
    temp->next=(*head);
    (*head)=temp;
}

void pop(struct Node** head)
{
     if(!head)
     {
        printf("Stack is empty");
        return;
    }
    struct Node* temp, *temp2;
    temp2= (*head)->next;
    temp= (*head);
    (*head)= temp2;
    temp->next= NULL;
    free(temp);
}



void print(struct Node* head){

   // struct Node* temp= head; // Node* temp= head ==> C++
   struct Node* temp= head;
   printf("List is- \n");
   while(temp!= NULL)
   {
       printf("%d ", temp->data);
       temp=temp->next;

   }
   printf("\n");
}

int main()
{
   
   struct Node* head= NULL;
   
   push(&head,33);
   push(&head,34);
   push(&head,332);
   push(&head,342);
   push(&head,3424);
   pop(&head);
   pop(&head);
   print(head);
   


}

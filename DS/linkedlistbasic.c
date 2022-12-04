#include <stdio.h>
#include<stdlib.h>


struct Node
{ 
   int data;
   struct Node* next; // Node* next; in -->C++ 
};
// struct Node* head; //When not declared globally
// head=NULL; // Empty-list; 

// Node*temp= new Node(); ==>C++ (new for C++);
void insertatbeg(struct Node** pointertohead,int x)
{
   struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
   temp->data= x;
   // alter-->
   temp->next=NULL;
   if(*pointertohead!=NULL)temp->next=*pointertohead;
   *pointertohead=temp;
   // temp->next=head;
   // head=temp; 
   
}

void print(struct Node* head){

   // struct Node* temp= head; // Node* temp= head ==> C++
   printf("List is- \n");
   while(head!= NULL)
   {
       printf("%d ", head->data);
       head=head->next;

   }
   printf("\n");
}


int main()
{
   struct Node* head=NULL; // empty list;
   printf("How many numbers?\n");
   int n,x;
   scanf("%d",&n);
   printf("Enter the numbers:\n");
   for(int i=0;i<n;i++)
   {
      
      scanf("%d",&x);
      insertatbeg(&head,x);
      
   }
   print(head);


}

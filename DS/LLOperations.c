#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>


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

void insertatk(struct Node** head2,int input,int n)
{
   struct Node* temp1= (struct Node*)malloc(sizeof(struct Node));// Node* temp1 = new Node(); ==>C++;
   temp1->data= input; 
   temp1->next= NULL;
   if(n==1){
      temp1->next= *head2;
      *head2=temp1;
      return;
   }
   struct Node* temp2= *head2;
   for(int i=0;i<n-2;++i) 
   {
      temp2=temp2->next;
   }
   temp1->next= temp2->next;
   temp2->next=temp1;
   
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
   struct Node* head=NULL; // empṇty list;
   printf("Welcome to linked list\n");

   printf("Please make a choice");
int x=0;
   while(x!=4)
   {
      printf("\n1.Add a no. at beginning\n2.Add no. at kth position\n3.Print the linked list\n4.Exit the program\n");
      printf("Enter your choice :");
      scanf("%d",&x);
      if(x==1)
      {
         int input;
         printf("Please enter the number to be inserted->");
         scanf("%d",&input);

         insertatbeg(&head,input);
      }
      else if(x==2)
      {
         printf("Enter the number and position");
         int number,position;
         scanf("%d %d",&number,&position);
         printf("\n%d %d ",number,position);
         insertatk(&head,number,position);
        


      }
      else if(x==3)
      {
         print(head);
      }
      else if(x==4)
      {
         printf("Bye Bye");
         break;
      }
   }
   
  


}

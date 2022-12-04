#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>


struct Node
{ 
   int data;
   struct Node* next;  // Node* next; in -->C++ 
};
// struct Node* head; //When not declared globally
// head=NULL; // Empty-list; 

// Node*temp= new Node(); ==>C++ (new for C++);
void insertatbeg(struct Node** pointertohead,int x)
{
   struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
   temp->data= x;
   // alter-->
   temp->next=*pointertohead;
   
   *pointertohead=temp;
   // temp->next=head;
   // head=temp; 
   
}

void insertatend(struct Node** head, int x)
{

   if(*head!=NULL)
   { printf("Please insert a no. at beginning first!");
     return;
   }
    struct Node* temp1=*head;

    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;

    while(temp1->next!= NULL)
    {
      temp1= temp1->next;
    }
    temp1->next=temp;


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

void deletenode(struct Node **head,int pos)
{
   struct Node* temp1=*head;

   for(int i=0;i<pos-2;i++)
   {
   temp1=temp1->next;
   
   }
   struct Node* temp2=temp1->next;
   temp1->next= temp2->next;
   free(temp2); // delete temp2; if new node() used C++;
}
void deletevalue(struct Node**head,int value)
{
   struct Node *temp1=*head;
   struct Node *temp2;
    while(temp1->data!=value)
    {
      temp2=temp1;
      temp1=temp1->next;
    }  
    temp2->next=temp1->next;
    free(temp1);
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
   while(x!=6)
   {
      printf("\n1.Add a no. at beginning\n2.Add no. at kth position\n3.Delete a node by value\n4. Delete node by position\n4.Print the linked list\n5.Exit the program\n");
      printf("Enter your choice :");
      scanf("%d",&x);
      if(x==1)
      {
         int input;
         printf("Please enter the number to be inserted->");
         scanf("%d",&input);

         insertatbeg(&head,input);
      }
      else if(x==10)
      {
         int input;
         printf("Please enter the number to be inserted->");
         scanf("%d",&input);

         insertatend(&head,input);
      }
      else if(x==2)
      {
         printf("Enter the number and position");
         int number,position;
         scanf("%d %d",&number,&position);
         // printf("\n%d %d ",number,position);
         insertatk(&head,number,position);
        


      }
      else if(x==3)
      {
         printf("Enter value of node to be deleted :");
         int value;
         scanf("%d",&value);

         deletevalue(&head,value);
      }
      else if(x==4)
      {
         printf("Enter position of node to be deleted :");
         int pos;
         scanf("%d",&pos);
         deletenode(&head,pos);
      }
      else if(x==5)
      {
         print(head);
      }
      else if(x==6)
      {
         printf("Bye Bye");
         break;
      }

   }
   
  


}

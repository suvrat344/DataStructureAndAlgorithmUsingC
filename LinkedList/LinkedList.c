// Single Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};


void display(struct node *);
void count_nodes(struct node *);
void add_at_end(struct node *,int);
void add_at_beg(struct node **,int);


int main(){
  struct node *head = malloc(sizeof(struct node));

  head -> data = 45;
  head -> link = NULL;

  struct node *current = malloc(sizeof(struct node));

  current -> data = 98;
  current -> link = NULL;
  head -> link = current;

  current = malloc(sizeof(struct node));
  current -> data = 3;
  current -> link = NULL;
  head -> link -> link = current;

  count_nodes(head);
  add_at_end(head,25);
  add_at_beg(&head,7);
  display(head);

  return 0;
}



// Display Nodes
void display(struct node *head){
  struct node *ptr;
  ptr = head;
  if(ptr == NULL){
    printf("Linked List is Empty");
  }

  while (ptr != NULL)
  {
    printf("%d ",ptr -> data);
    ptr = ptr -> link;
  }
}



// Count Nodes
void count_nodes(struct node *head){
  struct node *ptr;
  int count = 0;
  ptr = head;

  if(ptr == NULL){
    printf("Linked List is Empty.");
  }
  while(ptr != NULL){
    count++;
    ptr = ptr -> link;
  }
  printf("\nTotal Nodes : %d\n",count);
}



// Insert At The End
void add_at_end(struct node *head,int data){
  struct node *ptr,*temp;

  ptr = head;
  temp = (struct node *)malloc(sizeof(struct node));
  temp -> data = data;
  temp -> link = NULL;

  while(ptr -> link != NULL){
    ptr = ptr -> link;
  }
  ptr -> link = temp;
}



// Insert At The Beginning
// Method1
// struct node *add_at_beg(struct node *head,int data){
//   struct node *ptr = (struct node *)malloc(sizeof(struct node));
//   ptr -> data = data;
//   ptr -> link = head;
//   head = ptr;
//   return head;
// }

// Insert At The Beginning
// Method2
void add_at_beg(struct node **head,int data){
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr -> data = data;
  ptr -> link = *head;
  *head = ptr;
}
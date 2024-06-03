// Single Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};


void display(struct node *);
void count_nodes(struct node *);


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

  display(head);
  count_nodes(head);

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
    printf("Data : %d ",ptr -> data);
    printf("Address : %d\n",ptr -> link);

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
  printf("Total Nodes : %d",count);
}

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{//creates and defines a struct called node
  int n;
  struct node *next;
} node;
node *head;
void append(int entry)
{//appends entry to end of the list
  node *temp = (node*)malloc(sizeof(node));
  node *end = head;//creating a pointer-to-node that will eventually reach end of linked list
  temp->n = entry;//accessing the n variable of temp through reference
  temp->next = NULL;//initializing next (pointer-to-node) to NULL since we're appending
  if (head == NULL)
  {//if list is empty
    head = temp;
  }
  else
  {//traversing list
    while (end->next != NULL)
    {
      end = end->next;
    }
    end->next = temp;
  }
}
void delete(int position)
{//choosing position to delete
  int i = 0;
  node *temp = head;
  node *temp1;
  if (position == 1)
  {//if list has one element
    head = head->next;
    free(temp);
  }
  else
  {//traversing list until program reaches the node prior to the desired node to be deleted
    while (i < position - 1)
    {
      temp = temp->next;
      i++;
    }//set temp1 = node after desired node to-be-deleted
    temp1 = temp->next->next;
    free(temp->next);
    temp->next = temp1;//establishing link between (n-1)th node and (n+1)th node
  }
}
void print()
{//print function
  node *temp = head;//declare temp pointer
  printf("List is: ");
  while (temp != NULL)//temp does not equal null until the last bit of data is printed
  {
    printf(" %d",temp->n); //prints the data that temp is pointing to
    temp = temp->next;        //temp is now set to the next pointer
  }
  printf("\n");
}
int main()
{
  head = NULL;
  int SIZE, i, entry, position;
  printf("Enter size of list: ");
  scanf("%d", &SIZE);
  printf("Creating list...\n\n");
  for (i = 0; i < SIZE; i++)
  {
    printf("Enter number: ");
    scanf("%d", &entry);
    append(entry);
    print();
  }
  printf("Choose node to delete [starting from 0]: ");
  scanf("%d", &position);
  delete(position);
  print();
  return 0;
}

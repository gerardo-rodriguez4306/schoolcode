#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int n;
  struct node *next;
} node;
node *head;
void append(int entry)
{
  node *temp = (node*)malloc(sizeof(node));
  node *end = head;
  temp->n = entry;
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    while (end->next != NULL)
    {
      end = end->next;
    }
    end->next = temp;
  }
}
void delete(int position)
{
  int i = 0;
  node *temp = head;
  node *temp1;
  if (position == 1)
  {
    head = head->next;
    free(temp);
  }
  else
  {
    while (i < position - 1)
    {
      temp = temp->next;
      i++;
    }
    temp1 = temp->next->next;
    free(temp->next);
    temp->next = temp1;
  }
}
void print()
{
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

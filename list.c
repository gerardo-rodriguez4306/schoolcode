#include <stdio.h>
#include <stdlib.h>
typedef struct node //creating your node struct (contains data and pointer)
{
  int data;
  struct node *next;
} node;             /*  defines a type called node (instead of typing struct node variablename,
                        just type node variablename)
                        You don't have to use this notation, but the implementation
                        facilitates the usage in further functions.
                        Instead of typing:          struct node name;
                        you type         :          node name;
                        The same implementation is true when you're allocating memory;
                        instead of typing:           (struct node*)malloc(sizeof(struct node));
                        you type         :           (node*)malloc(sizeof(node));
                        It's easier, right?
                    */

node *head;         //points to the first element in the list
void freeList(node *head)
{
  node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}
void insert(int j)  //inserts an integer into your list
{
  node *temp = (node*)malloc(sizeof(node));//has your temp variable stored in the heap
  temp->data = j;   //sets the data that temp is pointing to to j
  temp->next = head;//sets the pointer that temp is pointing to to head(1st iteration is NULL)
  head = temp;      //sets head pointer to temp (which should always be your first node)
}
void print()
{
  node *temp = head;//declare temp pointer
  printf("List is: ");
  while (temp != NULL)//temp does not equal null until the last bit of data is printed
  {
    printf(" %d",temp->data); //prints the data that temp is pointing to
    temp = temp->next;        //temp is now set to the next pointer
  }
  printf("\n");
}
int main()
{
  head = NULL;      //head is set to NULL which is the last 'next' value in set of linked list
  int size,i,j;
  printf("Please enter size of list: ");
  scanf("%d",&size);
  for (i = 0; i < size; i++)
  {
    printf("Please enter number: \n");
    scanf("%d",&j);
    insert(j);
    print();
  }
  printf("Done writing list.\n");
  freeList(head);
  printf("Done freeing allocated data.\n");
}

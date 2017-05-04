/*
  This program creates a linked list with student information;
  the information stored is their first name, last name, GPA, and
  zip code. The data structure used is a linked list. The user is prompted
  with a menu of options and the program runs until the user decides to quit.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct file
{ //declaring a file structure to organize all the data for the student
  char first[20];
  char last[20];
  double score;
  char zip[5];
} file;//calling it file so we don't write (struct) all the time
typedef struct node
{ //there is a struct within this struct; code can get complicated so
  file record;//give this a good look
  struct node* next;
} node;
node *head;//global variable(GV) for head pointer
int size = 0;//GV for size; this way you update the size of your
             //list every time you delete or add a node and makes
             //the program faster. You won't need to traverse the
             //list every time to find out the size of it.
void add(file student)
{//simple linked list insert function
  node *temp = (node*)malloc(sizeof(node));
  temp->record = student;
  temp->next = head;
  head = temp;
}
void printOne(node* temp)
{//this prints ONE record
  printf("\nPrinting record...\n");
  printf("First name: %s\n", temp->record.first);
  printf("Last name: %s\n", temp->record.last);
  printf("GPA: %lf\n", temp->record.score);
  printf("Zip code: %s\n\n",temp->record.zip);
}
void print()
{//this prints ALL records
  printf("Printing record...\n");
  node *temp = head;
  while (temp != NULL)
  {
    printf("First name: %s\n", temp->record.first);
    printf("Last name: %s\n", temp->record.last);
    printf("GPA: %lf\n", temp->record.score);
    printf("Zip code: %s\n",temp->record.zip);
    temp = temp->next;
    printf("\n\n");
  }
}
void addRecord()
{ //adds a single record
  file temp;
  printf("Enter first name: ");
  scanf("%s", temp.first);
  printf("Enter last name: ");
  scanf("%s", temp.last);
  printf("Enter GPA [0-100]: ");
  scanf("%lf", &temp.score);
  printf("Enter zip code: ");
  scanf("%s", temp.zip);
  add(temp);
  size++;//update size of list
}
int countSearch(char lastname[])
{ //searches the position of the record with appropriate last name
  node* temp = head; int counter = 0;
  int comparison;
  while (comparison != 0)
  {
    comparison = strcmp(lastname, temp->record.last);
    temp = temp->next;
    counter++;//counts until you reach the position the last name is at
  }
  return counter;
}
void deleteRecord(char lastname[])
{
  node* temp = head; int i = 0;
  node* temp1;
  if (temp == NULL)
  {
    printf("Cannot allocate memory!\n\nExiting...\n"); exit(0);
  }
  int comparison = strcmp(lastname, temp->record.last);

  if (comparison == 0)
  {
    head = temp->next;
    free(temp);
    printf("Done deleting...\nPrinting menu...\n");
    size--;//size update
    return;
  }
  else
  {
    int location = countSearch(lastname);
    while (i < location - 2)
    {
      temp = temp->next;
      i++;
    }
    temp1 = temp->next->next;
    free(temp->next);
    temp->next = temp1;
    printf("Done deleting...\nPrinting menu...\n");
    size--;//size update
    return;
  }
}
void searchZip(char zip[])
{//searches by zipcode; you traverse list using GV size
  node* temp = head;
  int i = 0; int comparison;
  while (i < size)
  {
    comparison = strcmp(zip, temp->record.zip);
    if (comparison == 0)
      printOne(temp);
    temp = temp->next;
    i++;
  }
}
void rangeSearch(double range[])
{//searches list and prints records in the range
  node* temp = head; int i;
  double current;
  while (i < size)
  { //comparing current score to ranges
    current = temp->record.score;
    if (current >= range[0] && current <= range[1])
    {
      printOne(temp);
    }
    temp = temp->next;
    i++;//two updates necessary; if you don't update temp, you'll
        //print the same value I many times
  }
}
void bubblesort(double *scores)
{//simple sorting algorithm
  int i, j; double temp;
  for (i = 0; i < size - 1; i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if ((*scores + i) < *(scores + j))
      {
        temp = *(scores + i);
        *(scores + i) = *(scores + j);
        *(scores + j) = temp;
      }
    }
  }
}
void findMedian()//sorting is required
{
  node* temp = head;
  double *scores = (double*)malloc(sizeof(double) * size);
    if (scores == NULL)
    {
      printf("Cannot allocate memory!\n\nExiting...\n");
      exit(0);
    }
  int i = 0;
  while (i < size)//adding values into dynamic array
  {
    *(scores + i) = temp->record.score;
    temp = temp->next;
    i++;
  }
  bubblesort(scores);
  printf("Median score is: %lf", *(scores + (size/2)));
  printf("\n%d students are above median.\nPrinting menu...\n\n", (size/2));
}
void freeMemory()
{
  node* temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}
int main()
{
  file student;
  int i, choice;
  double range[2];
  char lastname[20]; char zipcode[5];
  head = NULL;
  printf("Enter number of records: ");
  scanf("%d", &size);
  for (i = 0; i < size; i++)
  {
    printf("Enter first name: ");
    scanf("%s", student.first);
    printf("Enter last name: ");
    scanf("%s", student.last);
    printf("Enter GPA [0-100]: ");
    scanf("%lf", &student.score);
    printf("Enter zip code: ");
    scanf("%s", student.zip);
    add(student);
  }
  printf("\n\n\n");
  while (1)
  {
printf("Menu:\n1. Print Records\n2. Add Record\n3. Delete Record\n4. Search by Zip Code\n5. Search by Score Range\n6. Find Median Score\n7. Exit Program\n");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
      if (head == NULL)
        printf("\nList has no records!\nPrinting menu...\n\n");
      else
        print();
      break;
      case 2:
      addRecord();
      break;
      case 3:
      if (head == NULL)
        printf("\nList has no records!\nPrinting menu...\n\n");
      else
      {
        printf("Type in last name to delete: ");
        scanf("%s", lastname);
        deleteRecord(lastname);
      }
      break;
      case 4:
      if (head == NULL)
        printf("\nList has no records!\nPrinting menu...\n\n");
      else
      {
        printf("Type in zip code for search: ");
        scanf("%s", zipcode);
        searchZip(zipcode);
      }
      break;
      case 5:
      if (head == NULL)
        printf("\nList has no records!\nPrinting menu...\n\n");
      else
      {
        printf("Enter range for search: \n");
        printf("Lower bound: ");
        scanf("%lf", &range[0]);
        printf("Upper bound: ");
        scanf("%lf", &range[1]);
        rangeSearch(range);
      }
      break;
      case 6:
      if (head == NULL)
        printf("\nList has no records!\nPrinting menu...\n\n");
      else
      {
        findMedian();
      }
      break;
      case 7://free memory before exiting
      freeMemory();
      printf("Exiting...\n\n");
      return 0;
      default:
      printf("That is not one of the choices\nPrinting menu...\n\n");
      break;
    }
  }
}

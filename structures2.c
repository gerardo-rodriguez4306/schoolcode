/*
  Involves a higher-level understanding of structs and how to access them with
  pointers. This program creates a list of students and prompts the user with
  operations to perform with values in the list. The data structure used is a
  dynamic array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct record
{//struct record is created and defined
  char firstname[20];
  char lastname[20];
  double gpa;
} record;
void printMax(record *list, int i, int SIZE)
{ //prints the name of the person with the max score along with the score
  char f[20], l[20];
  double max = (list + i)->gpa;
  for (i = 0; i < SIZE; i++)
  {
    if ((list + i)->gpa > max)
    {
      max = (list + i)->gpa;
      strcpy(f, (list + i)->firstname);//strcpy since you can't assign
      strcpy(l, (list + i)->lastname);//an array to another array
    }//for this, you can also use *(list + i).variable
  }
  printf("%s %s has the max score of %.2lf", f, l, max);
}
void printMin(record *list, int i, int SIZE)
{ //does the same as previous function, but minimum instead of max
  char f[20], l[20];
  double min = (list + i)->gpa;
  for (i = 0; i < SIZE; i++)
  {
    if ((list + i)->gpa < min)
    {
      min = (list + i)->gpa;
      strcpy(f, (list + i)->firstname);
      strcpy(l, (list + i)->lastname);
    }
  }
  printf("%s %s has the min score of %.2lf", f, l, min);
}
void searchPrint(record *list, int i, int SIZE)
{ //searches the list for an inputted name, prints the record
  //can take in either first or last name
  int boolean = 0;
  char namesearch[20];
  printf("Enter name for search: ");
  scanf("%s", namesearch);
  for (i = 0; i < SIZE; i++)
  {
    if ((strcmp(namesearch, (list + i)->firstname) == 0) || (strcmp(namesearch, (list + i)->lastname) == 0))
    {
      boolean = 1;
      printf("Name: %s ", (list + i)->firstname); printf("%s \n", (list + i)->lastname); printf("Score: %.2lf\n", (list + i)->gpa);
    }
  }
  if (boolean == 0)
  {
    printf("No record was found with that name.\n");
  }
}
void create(record *list, int i, int SIZE)
{ //creates list of structs
  while (i < SIZE)
  {
    printf("First name[max 20 characters]: ");
    scanf("%s", (list + i)->firstname);
    printf("Last name[max 20 characters]: ");
    scanf("%s", (list + i)->lastname);
    printf("GPA: ");
    scanf("%lf",&(list + i)->gpa);
    i++;
  }
}
void printAll(record *list, int SIZE)
{ //function that prints values in a struct
  int i = 0;
  printf("Printing student information: \n");
  while (i < SIZE)
  {
    printf("First Name: %s\t",(list + i)->firstname);
    printf("Last Name: %s\t",(list + i)->lastname);
    printf("Score: %.2lf",(list + i)->gpa);
    printf("\n");
    i++;
  }
}
void sortPrint(record *list, int entry, int i, int j, int SIZE)
{                              //function that sorts list of structs
  char tmpfrst[20], tmplst[20];//by ascending order based on the last name or GPA
  double tmpFlt;
  if (entry == 4)          //sorting by GPA
  {//bubble sorting algorithm
    for (i = 0; i < SIZE - 1; i++)
    {
      for (j = i + 1; j < SIZE; j++)
      {
        if ((list + i)->gpa > (list + j)->gpa)
        {
          tmpFlt = (list + i)->gpa;
          (list + i)->gpa = (list + j)->gpa;
          (list + j)->gpa = tmpFlt;
          strcpy(tmpfrst, (list + i)->lastname);
          strcpy((list + i)->lastname,(list + j)->lastname);
          strcpy((list + j)->lastname, tmpfrst);
          strcpy(tmplst, (list+ i)->firstname);
          strcpy((list + i)->firstname, (list+ j)->firstname);
          strcpy((list + j)->firstname, tmplst);
        }
      }
    }
  }
  else               //sorting by last name
  {
    for (i = 0; i < SIZE - 1; i++)
    {
      for (j = i + 1; j < SIZE; j++)
      {
        if ((list + i)->lastname[0] > (list + j)->lastname[0])
        {
          strcpy(tmpfrst, (list + i)->lastname);
          strcpy((list + i)->lastname,(list + j)->lastname);
          strcpy((list + j)->lastname, tmpfrst);
          strcpy(tmplst, (list+ i)->firstname);
          strcpy((list + i)->firstname, (list+ j)->firstname);
          strcpy((list + j)->firstname, tmplst);
          tmpFlt = (list + i)->gpa;
          (list + i)->gpa = (list + j)->gpa;
          (list + j)->gpa = tmpFlt;
        } //here, as in the other conditional, both last name and GPA must be included.
      }   //If only one part of data is manipulated, then values will
    }     //be assigned to another record that does not correspond to it.
  }
  printAll(list, SIZE);
}
int main()
{
  printf("Please enter number of desired records: \n");
  int i, j, SIZE, entry;
  scanf("%d",&SIZE);//a) Ask the user for the number of desired records as input
  record *list;
  list = (record*)malloc(sizeof(record) * SIZE);//b)dynamically allocate space
  i = 0;                                        //  for records
  printf("Please enter student data: \n");
  create(list, i, SIZE);
  while (1)
  {//use while loop to continuously prompt user until exhausted
    i = 0;//setting i & j to 0 continuously because they're manipulated almost always
    j = 0;
    printf("\nMenu: \n1. Print records\n2. Search by first name\n3. Search by last name\n4. Sort by GPA\n5. Sort by last name\n6. Find max gpa\n7. Find min score\n0. Exit the program\n");
    scanf("%d", &entry);
    switch(entry)//alternate to list of conditionals
    {            //allows easier read while providing same function
      case 1:
      printAll(list, SIZE);
      break;
      case 2:
      searchPrint(list, i, SIZE);
      break;
      case 3:
      searchPrint(list, i, SIZE);
      break;
      case 4:
      sortPrint(list, entry, i, j, SIZE);
      break;
      case 5:
      sortPrint(list, entry, i, j, SIZE);
      break;
      case 6:
      printMax(list, i, SIZE);
      break;
      case 7:
      printMin(list, i, SIZE);
      break;
      case 0:
      printf("Exiting...\n");
      return 0;
      default:
      printf("Option %d not valid. Reprinting menu: \n",entry);
      break;
    }
  }
}

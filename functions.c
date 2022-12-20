#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct node

{

char number[100];

char gmail[100];

char name[100];

struct node *prev, *next;

} *head = NULL;

struct pq

{

char number[100];

char gmail[100];

char name[100];

int priority;

struct pq *previous, *nextt;

} *top = NULL;

void createFav()

{

char name[100];

int priority;

char ans;

do

{

printf("Enter the Name of the Contact and Assign a Priority Number\n");

scanf("%[^\n]", name);

fflush(stdin);

scanf("%d", &priority);

fflush(stdin);

struct node *tmp = head;

struct pq *p, *temp1, *pr;

while (tmp != NULL)

{

if (strcmp(name, tmp->name) == 0)

{

p = (struct pq *)malloc(sizeof(struct pq));

strcpy(p->gmail, tmp->gmail);

strcpy(p->number, tmp->number);

strcpy(p->name, tmp->name);

p->priority = priority;

if (top == NULL)

{

p->nextt = p->previous = NULL;

p->priority = 1;

top = p;

}

else

{

temp1 = top;

while ((temp1->priority < priority) && (temp1->nextt != NULL))

{

temp1 = temp1->nextt;

}

if (temp1->nextt != NULL)

{

temp1->previous->nextt = p;

p->previous = temp1->previous;

p->nextt = temp1;

temp1->previous = p;

}

else

{

temp1->nextt = p;

p->nextt = NULL;

p->previous = temp1;

}

}

break;

}

tmp = tmp->next;

}

printf("Do You Want To Continue Assigning Priorities?\n");

scanf("%c", &ans);

fflush(stdin);

} while (ans == 'y');

}



void displayFav()

{

struct pq *temp = top;

printf("Displaying Favourite Contacts:\n");

while (temp != NULL)

{

printf("\nName ::\t%s\n", temp->name);

printf("Contact Number ::\t%s\n", temp->number);

printf("G-Mail ID :: \t%s\n", temp->gmail);

temp = temp->nextt;

}

}

void insert()

{

char number[100];

char gmail[100];

char name[100];

char ans;

do

{

struct node *p;

p = (struct node *)malloc(sizeof(struct node));

printf("Enter The Name of The Contact: ");

scanf("%[^\n]", name);

fflush(stdin);

strcpy(p->name, name);

printf("Enter The Phone Number    :\t");

scanf("%[^\n]", number);

fflush(stdin);



while (strlen(number) != 10)

{

printf("ENTER A VALID 10 DIGIT NUMBER  :\t");

scanf("%[^\n]", number);

fflush(stdin);

}

strcpy(p->number, number);

printf("Enter The G-Mail ID  :\t");

scanf("%[^\n]", gmail);

strcpy(p->gmail, gmail);

fflush(stdin);



if (head == NULL)

{

p->next = NULL;

p->prev = NULL;

head = p;

}

else

{

struct node *tmp = head;

while (tmp->next != NULL)

{

tmp = tmp->next;

}

p->next = NULL;

p->prev = tmp;

tmp->next = p;

}

printf("Do You Want To Continue Insertion?\n");

scanf("%c", &ans);

fflush(stdin);

} while (ans == 'y');

}

void display()

{

struct node *tmp = head;

while (tmp != NULL)

{

printf("\nNAME  ::  %s", tmp->name);

printf("\nNUMBER::  +91-%s", tmp->number);

printf("\nG-MAIL::  %s\n", tmp->gmail);

tmp = tmp->next;

}

}

void sort()

{

struct node *i, *j;

int temp;

char a[100], b[100], c[100];

for (i = head; i->next != NULL; i = i->next)

{

for (j = i->next; j != NULL; j = j->next)

{

temp = strcmp(i->name, j->name);

if (temp > 0)

{

strcpy(a, i->name);

strcpy(i->name, j->name);

strcpy(j->name, a);

strcpy(b, i->number);

strcpy(i->number, j->number);

strcpy(j->number, b);

strcpy(c, i->gmail);

strcpy(i->gmail, j->gmail);

strcpy(j->gmail, c);

}

}

}

}

void deletecontact()

{

char s[100];

printf("Enter the Name of the Contact You Wish to Delete\n");

scanf("%[^\n]", s);

fflush(stdin);

int c = 0;

struct node *tmp = head;

while (tmp != NULL)

{

if (strcmp(s, tmp->name) == 0)

{

c = 1;

break;

}

else

{

c = 2;

}

tmp = tmp->next;

}

if (!tmp)

{

printf("CONTACT NOT FOUND\n");

return;

}

if (c == 1 && tmp != head && tmp->next != NULL)

{

tmp->prev->next = tmp->next;

tmp->next->prev = tmp->prev;

free(tmp);

printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");

}

if (tmp == head)

{

head = head->next;

head->prev = NULL;

free(tmp);

printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");

}

if (tmp->next == NULL)

{

tmp->prev->next = NULL;

tmp->prev = NULL;

free(tmp);

printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");

}

}

void deletesamename()

{

struct node *tmp1 = head;

int n = 0;

while (tmp1 != NULL && tmp1->next != NULL)

{

struct node *tmp2 = tmp1;

while (tmp2->next != NULL)

{

if (strcmp(tmp1->name, tmp2->next->name) == 0)

{

struct node *dup = tmp2->next;

tmp2->next = tmp2->next->next;

free(dup);

n++;

}

else

{

tmp2 = tmp2->next;

}

}

tmp1 = tmp1->next;

}

if (!n)

printf("Same Names Not Found\n");

else

display();

}

void deletesamegmail()

{

struct node *tmp1 = head;

int n = 0;

while (tmp1 != NULL && tmp1->next != NULL)

{

struct node *tmp2 = tmp1;

while (tmp2->next != NULL)

{

if (strcmp(tmp1->gmail, tmp2->next->gmail) == 0)

{

struct node *dup = tmp2->next;

tmp2->next = tmp2->next->next;

free(dup);

n++;

}

else

{

tmp2 = tmp2->next;

}

}

tmp1 = tmp1->next;

}

if (!n)

printf("Same G-Mail IDs Not Found\n");

else

display();

}

void deletesamenumber()

{

struct node *tmp1 = head;

int n = 0;

while (tmp1 != NULL && tmp1->next != NULL)

{

struct node *tmp2 = tmp1;

while (tmp2->next != NULL)

{

if (strcmp(tmp1->number, tmp2->number) == 0)

{

struct node *dup = tmp2->next;

tmp2->next = tmp2->next->next;

free(dup);

n++;

}

else

{

tmp2 = tmp2->next;

}

}

tmp1 = tmp1->next;

}

if (!n)

printf("Same Numbers Not Found\n");

else

display();

}

void searchbyname(char *na)

{

struct node *tmp = head;

int n = 0;

while (tmp != NULL)

{

if (strcmp(na, tmp->name) == 0)

{

printf("NAME FOUND\n");

printf("CONTACT DETAILS ARE BELOW:\n");

printf("\n\nNAME  ::\t%s", tmp->name);

printf("\nNUMBER::\t+91-%s", tmp->number);

printf("\nG-MAIL::\t%s", tmp->gmail);

n++;

}

tmp = tmp->next;

}

if (!n)

printf("CONTACT NOT FOUND\n");

}

void searchbynumber(char *num)

{

struct node *tmp = head;

int n = 0;

while (tmp != NULL)

{

if (strcmp(num, tmp->number) == 0)

{

printf("NUMBER FOUND\n");

printf("CONTACT DETAILS ARE BELOW:\n");

printf("\n\nNAME  ::\t%s", tmp->name);

printf("\nNUMBER::\t+91-%s", tmp->number);

printf("\nG-MAIL::\t%s", tmp->gmail);

n++;

}

tmp = tmp->next;

}

if (!n)

printf("CONTACT NOT FOUND\n");

}

void searchbygmail(char *gm)

{

struct node *tmp = head;

int n = 0;

while (tmp != NULL)

{

if (strcmp(gm, tmp->gmail) == 0)

{

printf("G-MAIL FOUND\n");

printf("CONTACT DETAILS ARE BELOW:\n");

printf("\n\nNAME  ::\t%s", tmp->name);

printf("\nNUMBER::\t+91-%s", tmp->number);

printf("\nG-MAIL::\t%s", tmp->gmail);

n++;

}

tmp = tmp->next;

}

if (!n)

printf("CONTACT NOT FOUND\n");

}

void update()

{

char n[100];

char ans;

int c;

struct node *tmp = head;

printf("\nEnter the Name of the Contact that You Wish to Update\n");

scanf("%[^\n]", n);

fflush(stdin);

while (tmp != NULL)

{

if (strcmp(n, tmp->name) == 0)

{



do

{

printf("\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n");

scanf("%d", &c);

fflush(stdin);

switch (c)

{

case 1:

printf("Enter The New Name:\n");

scanf("%[^\n]", tmp->name);

fflush(stdin);

break;

case 2:

printf("Enter the New Phone Number:\n");

scanf("%[^\n]", tmp->number);

fflush(stdin);

while (strlen(tmp->number) != 10)

{

printf("ENTER A VALID NUMBER!  :\n");

scanf("%[^\n]", tmp->number);

fflush(stdin);

}

break;

case 3:

printf("Enter The New G-Mail ID:\n");

scanf("%[^\n]", tmp->gmail);

fflush(stdin);

break;

}

printf("Do You Wish To Continue Updating?\n");

scanf("%c", &ans);

fflush(stdin);

} while (ans == 'y');

}

tmp = tmp->next;

}

}

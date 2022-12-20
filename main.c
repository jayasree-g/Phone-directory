int main()

{

char n[100];

char nam[100];

char name[100];

char number[100];

char gmail[100];

char ans;

int ch, a;

printf("**************************************  PHONE BOOK  ************************************** \n");

printf("\n\nWHAT IS YOUR NAME?\n");

scanf("%[^\n]", name);


printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  Welcome %s  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", name);

printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LET'S CREATE OUR PHONEBOOK !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

insert();

sort();

while (1)

{

printf("\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) DELETE SAME GMAIL-ID IN PHONEBOOK\n8) SEARCH\n9) CREATE FAVOURITE CONTACTS\n10) DISPLAY FAVOURITE CONTACTS\n");

scanf("%d", &ch);



switch (ch)

{

case 1:

display(); // Displays the contact list

break;



case 2:

insert(); // Inserts a new contact to the existing contact list

sort();

break;

case 3:

update(); // Updates the information needed of the given contact

sort();

break;

case 4:

deletecontact(); // Deletes contact with the given name

break;



case 5:

deletesamename(); // Deletes contacts with duplicate name other than the contact with first entry with the given name

break;



case 6:

deletesamenumber(); // Deletes contacts with duplicate number other than the contact with first entry with the given number

break;

case 7:

deletesamegmail(); // Deletes contacts with duplicate G-Mail ID other than the contact with first entry with the given G-Mail ID

break;

case 8:

do

{

printf("1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL\n");

scanf("%d", &a);


switch (a)

{

case 1:

printf("\nENTER THE NAME TO BE SEARCHED\n");

scanf("%[^\n]", name);



searchbyname(name);  // Searches contact based on the name

break;

case 2:

printf("ENTER THE NUMBER TO BE SEARCHED\n");

scanf("%[^\n]", number);



searchbynumber(number); // Searches contact based on the number

break;

case 3:

printf("ENTER THE GMAIL ID TO BE SEARCHED\n");

scanf("%[^\n]", gmail);



searchbygmail(gmail); // Searches contact based on the G-Mail ID

break;

default:

printf("\nNO PROPER INPUT GIVEN.....\n");

}

printf("\nDO YOU WANT TO CONTINUE SEARCHING?????????\n");

scanf("%c", &ans);



} while (ans == 'y');



break;



case 9:

createFav();

break;

case 10:

displayFav();

break;

default:

printf("\nENTER A VALID INPUT\n");

break;

}



printf("\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????\n");

scanf("%c", &ans);

if (ans != 'y')

break;



}

} 
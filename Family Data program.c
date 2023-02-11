/*C program by Abdullah MMohammad Mahi for CS 1310

 o            o
  \          /
   \        /
    :-'""'-:
 .-'  ____  `-.
( (  (_()_)  ) )
 `-.   ^^   .-'
    `._==_.'
    __)(___
*this program assigns family information to structures  
*read in data from familyin.txt file which was created using  
*notepad and output each person's name, street address, city, 
*zip-code, relation to programmer and birthday to the screen 
*and to the file familyout.txt  
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct family{ /* record people information in family struct */
              char name [50];     /*people's name */
			  char street [50];   /* street address */ 
			  char csz [50];      /* city, state, zip */
			  char relation [50]; /* relation to you */
              char birthday [30]; /* mm-dd-yyyy */
		    };
struct family peoples [7];
void main (void)
{
 FILE *Familydatain, *Familydataout; /*file pointers*/
 int i, m;
 
 /*opening familyin.txt file in reading mode*/
 Familydatain = fopen("familyin.txt", "r");
  
 	
 for(m = 0; m < 7; m++) /*m stands for each person, going from 0 to 6*/
  { /*reading data from familyin.txt by using pointer*/
	fgets(peoples[m].name, 50, Familydatain);
	fgets(peoples[m].street, 50, Familydatain);
	fgets(peoples[m].csz, 50, Familydatain);
	fgets(peoples[m].relation, 50, Familydatain);
	fgets(peoples[m].birthday, 50, Familydatain);
  }
  
  /*opening familyout.txt file in writing mode*/
  Familydataout = fopen("familyout.txt", "w");
   	
  for(i = 0; i < 7; i++)  
	{   int m, j;   /*countering every character for birth year*/
		char mon[2], day[2]; 
		char birth_mon[15], birth_day[2], birth_yr[4]; /*birth_mon is for storing month name*/
		
		/*profeesor's direction in class*/
		strtok(peoples[i].name, "\n");
		strtok(peoples[i].street, "\n");
		strtok(peoples[i].csz, "\n");
		strtok(peoples[i].relation, "\n");
		strtok(peoples[i].birthday, "\n");

		/*taking out only birth year from whole birthday data*/ 
		for( m=0, j=6; m<4, j<10; m++, j++) /*m 1st char of birth_yr, copying position 6th char from birthday*/
		  	{ birth_yr[m] = peoples[i].birthday[j]; }
			  	  
		/*converting birth string 'year' into integer*/	  	
		int age = 2022 - atoi(birth_yr);
		
		/*converting string 'month' into integer*/
		mon[0] = peoples[i].birthday[0];
		mon[1] = peoples[i].birthday[1];
		int BirthMonth = atoi(mon);
		
		/*assigning month name for every integer, from 0 to 12*/
		switch (BirthMonth)
		{
			case 1:
				strcpy(birth_mon, "January");
				break;
			case 2:
				strcpy(birth_mon, "February");
				break;
			case 3:
				strcpy(birth_mon, "March");
				break;
			case 4:
				strcpy(birth_mon, "April");
				break;
			case 5:
				strcpy(birth_mon, "May");
				break;
			case 6:
				strcpy(birth_mon, "June");
				break;
			case 7:
				strcpy(birth_mon, "July");
				break;
			case 8:
				strcpy(birth_mon, "August");
				break;
			case 9:
				strcpy(birth_mon, "September");
				break;
			case 10:
				strcpy(birth_mon, "October");
				break;
			case 11:
				strcpy(birth_mon, "November");
				break;
			case 12:
				strcpy(birth_mon, "December");
				break;
			default:
				printf("404 !! Are You Kidding Me :) \n");	
		}	
		/*storing date into 'birthday' string from people's birthday information*/
		if(peoples[i].birthday[3]!= "0") 
		   {birth_day[0] = peoples[i].birthday[3];
			birth_day[1] = peoples[i].birthday[4];}
		else 
		   {birth_day[0] = peoples[i].birthday[3];
		    birth_day[1] = peoples[i].birthday[4];}
		
		/*printing people's name, relationship in c program and the Familyout file*/
		printf("%-40s    Relation: %s\n", peoples[i].name, peoples[i].relation);
		fprintf(Familydataout, "%-40s    Relation: %s\n", peoples[i].name, peoples[i].relation);
		
		/*printing people's street, birth month, day, year in c program and the Familyout file*/
		printf("%-40s    Birthday: %s %s, %s\n", peoples[i].street, birth_mon, birth_day, birth_yr);
		fprintf(Familydataout, "%-40s    Birthday: %s %s, %s\n", peoples[i].street, birth_mon, birth_day, birth_yr);
		
		/*printing people's age in c program and the Familyout file*/
		printf("%-40s    Age: %i\n\n", peoples[i].csz, age);
	    fprintf(Familydataout, "%-40s    Age: %i\n\n", peoples[i].csz, age);
		
	}
	/*closing files*/
	fclose(Familydatain);
	fclose(Familydataout);	
}
		


#include <stdio.h>
int main(){
 int daynumber, startday, dayoftheweek;
 startday=3;
 printf("Enter the number of the day ");
 scanf("%d",&daynumber);
 dayoftheweek=(daynumber+startday-1)%7;
 switch (dayoftheweek) {
	 case 1:
	 printf ("Monday");
	 break;
	 case 2:
	 printf ("Tuesday");
	 break;
	 case 3:
	 printf ("Wednesday");
	 break;
	 case 4:
	 printf ("Thursday");
	 break;
	 case 5:
	 printf ("Friday");
	 break;
	 case 6:
	 printf ("Saturday");
	 break;
	 case 0: 
	 printf ("Sunday");
     break;
 }
 
}
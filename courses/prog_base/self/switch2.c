#include <stdio.h>
int main() {
	int month_day;
	printf("Enter the number of the day ");
	scanf("%d",&month_day);
	switch (month_day) {
	case 1:
	case 8:
	case 15:
	case 22:
	case 29:
	printf("Wednesday");
	break;
	case 2:
	case 9:
	case 16:
	case 23:
	case 30:
	printf("Thursday");
	break;
	case 3:
	case 10:
	case 17:
	case 24:
	case 31:
	printf("Friday");
	break;
	case 4:
	case 11:
	case 18:
	case 25:
	printf("Saturday");
	break;
	case 5:
	case 12:
	case 19:
	case 26:
	printf("Sunday");
	break;
	case 6:
	case 13:
	case 20:
	case 27:
	printf("Monday");
	break;
	case 7:
	case 14:
	case 21:
	case 28:
	printf("Tuesday");
	break;
}
}
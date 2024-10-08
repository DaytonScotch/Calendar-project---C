#include <stdio.h>
#include <stdlib.h>

int getFirstWeekday(int year) {

	int d;
	d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
	return d;//Simplified version of Zeller Congruence since only first day of month is needed
}

int main() {

	int year, month, day, daysInMonth, weekDay=0, startingDay;

	system("Color BF");
	printf("\nEnter any year to see the calendar: ");
	scanf_s("%d", &year);

	const char* months[] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };//String array for all 12 months
	int monthDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };// int array for number of days in each month

	if (year%4==0 && year%100!=0 || year%400==0)
		monthDay[1] = 29; //Condition for leap year

	startingDay = getFirstWeekday(year);

	for (month=0; month<12; ++month) {

		daysInMonth = monthDay[month];
		printf("\n\n----------------%s----------------\n", months[month]);
		printf("\n  Sun  Mon  Tue  Wed  Thur  Fri  Sat\n");

		for (weekDay = 0; weekDay < startingDay; ++weekDay) {
			printf("     ");
		}

		for (day=1; day<=daysInMonth; ++day) {
			printf("%5d", day);

			if (++weekDay > 6) {
				printf("\n");
				weekDay = 0;
			}
			startingDay = weekDay;
		}
	}


}
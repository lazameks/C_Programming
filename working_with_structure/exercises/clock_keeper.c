#include <stdio.h>
#include <stdbool.h>

struct date
{
	int month;
	int day;
	int year;
};

struct time
{
	int hour;
	int minutes;
	int seconds;
};

struct dateAndTime
{
	struct date sDate;
	struct time sTime;
};

// function to update date and time.

struct dateAndTime clockKeeper ( struct dateAndTime previous )
{
	struct dateAndTime current;
	struct time timeUpdate(struct time now);
	struct date dateUpdate (struct date today);

	current.sTime = timeUpdate(previous.sTime);

	if (current.sTime.hour == 0 && current.sTime.minutes == 0 && current.sTime.seconds == 0)
		current.sDate = dateUpdate(previous.sDate);
	else
		current.sDate = previous.sDate;

	return (current);
}

// Function to update time.
struct time timeUpdate(struct time now)
{
        ++now.seconds;

        if (now.seconds == 60)
        {
                now.seconds = 0;
                ++now.minutes;

                if (now.minutes == 60)
                {
                        now.minutes = 0;
                        ++now.hour;

                        if (now.hour == 24)
                                now.hour = 0;
                }
        }

        return (now);
}


// function to calculate tomorrow's date
struct date dateUpdate (struct date today)
{
        struct date tomorrow;
        int numberOfDays (struct date d);

        if ( today.day != numberOfDays(today) )
        {
                tomorrow.day = today.day + 1;
                tomorrow.month = today.month;
                tomorrow.year = today.year;
        }
        else if ( today.month == 12 )   //End of the year
        {
                tomorrow.day = 1;
                tomorrow.month = 1;
                tomorrow.year = today.year + 1;
        }
        else                            // End of the month
        {

                tomorrow.day = 1;
                tomorrow.month = today.month + 1;
                tomorrow.year = today.year;
        }

        return (tomorrow);
}

//Function to calculate number of days

int numberOfDays(struct date d)
{
        bool isLeapYear(struct date d);
        int days;
        const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (isLeapYear (d) == true && d.month == 2)
                days == 29;
        else
                days = daysPerMonth[d.month - 1];

        return (days);
}

//Function to calculate leapyear
bool isLeapYear (struct date d)
{
        bool leapYearFlag;

        if (( d.year % 4 == 0 && d.year % 100 != 0 ) || d.year % 400 == 0 )
                leapYearFlag = true;
        else
                leapYearFlag = false;

        return ( leapYearFlag );
}

int main (void)
{
	struct dateAndTime moment, nextMoment;
	struct dateAndTime clockKeeper ( struct dateAndTime previous);

	printf ("\nHey there, it is good you want to find out what the next moment will be\nlet's start by taking a moment and then we will show yo what the next moment will be by seconds\n\n");

	printf ("Enter date and time (mm dd yyyy hh:mm:ss)\n");
	scanf("%i %i %i %i:%i:%i", &moment.sDate.month, &moment.sDate.day, &moment.sDate.year, &moment.sTime.hour, &moment.sTime.minutes, &moment.sTime.seconds);

	nextMoment = clockKeeper (moment);

	printf ("The next moment will be..... \ndate: %i %i %i\ntime: %i:%i:%i\n", nextMoment.sDate.month, nextMoment.sDate.day, nextMoment.sDate.year, nextMoment.sTime.hour, nextMoment.sTime.minutes, nextMoment.sTime.seconds);

	return (0);
}

#include <stdio.h>
#include <time.h>


int main()
{
    printf("HELLO\n");

    // Get time =======================================================================
    time_t currentTime;
    char *currentTimeInString;
    struct tm *local;

    char hourDigitMSB;
    char hourDigitLSB;
    char minDigitMSB;
    char minDigitLSB;
    char secDigitMSB;
    char secDigitLSB;

    // Get current system time
    currentTime = time(NULL);
    local = localtime(&currentTime);

    printf("time --> %d : %d : %d\n", local->tm_hour, local->tm_min, local->tm_sec);

    // Check if time was successfully retreived
    if (currentTime == (time_t)-1)
    {
        printf("Failed to get the current time.\n");
    }
    else
    {
        // Convert retreived time to string
        currentTimeInString = ctime(&currentTime);

        // Check if time was successfully converted to string
        if (currentTimeInString == NULL)
        {
            printf("Failed to convert the current time.\n");
        }
        else
        {
            printf("The current time is: %s\n", currentTimeInString);

            // Retreive hour, min, sec digit information from string
            hourDigitMSB = currentTimeInString[11];
            hourDigitLSB = currentTimeInString[12];
            minDigitMSB = currentTimeInString[14];
            minDigitLSB = currentTimeInString[15];
            secDigitMSB = currentTimeInString[17];
            secDigitLSB = currentTimeInString[18];

            printf("The current time is: %c %c %c %c %c %c\n",
                hourDigitMSB,
                hourDigitLSB,
                minDigitMSB,
                minDigitLSB,
                secDigitMSB,
                secDigitLSB);

        }
    }


    // Get temperature =======================================================================


    //Get EUR to HUF exchange rate =======================================================================


    // Get gold price in HUF =======================================================================


    // Email notification =======================================================================

    return 0;
}
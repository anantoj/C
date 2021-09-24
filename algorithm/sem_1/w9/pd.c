#include <stdio.h>

char dayName[7][101] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday".
};

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int date, month, year;
        scanf("%d/%d/%d", &date, &month, &year);

        int res = 0;
        // find the residue days in a YEAR
        for (int i = 1; i < month; i++){
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                res += 31;

            else if (i == 2){
                if (year % 100 == 0){
                    if (year % 400 == 0 ){
                        res+= 29;
                    }
                }

                else if (year % 4 == 0)
                    res += 29;

                else
                    res += 28;
            }
            else{
                res += 30;
            }
        }
        res += date - 1;

        int day = 2; // starts at tuesday

        int count = 0; // variable for counting number of days per year

        for (int startyear = 1901; startyear < year; startyear++){
            if (startyear % 100 == 0){
                if (startyear % 400 == 0){
                    count += 366;
                }
            }

            else if (startyear % 4 == 0)
                count += 366;

            else
                count += 365;
     
        }
        count += res;
        count = count % 7;
  
         for (int x = 0; x < count; x++){
            day++;
            if (day == 8) day = 1;
        }
        
        printf("Case #%d: %s\n", tc+1, dayName[day-1]);
    }
}
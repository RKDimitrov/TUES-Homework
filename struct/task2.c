#include <stdio.h>
#include <stdlib.h>

typedef enum{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
}Day;

int main(){
    int day;
    printf("Enter day of the week: ");
    scanf("%d", &day);
    day--;
    switch (day)
    {
    case Monday:
        printf("Monday"); 
        break;
    case Tuesday:
        printf("Tuesday"); 
        break;
    case Wednesday:
        printf("Wednesday"); 
        break;
    case Thursday:
        printf("ThursDay");
        break;
    case Friday:
        printf("Friday");
        break;
    case Saturday:
        printf("Saturday");
        break;
    case Sunday:
        printf("Sunday");
        break;
    default:
        break;
    }    
}
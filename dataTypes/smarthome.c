#include <stdio.h>

int main()
{
    char rooms = 0;
    char room1 = 1 << 0;
    char room2 = 1 << 1;
    char room3 = 1 << 2;
    char room4 = 1 << 3;
    char room5 = 1 << 4;
    char room6 = 1 << 5;
    char room7 = 1 << 6;
    char room8 = 1 << 7;

    while (1)
    {
        int chooser;
        printf("\n 1 -t urn lights, 2 - show state , 3 - exit: ");
        scanf("%d", &chooser);

        if(chooser == 1)
        {
            int number;
            printf("Enter room number: ");
            scanf("%d", &number);

            rooms = rooms ^ (1 << (number - 1));
        }
        else if(chooser == 2)
        {
            printf("The light is on in rooms: ");
            
            for(int i = 0; i < 8; i++)
            {
                if (rooms & (1 << i))
                {
                    printf("%d ", i+1);
                }
            }
        }
        else
        {
            break;
        }
    }
}
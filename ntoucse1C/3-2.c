#include "stdio.h"
int main()
{
    int m;
    scanf("%d", &m);
    const char *arr[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"};
    for (int i = 0; i < m; i++)
    {
        if (i!=0) printf("\n");
        printf("On the %s day of Christmas\nmy true love sent to me:\n", arr[i]);
        //else
        //{
        for (int j = i+1; j >= 0; j--)
        {
            switch (j)
            {
            case 12:
                printf("12 Drummers Drumming\n");
                break;
            case 11:
                printf("11 Pipers Piping\n");
                break;
            case 10:
                printf("10 Lords a Leaping\n");
                break;
            case 9:
                printf("9 Ladies Dancing\n");
                break;
            case 8:
                printf("8 Maids a Milking\n");
                break;
            case 7:
                printf("7 Swans a Swimming\n");
                break;
            case 6:
                printf("6 Geese a Laying\n");
                break;
            case 5:
                printf("5 Golden Rings\n");
                break;
            case 4:
                printf("4 Calling Birds\n");
                break;
            case 3:
                printf("3 French Hens\n");
                break;
            case 2:
                printf("2 Turtle Doves\n");
                break;
            case 1:
                if (i == 0)
                    printf("A Partridge in a Pear Tree\n");
                else
                    printf("and a Partridge in a Pear Tree\n");
                break;
            default:
                break;
            }
        }
        //}
    }
}
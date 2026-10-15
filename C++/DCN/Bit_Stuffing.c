#include <stdio.h>
#include <string.h>

// 01111110111110101111110001111110

int main()
{
    char input[200], stuffed[300], destuffed[300];
    char flag[] = "01111110";

    int i, j = 0, k = 0;
    int count = 0;
    int len;

    printf("Enter HDLC Frame: ");
    scanf("%s", input);

    len = strlen(input);

    /* Check minimum frame length */
    if (len < 16)
    {
        printf("Invalid HDLC Frame!\n");
        return 1;
    }

    /* Check starting flag */
    for(i = 0; i < 8; i++)
    {
        if(input[i] != flag[i])
        {
            printf("Invalid Start Flag!\n");
            return 1;
        }
    }

    /* Check ending flag */
    for(i = 0; i < 8; i++)
    {
        if(input[len - 8 + i] != flag[i])
        {
            printf("Invalid End Flag!\n");
            return 1;
        }
    }

    // Data validation checks if there are only 0 or 1 in the data.
    /* Check whether data contains only 0 and 1 */
    for(i = 8; i < len - 8; i++)
    {
        if(input[i] != '0' && input[i] != '1')
        {
            printf("Invalid Data! Only 0 and 1 are allowed.\n");
            return 1;
        }
    }

    /*
       BIT STUFFING
       Insert 0 after every five consecutive 1s
    */
    for(i = 8; i < len - 8; i++)
    {
        stuffed[j++] = input[i];

        if(input[i] == '1')
        {
            count++;

            if(count == 5)
            {
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    stuffed[j] = '\0';

    /* Display original data */
    printf("\nOriginal Data: ");

    for(i = 8; i < len - 8; i++)
    {
        printf("%c", input[i]);
    }

    /* Display stuffed data */
    printf("\nStuffed Data: %s", stuffed);


    /*
       BIT DE-STUFFING
       Remove 0 after every five consecutive 1s
    */

    count = 0;

    for(i = 0; stuffed[i] != '\0'; i++)
    {
        destuffed[k++] = stuffed[i];

        if(stuffed[i] == '1')
        {
            count++;

            if(count == 5)
            {
                /*
                   Skip the next 0 because it is
                   the stuffed bit
                */
                if(stuffed[i + 1] == '0')
                {
                    i++;
                }

                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    destuffed[k] = '\0';

    /* Display de-stuffed data */
    printf("\nDe-stuffed Data: %s\n", destuffed);

    return 0;
}
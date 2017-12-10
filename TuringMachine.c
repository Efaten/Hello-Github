#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**/
/*void begin();*/
void secondtrybegin(FILE *fl, int* arr, int i, char *cmd, long int m1, long int m2);

int main(int argc, const char *argv[])
{
    char cmd[255];
    char spam[255];
    int arr[255] = {0};
    int i = 0;
    FILE *fl;
    long int m1 = 0;
    long int m2 = 0;


    if (argc < 2)
    {
        printf ("\nNeed arguments to run\n");
        return -1;
    }
    if ((fl = fopen(argv[1], "r")) == NULL)
    {
        printf ("\nFailed in opening file.\n");
        return -2;
    }


    while (!feof(fl))
    {
        fscanf (fl, "%s", cmd);
        if (!strcmp(cmd, "inc"))
        {
            arr[i]++;
            if (arr[i] == 256)
            {
                arr[i] = 0; printf ("\nThe cell was overfilled and nullified\n");
            }
        }
        else if (!strcmp(cmd, "movl"))
        {
            i--;
            if (i < 0)
                i = 254;
        }
        else if (!strcmp(cmd, "movr"))
        {
            i++;
            if (i > 254)
                i = 0;
        }
        else if (!strcmp(cmd, "dec"))
        {
            arr[i]--;
            if (arr[i] < 0)
                arr[i] = 255; printf ("\nYou can not assign negative values. The value of the cell became 255.\n");
        }
        else if (!strcmp(cmd, "print"))
        {
            printf ("%d\n", arr[i]);
        }
        else if (!strcmp(cmd, "get"))
        {
            arr[i] = getchar();
        }
        else if (!strcmp(cmd, "printc"))
        {
            printf ("%c", arr[i]);
        }
        else if (!strcmp(cmd, "begin"))
        {
            while (arr[i] != 0)
            {
                secondtrybegin(fl, arr, i, cmd, m1, m2);
            }
        }
        else if (cmd[0] == '*')
        {
            fgets(spam, 255, fl);
        }
    }
    return 1;
}

void secondtrybegin(FILE *fl, int* arr, int i, char *cmd, long int m1, long int m2)
{
    m1 = ftell(fl);
    char spam[255];
    fscanf (fl, "%s", cmd);
    while (strcmp (cmd, "end"))
    {
        if (!strcmp(cmd, "inc"))
        {
            arr[i]++;
            if (arr[i] == 256)
            {
                arr[i] = 0; printf ("\nThe cell was overfilled and nullified\n");
            }
        }
        else if (!strcmp(cmd, "movl"))
        {
            i--;
            if (i < 0)
                i = 254;
        }
        else if (!strcmp(cmd, "movr"))
        {
            i++;
            if (i > 254)
                i = 0;
        }
        else if (!strcmp(cmd, "dec"))
        {
            arr[i]--;
            if (arr[i] < 0)
                arr[i] = 255; printf ("\nYou can not assign negative values. The value of the cell became 255.\n");
        }
        else if (!strcmp(cmd, "print"))
        {
            printf ("%d\n", arr[i]);
        }
        else if (!strcmp(cmd, "get"))
        {
            scanf ("%d\n", &arr[i]);
        }
        else if (!strcmp(cmd, "printc"))
        {
            printf ("%c", arr[i]);
        }
        else if (!strcmp(cmd, "begin"))
        {
            while (arr[i] != 0)

                secondtrybegin(fl, arr, i, cmd, m1, m2);
        }
        else if (cmd[0] == '*')
        {
            fgets(spam, 255, fl);
        }
        fscanf (fl, "%s", cmd);
    }
    if (arr[i] != 0)
    {
        m2 = ftell(fl);
        m1 = m1 - m2;
        fseek (fl, m1, SEEK_CUR);
    }
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        printf ("\nNeed arguments to start\n");
        return 0;
    }
    FILE *fl;
    int i = 0;
    bool slovo;
    char c;
    int num = 0;
    int k = 1;
    int s = 1;
    int p = 0;
    if ((fl = fopen(argv[1], "r")) == NULL)
    {
        printf ("\nFailed in opening file.\n");
        return 1;
    }
    char name2[80000];
    while (!feof(fl))
    {
        fscanf (fl, "%s", name2);
        num++;
        while ((c = fgetc(fl)) == ' ')
        {
          p++;
        }
        ungetc(c, fl);
        if (!strcmp(argv[2], name2))
        {
            /*printf ("\nSlovo naideno.\n");*/
            i++;
            printf ("\n%4.d : %4.d - %s", k, s, argv[2]);
            slovo = 1;
        }
        s = s + strlen(name2);
        if (c == '\n' || c == EOF)
        {
            k++; s = 1;
        }
        s = s + p;
        p = 0;
    }
    char *str, *istr;
    if (num == 1)
    {
        istr = name2;
        while ((str = strstr(istr, argv[2])) != NULL)
        {
            printf ("1 : %4.d - %s\n", str-name2+1, argv[2]);
            istr = str + 1;
            slovo = 1;
        }
    }
    if (!slovo)
        printf ("\nCan not find the line");
    /*printf ("\n%d\n%d",i, k);*/
    return 3;
}

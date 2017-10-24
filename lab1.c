#include <stdio.h>
#include <stdlib.h>
float converterCtoF(float a);
float converterCtoK(float b);
float converterFtoC(float v);
float converterFtoK(float l);
float converterKtoC(float r);
float converterKtoF(float y);
int main(int arg0, char *argg [ ] )
{
    float c;
 char m;
 c = atof(argg [1]);
    if (arg0<=1) {
    /* printf("%s","Äëÿ çàïóñêà òðåáóþòñÿ ïàðàìåòðû");*/
    }
    else {
        if (arg0 == 2) {
            if (c > -273.15)
            {
                printf ("%s C\n", argg [1]);
                printf ("%.2f F\n", converterCtoF(c));
                printf ("%.2f K\n", converterCtoK(c));
                printf ("\n");
            } else {
                printf ("\nTemperature C doesn't exist\n");
            }
            if (c > -469.27)
            {
                printf ("%s F\n", argg [1]);
                printf ("%.2f C\n", converterFtoC(c));
                printf ("%.2f K\n", converterFtoK(c));
                printf ("\n");
            } else {
                printf ("Temperature doesn't exist\n");
            }
            if (atof(argg[1])>=0)
            {
                printf ("%s K\n", argg [1]);
                printf ("%.2f C\n", converterKtoC(c));
                printf ("%.2f F\r", converterKtoF(c));
            } else {
                printf ("Temperature K doesn't exist\n");
            }
        }
        else {
            m = *argg [2];
            if (m == 'C' && c > -273.15){
                printf ("%.2f F\n", converterCtoF(c));
                printf ("%.2f K\r", converterCtoK(c));
            }
            if (m == 'K' && atof(argg[1])>0){
                printf ("%.2f C\n", converterKtoC(c));
                printf ("%.2f F\r", converterKtoF(c));
            }
            if (m == 'F'&& c > -469.27){
                printf ("%.2f C\n", converterFtoC(c));
                printf ("%.2f K\r", converterFtoK(c));
            }
        }
    }
    return 0;
}
float converterCtoF(float a)
{
    float f;
    f = 1.8*a+32;
    return f;
}
float converterCtoK(float b)
{
    float k;
    k = b + 273.15;
    return k;
}
float converterFtoC(float v)
{
    float n;
    n = 5*( v- 32)/9;
    return n;
}
float converterFtoK(float l)
{
    float w;
    w = 5*( l- 32)/9 + 273.15;
    return w;
}
float converterKtoC(float r)
{
    float u;
    u = r - 273.15;
    return u;
}
float converterKtoF(float y)
{
    float i;
    i = 9*(y - 273.15)/5 + 32;
    return i;
}

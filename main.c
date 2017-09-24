/*#include <QCoreApplication>*/
#include <stdio.h>
#include <stdlib.h>
float converterCtoF(float a){
    float f;
    f = 1.8*a+32;
    return f;
}
float converterCtoK(float b){
    float k;
    k = b + 273.15;
    return k;
}
float converterFtoC(float v){
    float n;
    n = 5*( v- 32)/9;
    return n;
}
float converterFtoK(float l){
    float w;
    w = 5*( l- 32)/9 + 273.15;
    return w;
}
float converterKtoC(float r){
    float u;
    u = r - 273.15;
    return u;
}
float converterKtoF(float y){
    float i;
    i = 9*(y - 273.15)/5 + 32;
    return i;
}
int main(int arg0, char *argg [ ] )
{
 float c;
 char m;
 c = atof(argg [1]);
 if (arg0<=1) {
 /* printf("%s","Для запуска требуются параметры");*/
 }
  else {
    if (arg0 == 2) {
        printf ("%s C\n", argg [1]);
        printf ("%.2f F\n", converterCtoF(c));
        printf ("%.2f K\n", converterCtoK(c));
        printf ("\n");
        printf ("%s F\n", argg [1]);
        printf ("%.2f C\n", converterFtoC(c));
        printf ("%.2f K\n", converterFtoK(c));
        printf ("\n");
        printf ("%s K\n", argg [1]);
        printf ("%.2f C\n", converterKtoC(c));
        printf ("%.2f F\r", converterKtoF(c));
     }
     else {
        m = *argg [2];
        if (m == 'C'){
             printf ("%.2f F\n", converterCtoF(c));
             printf ("%.2f K\r", converterCtoK(c));
        }
        if (m == 'K'){
             printf ("%.2f C\n", converterKtoC(c));
             printf ("%.2f F\r", converterKtoF(c));
         }
        if (m == 'F'){
             printf ("%.2f C\n", converterFtoC(c));
             printf ("%.2f K\r", converterFtoK(c));
         }
    }
 }
 return 0;
}

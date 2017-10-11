/*#include <QCoreApplication>*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int main()
    {
    srand(time(NULL));
    int m = rand()%5+3;
    int n = rand()%7+3;
    int i = 0;
    int j = 0;
    int min = 20000;
    int indmin [2];
    printf ("%i \n", n);
    printf ("%i \n", m);
    int massiv [n] [m];
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            massiv [i] [j] = rand()%10+1;
            printf ("%3.0i ", massiv [i][j]);
        }
        printf ("\n");
    }
    printf ("\n \n \n");
    for (i = 0; i < m; i++){
        int v = massiv [0][i];
        massiv [0][i] = massiv [n-1][i];
        massiv [n-1][i] = v;
    }
    /*for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
            printf("%3.0i ", massiv [i][j]);
        printf ("\n");
    }*/
    for (i = 0; i < m/2; i++){
        int v1 = massiv [0][i];
        massiv [0][i] = massiv [0][m - i - 1];
        massiv [0][m - i - 1] = v1;
        int v2 = massiv [n - 1][i];
        massiv [n - 1][i] = massiv [n - 1][m - i - 1];
        massiv [n - 1][m - 1 - i] = v2;
    }
    printf ("\n \n \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
            printf("%3.0i ", massiv [i][j]);
        printf ("\n");
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (min > massiv [i][j]){
                min = massiv [i][j];
                indmin [0] = i;
                indmin [1] = j;
            }
        }
    }
    printf ("\n \n \n");
    /*printf ("%3.0i \n", min);*/
    /*for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
            printf("%3.0i ", massiv [i][j]);
        printf ("\n");
    }*/
    int masmen [n-1][m-1];
    for (i = 0; i < n-1; i++){
        for (j = 0; j < m-1; j++){
            if (i < indmin[0] && j < indmin[1])
                masmen [i][j] = massiv [i][j];
            if (i >= indmin [0] && j < indmin [1])
                masmen[i][j] = massiv [i+1][j];
            if (i >= indmin [0] && j >= indmin [1])
                masmen [i][j] = massiv [i+1][j+1];
            if (i < indmin [0] && j >= indmin [1])
                masmen [i][j] = massiv [i][j+1];
        }
    }
    printf ("\n \n \n");
    for (i = 0; i < n-1; i++){
        for (j = 0; j < m-1; j++)
            printf ("%3.0i ", masmen [i][j]);
        printf ("\n");
    }
    printf ("\n\n\nPlease enter the amount of pillars (0<x<10)\n");
    int p = getch();
    p = p - '0';
    if (p > 9 || p < 0){
        printf ("Wrong argument. Please restart the program.\n");
        return 1;
    }
    printf ("%i \n", p);
    printf ("Thank you.",/*It doesn't change anything.*/"\nNow please enter the data in correct format\n");
    printf ("Enter '1' if you want to know the format.\nEnter '2' if you want to start entering the matrix.\n");
    int a;
    int k = 0;
    int l = 0;
    int ruchmas [m-1][p];
    a = getch();
    printf ("\n \n \n");
    switch (a) {
        case '1':
            printf ("You must enter a series of numbers separated by a space.\nSymbol ',' will indicate the end of the line.\n");
            printf ("Symbol '.' will indicate the end of input.\nThere must be no negative numbers or zeros.\n");
            printf ("\nNow please start entering the matrix in correct format.\n");
            break;
        case '2':
            break;
        default:
            printf ("Wrong argument.\nPlease restart the program.\n");
            return 1;
    }
    printf ("\nIn the matrix should be %i rows and %i columns.\n", m-1, p);
    for (i = 0; i < m - 1; i++){
        for (j = 0; j < p; j++){
            while ( ( a = getch() ) != ' '){
                if (a == ',' || a == '.')
                    break;
                k = k*10 + a - '0';
            }
            ruchmas [i][j] = k;
            k = 0;
            printf ("%3.0i  ", ruchmas[i][j]);
        }
        printf ("\n");
    }
    k = 0;
    l = 0;
    int h = 0;
    int resultmatrix [m-1][p];
    printf ("\n%1.0i\n%1.0i\n%1.0i\n\n", n-1, m-1, p);
    for (h = 0; h < n-1; h++){
        for (k = 0; k < p; k++){
            for (i = 0; i < m-1; i++){
                l = l + masmen[h][i]*ruchmas[i][k];
            }
            resultmatrix [h][k] = l;
            l = 0;
            printf ("%3.0i  ", resultmatrix[h][k]);
            /*printf ("%3.0i  - >[ %1.0i] - [%1.0i]  ", resultmatrix[h][k], h, k);*/
        }
        printf ("\n");
    }
    printf ("\nThat's all.\n");
    return -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

main()
{
        double stack[100];
        int n = 0;
        /*printf ("There must be no space after the action.\n");WIP*/
        printf ("You must enter an expression according to the Reverse Polish notation\n");
        printf ("Please enter numbers separated by spaces.\nAll extra spaces will be considered as zero.\n");
        printf ("Symbol '=' will indicate the end of input.\n");
        char a;
        char l;
        int NextToMinus;
        double k = 0;
        while (!feof(stdin))
        {
            while ( (a = getch() ) != EOF || (a != '\n') || a != 32 )
            {
                if (a != 32 && a >= 48 && a <= 57)
                {
                    k = k*10 + a - '0';
                    l = a;
                }
                else break;
            }
            if(a == '+' || a == '-' || a == '*' || a == '/')
                l = a;
            if (a==45){
                NextToMinus = getch();
                if (NextToMinus == 32){
                } else{
                    k = -1 * (NextToMinus - '0');
                    while ( (a = getch() ) != EOF || (a != '\n') || a != 32 )
                    {
                        if (a != 32 && a >= 48 && a <= 57)
                        {
                            k = k*10 + a - '0';
                        }
                        else break;
                    }
                }
            }
            if (a != '+' && a != '-' && a != '*' && a != '/' &&l >=48 && l <=57){
                stack[n] = k; n++;
                k = 0;
                printf ("%.0f ", stack [n-1]);
            }
            /*printf ("%.0f ", stack [n-1]);*/
            switch (a) {
            case '+':
                if (n < 2){
                    printf ("Wrong input. Please restart the program.\n");
                    return 0;
                }
                stack[n-2] = stack[n-1] + stack[n-2]; n--;
                /*printf ("%.0f\t", stack[n-1]);*/
                break;
            case '-':
                if (n < 2){
                    printf ("Wrong input. Please restart the program.\n");
                    return 0;
                }
                stack[n-2] = stack[n-2] - stack[n-1]; n--;
                /*printf ("%.0f\t", stack[n-1]);*/
                break;
            case '*':
                if (n < 2){
                    printf ("Wrong input. Please restart the program.\n");
                    return 0;
                }
                stack[n-2] = stack[n-2] * stack[n-1]; n--;
                /*printf ("%.0f\t", stack[n-1]);*/
                break;
            case '/':
                if (n < 2){
                    printf ("Wrong input. Please restart the program.\n");
                    return 0;
                }
                stack[n-2] = stack[n-2] / stack[n-1]; n--;
                /*printf ("%.0f\t", stack[n-1]);*/
                break;
            case ' ':
                break;
            case '=':
                printf ("Result: %.0f", stack[n-1]);
                break;
            default:
                printf ("Can't understand the argument\n");
                return -1;
            }
        }
}

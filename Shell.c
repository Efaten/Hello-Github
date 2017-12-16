#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int main()
{
    while (1)
    {
        char cmd[255];
        char **arguments = (char**) malloc(sizeof(char*));
        int i = 1;
        int ac = 0;
        int c = 0;
        char program[255];
        printf ("> ");
        while ((c != '\n' && c != EOF) && (scanf("%s", cmd)))
        {
            /*printf ("%s\n", cmd);*/
            if (!ac)
            {
                ac = 1;
                *arguments = cmd;
                strcpy(program, cmd);
            } else
            {
                *(arguments + i) = cmd;
                i++;
            }
            c = getchar();
        }
        if (c == EOF)
        {
            printf ("Termination!\n");
            exit(0);
        }
        *(arguments + i) = NULL;
        pid_t pid = fork();
        if(pid==0)
        {

            if(execvp(program, arguments)!=0)
            {
                switch(errno)
                {
                    case EACCES:
                        fprintf(stderr, "Access to the file of the child process is prohibited\n");
                        break;
                    case EMFILE:
                        fprintf(stderr, "Too many open files\n");
                        break;
                    case ENOENT:
                        fprintf(stderr, "File not found\n");
                        break;
                    case ENOEXEC:
                        fprintf(stderr, "Invalid format of exec\n");
                        break;
                    case ENOMEM:
                        fprintf(stderr, "There is not enough free memory to load child process\n");
                        break;
                    default:
                        fprintf(stderr, "Unknown error!\n");
                }
            }
            exit(1);
        }
        int k;
        wait(&k);
    }
}

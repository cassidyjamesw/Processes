// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("x value before calling fork: %d \n", x);

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        x = 200;
        printf("hello, child here (pid: %d) \n", (int)getpid());
        printf("x value in child when changed: %d \n", x);
    }
    else
    {
        x = 300;
        printf("hello, parent here (pid: %d) of child %d \n", (int)getpid(), rc);
        printf("x value in parent when changed: %d \n", x);
    }

    return 0;
}
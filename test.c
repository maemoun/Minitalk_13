#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void    ft_print()
{
    printf("hello\n");
    signal(SIGINT, SIG_DFL);
}

int main()
{
    signal(SIGINT, ft_print);
    while (1)
    {
        pause();
    }
}
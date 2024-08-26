// Barush Mendez Ruan

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void print_levels(int level)
{
    for (int i = 0; i <= level; i++)
    {
        printf("%d,", i);
    }
    printf("\n");
}

void process_tree(int level, int n)
{

    if (level > n)
    {
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            print_levels(level);
            process_tree(level + 1, n);
            exit(0);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);

    print_levels(0);
    process_tree(1, n);

    return 0;
}
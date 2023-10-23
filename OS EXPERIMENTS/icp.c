#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int fd[2], n;
    char buffer[100];
    pid_t p;
    
    pipe(fd); // Creates a unidirectional pipe with two ends fd[0] and fd[1].
    p = fork();
    
    if (p > 0) { // Parent
        printf("Parent is passing a value to the child.\n");
        write(fd[1], "hello\n", 6); // fd[1] is the write end of the pipe.
        wait(NULL);
    } else { // Child
        printf("Child is printing the received value.\n");
        n = read(fd[0], buffer, 100); // fd[0] is the read end of the pipe.
        write(1, buffer, n);
    }
    
    return 0;
}

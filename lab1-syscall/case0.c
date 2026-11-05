#include <stdio.h>
#include <unistd.h>


int main() {
    int pid;   

    printf("Parent's PID is: %d\n", getpid());

    /* child */
    pid = fork(); 

    if (pid < 0){
        perror("fork error!");
        return 1;
    }
    /* for parent fork() returns it's real pid, for child - 0 */
    else if (pid == 0){
        pid = fork();
        if (pid == 0){
            pid = fork();
        }
    }
    
    sleep(30);
    return 0;    
}
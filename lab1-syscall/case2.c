#include <stdio.h>
#include <unistd.h>

/*Case 2: 
    create binary tree:
    1 -> 2 -> 4 -> 8
*/
int main() {
    int pid;   
    int i;
    int depth = 0;
    const int max_depth = 3;
    const int children = 2;

    printf("Parent's PID is: %d\n", getpid());

    while (depth < max_depth){
        for(i = 0; i < children; i++){
            pid = fork();

            if(pid < 0){
                perror("fork error!");
                return 1;
            }
            /*
                child should stop here for now
                since his siblings are still being created
            */
            else if (pid == 0){
                break;
            }
        }
        
        /*
            parent should exit while loop here
            since he has already created 2 children
        */
        if (pid > 0){
            break;
        }

        depth++;
    }

    sleep(30);
    return 0;    
}
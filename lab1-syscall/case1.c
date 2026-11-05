#include <stdio.h>
#include <unistd.h>

/*Case 1: 
    create parent, then parent creates 1 child,
    then this child creates 5 grandchildren,
    and then only 2 gradchildren create 1 child each.
    so 1 -> 1 -> 5 -> 2.
*/
int main() {
    int pid;   
    int i;
    const int grandchildren = 5;
    const int last_generation = 2;

    printf("Parent's PID is: %d\n", getpid());

    /* child */
    pid = fork(); 

    if (pid < 0){
        perror("fork error!");
        return 1;
    }
    /* for parent fork() returns it's real pid, for child - 0 */
    else if (pid == 0){
        /* 
            case for child 
            5 next children should be created 
        */
       for (i = 0; i < grandchildren; i++){
            pid = fork();
            if (pid < 0){
                perror("fork error!");
                return 1;
            }
            
            /*
                next 2 children should be created
            */
            else if (pid == 0){
                if(i < last_generation){ 
                    pid = fork(); 
                    if (pid == 0){
                        break;
                    }
                }
                break;
            }
       }
    }
    
    /* 
        sleep for 30 sec so we can check the width of parent's tree
        before it will be deleted from system's memory
    */
    sleep(30);
    return 0;    
}
// Project 1
// Author: Greg Ryan
// Date: 2/13/18

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int processA(int ta){

    int id = getpid();
    int Pid = getppid();
    int status, Cid;

    printf("Ada (process %d, parent %d ) will sleep for %d seconds.\n", id, Pid, ta);
    usleep(ta * 1000000);

    printf("Ada (process %d, parent %d ) now waits.\n", id, Pid);
    Cid = wait(&status);

    printf("Ada (process %d, parent %d ) got pid %d and status %d from wait.\n", id, Pid, Cid, status);

    printf("Ada (process %d, parent %d ) quits with exit code 0.\n", id, Pid);
    exit(0);
    
}

int main(int argc, char *argv[]){

    int ta = atoi(argv[1]);
    
    if (fork() == 0){//if process B
        //exec countdown here for B
        execlp("./countdown", "countdown", "Bev", argv[2], NULL);
    }
    else {//if Process A
        if (fork() == 0){//create process C
            if (fork() == 0){//process C creating process D
                //exec countdown here for D
                execlp("./countdown", "countdown", "Dot", argv[4], NULL);
            }
            else {//if process C
                if (fork() == 0){//create process E
                    //exec countdown here for E
                    execlp("./countdown", "countdown", "Eve", argv[5], NULL);
                }
                else {
                    //exec countdown here for C
                    execlp("./countdown", "countdown", "Cal", argv[3], NULL);
                }
            }
        } else {//if process A
            processA(ta);
        }
    }
}


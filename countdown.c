// Project 1
// Author: Greg Ryan
// Date: 2/14/18

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    setbuf(stdout, NULL);

    //int id = getpid();
    //int Pid = getppid();
    int n = atoi(argv[2]);

    int i = 0;
    for (i = n; i > 0; i--){
        printf("%s (process %d, parent %d) will quit in %d seconds.\n", argv[1], getpid(), getppid(), i);
        usleep(1000000);
    }
    
    char *openFile = "/dev/urandom";
    int fd = open(openFile, O_RDONLY);//assign file descriptor
    char *s = malloc(1);
    read(fd, s, 1);
    int r = s[0];

    //makes sure 1 <= r <= 50
    if (r < 1){
            r = -r;
    }
    if (r > 50){
            r = r % 50;
        
    }
    
    printf("%s (process %d, parent %d) quits with exit code %d.\n", argv[1], getpid(), getppid(), r);
    exit(r);

}

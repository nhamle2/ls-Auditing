#include <stdio.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

int checkls(char *arg1, char *arg2){
    
    //declaring constant variables | list length for blacklist and character to exclude in user input
    const char *blacklist[20];
    const char *search = "/";

    //blacklist of all spaces that the user is not allowed to visit (ls into); ex. /etc, /var, /root
    blacklist[0] = "etc";
    blacklist[1] = "var";
    blacklist[2] = "root";
    blacklist[3] = "boot";
    blacklist[4] = "bin";
    blacklist[5] = "dev";
    blacklist[6] = "lib";
    blacklist[7] = "lib32";
    blacklist[8] = "lib64";
    blacklist[9] = "libx32";
    blacklist[10] = "media";
    blacklist[11] = "mnt";
    blacklist[12] = "opt";
    blacklist[13] = "proc";
    blacklist[14] = "run";
    blacklist[15] = "sbin";
    blacklist[16] = "srv";
    blacklist[17] = "sys";
    blacklist[18] = "tmp";
    blacklist[19] = "usr";

    //secure way (somewhat) of copying contents of each user input into buffer1 and buffer 2 respectively
    size_t len1= strlen(arg1);
    size_t len2= strlen(arg2);
    char buffer1 [len1];
    char buffer2 [len2];
    char buffer3 [len2];
    strcpy(buffer1, arg1);
    strcpy(buffer2, arg2);
    strcpy(buffer3, buffer2); //extra buffer to break up buffer2

    //takes first part of buffer2, which contains the path and stores into the first variable
    char *first;
    first = strtok(buffer3, search);
    
    //checks if first argument is "ls", if so, for all memebers in blacklist, check if they are equal to the first part of the path given by user
    if(strcmp(buffer1, "ls")==0){
        for(int i =0; i< 20; i++){
            if(strstr(first, blacklist[i])!=NULL){
                //if directory is beyond home, the attempt is recorded and sent to a log file
                printf("contains directory beyond '/home'. This attempt will be logged \n");
                FILE *fptr;

                fptr = fopen("log.txt", "a+");
                time_t tt;
                time(&tt);

                //error checking for the log file
                if(fptr == NULL){
                    printf("ERROR: There was an error writing to the text file \n");
                    return 0;
                }
                
                fprintf(fptr, "%s : User attempted to access -> %s \n", ctime(&tt), buffer2);
                printf("A log file has been created");
                return 1;
            }
         }
         
        //if all other checks fail, then list out the directory contents
        DIR *dir;
        struct dirent *dent;
        dir = opendir(buffer2);

        if(dir == NULL){ //checks if directory is accessible or exists
            printf("Can't open directory '%s' \n", buffer2);
        }

        while((dent = readdir(dir)) != NULL){ // prints out directory contents
            printf("%s \n", dent->d_name);
        }
    }
    return 0;   

}
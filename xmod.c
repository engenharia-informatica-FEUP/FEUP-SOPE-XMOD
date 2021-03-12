#include "xmod.h"

int ViewDirectoryRecursive(char s[], int indent){
    DIR *dir;
    struct dirent *sd;
    if (!(dir = opendir(s))){
        return 1;
    }

    while ( (sd=readdir(dir)) != NULL){
        if(sd->d_type == DT_DIR){
            char path[1024];
            if(strcmp(sd->d_name, ".") == 0 || strcmp(sd->d_name, "..") == 0){
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", s, sd->d_name);
            printf("%*s[%s]\n", indent, "", sd->d_name);
            int id = fork();
            if(id == 0){
                ViewDirectoryRecursive(path, indent+2);
                return 0;
            }
            else{
                wait(NULL);
            }
        }
        else if(sd->d_type == DT_REG){
            printf(">> %s", sd->d_name);
            printf(" -> %hu\n", sd->d_reclen);
        }
    }
    closedir(dir);
    return 0;
}

int xmod(int argc, char* argv[], char* envp[]){

    if(argc < MIN_ARGS || argc > MAX_ARGS){
        fprintf(stderr,"Incorrect number of arguments\n");
        exit(EXIT_FAILURE);
    }


    if(strcmp(argv[1] , "-v")){
        
    }   
    else if(strcmp(argv[1], "-c")) {

    }
    else if(strcmp(argv[1], "-R")) {

    }


    exit(EXIT_SUCCESS);

}



int main(int argc, char* argv[], char* envp[]){
    mode_t mode = 0777;
    umask(mode);
    int Fid;
    if ( (Fid = open(argv[2], O_RDWR)) != 0){
        return 1;
    }
    //./xmod 0777 ficheiro
    close(Fid);

    printf("Hello World :3\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <ctype.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include <dirent.h>
#include <sys/stat.h>

#include <errno.h>

#include "xmod_macros.h"
#include "xmod_aux.h"

char *signame[] = {"INVALID", "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGTRAP", "SIGABRT", "SIGBUS", "SIGFPE", "SIGKILL", "SIGUSR1", "SIGSEGV", "SIGUSR2", "SIGPIPE", "SIGALRM", "SIGTERM", "SIGSTKFLT", "SIGCHLD", "SIGCONT", "SIGSTOP", "SIGTSTP", "SIGTTIN", "SIGTTOU", "SIGURG", "SIGXCPU", "SIGXFSZ", "SIGVTALRM", "SIGPROF", "SIGWINCH", "SIGPOLL", "SIGPWR", "SIGSYS", NULL};

enum events {
    PROC_CREAT,
    PROC_EXIT,
    SIGNAL_RECV,
    SIGNAL_SENT,
    FILE_MODF
};

struct eventsInfo {
    FILE* file; 
    double instant; // Time Elapsed
    pid_t pid;        // Callee process ID
    pid_t pidTarget; 

    //info of the events
    //PRO_CREATE
    char ** arg;
    int NumArgs;
	int nftot; // Total files checked 
	int nfmod; // Files modified
	int exitStatus;
	int signal;
    char *fileChanged;
    mode_t oldPerm; 
    mode_t newPerm;
};

struct eventsInfo eevee;

int processRegister(enum events event);

int toOctalMode(mode_t oldMask, char mode[], mode_t * mask);

int ViewDirectoryRecursive(char s[], char newMode[], int Octal, int option);

int xmod(int argc, char* argv[]);

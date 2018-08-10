#include <stdio.h>

#if defined(_WIN64) || defined(_WIN32)
#include "getopt.h"
#else
#if 0
#include "getopt.h"
#else
#include <getopt.h>
#endif
#endif

/*
void print(...){
     This is for replacing printf
    Should do it in the future as we're looking how to do so in C.
#if defined(_WIN64) || defined(_WIN32)
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    char *bagus = "bagus";
    LPDWORD written;
    WriteFile(
        handle,
        bagus,
        strlen(bagus),
        written,
        NULL);
#endif
};
*/

int
main(int argc, char *argv[], char *envp[]){
    
    printf("Args : ");
    for(int i=0; i<argc;++i){
        printf("%s ", argv[i]);
    };
    
    printf("\nRead as:\n");
    int opt;
    
    while((opt=getopt(argc, argv, "ab:"))!=-1){
        printf("%d\n", optind);
        printf("%c %d\n", opt, opt);
        //if(opt == '?') break;
    };
    
    
    return 0;
}

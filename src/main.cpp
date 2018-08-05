#if defined(_WIN64) || defined(_WIN32)
#include <windows.h>
#else
#include <string.h>
#endif

void print(...){
    
};

int
main(int argc, char *argv[], char *envp[]){
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
    return 0;
};
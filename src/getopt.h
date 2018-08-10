// Might not need this one line actually.
// Remember: Unity Build
#pragma once

//#include <unistd.h> TODO(bagus) : should also rewrite this

struct option {
    const char *name;
    int         has_arg;
    int        *flag;
    int         val;
};


int getopt(
int argc,
char *argvp[],
char *optstring);

extern char *optarg; char *optarg = NULL;
extern int optind, opterr, optopt;

int optind = 1;int opterr=1;

int
getopt(
int argc,
char *argvp[],
char *optstring){
    
    if(optind >= argc){
        return -1;
    };
    char *opt = argvp[optind];
    if (!opt || '-' != *opt){
        if (*(opt+1) == '-' && !*(opt+2)){
            ++optind;
            return -1;
        };
        //These two lines below might not needed
        //if (!(opt+1))
        //return -1;
        //Also, there might be some kind of loop or recursive mechanism here.
        ++optind;
        return -1;
    };
    char *optstr = optstring;
    if(*optstr == ':') return ':';
    
    ++opt;
    while(*optstr != '\0'){
        if(*optstr == *opt){
            if (*(optstr+1) == ':') {
                ++optind;
                if(optind >= argc) {
                    // error here
                    return '?';
                };
                optarg = argvp[optind+1];
            };
            ++optind;
            break;
        };
        ++optstr;
    };
    if(*optstr == '\0') {
        *opt =  '?';
        ++optind;
    };
    return *opt;;
}

int getopt_long(
int argc, 
char *argv[],
struct option *Longopts,
int *Longindex){
    
    return 0;
}

int getopt_long_only(
int argc,
char *argv[],
char *optstring,
struct option *Longopts,
int *Longindex){
    
    return 0;
}

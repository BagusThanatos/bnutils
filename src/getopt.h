// Might not need this one line actually.
// Remember: Unity Build
#pragma once

//#include <unistd.h> TODO(bagus) : should also rewrite this

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
    if (!opt || *opt != '-'){
        if (*(opt+1) == '-' && !*(opt+2)){
            ++optind;
            return -1;
        };
        if (!(opt+1))
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
                ++optind;
                optarg = argvp[optind+1];
            };
            break;
        };
        ++optstr;
    };
    if(*optstr == '\0') return '?';
    ++optind;
    return *opt;;
};

int getopt_long(
int argc, 
char *argv[],
struct option *Longopts,
int *Longindex){
    
    return 0;
};

int getopt_long_only(
int argc,
char *argv[],
char *optstring,
struct option *Longopts,
int *Longindex){
    
    return 0;
};
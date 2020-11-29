#include <stdio.h>

#define MAXINT 7

int main(){
    FILE *fp;
    char* filename = /*file path*/;
    int lineCount = 0;
    int n;
    int m;
    unsigned int address[MAXINT];

    fp = fopen(filename, "r");
    /*Check if filepath is valid*/
    if(fp == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }
    /*Read addresses into array*/
    address = fgets(address, MAXCHAR, fp) != NULL);
    /*initialize offset and page number ints*/
    n = address[0];
    m = address[1];

    /*Use bit wise functions to extract the page number and offset*/
    int i;
    for(i=2; i<MAXINT; i++){
        char offset = '\00';

        int pn;
        int offset;
        printf("virtual address v%d is in page number %d and offset %d", i-1, pn, offset);
    }
}


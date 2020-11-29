#include <stdio.h>
#include <string.h>

#define MAXINT 7

int main(){
    FILE *fp;
    char* filename = OSproj3\part1\input.txt;
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
    int j = 0;
    while(j<MAXINT&&fgets(address, MAXINT, fp)!=NULL){
        char temp[MAXINT];
        char *temp = temp;
        strcpy(temp[j],address);
        address[j]= (unsigned int)(temp[j])
        j++;
    }
    /*initialize offset and page number ints*/
    n = address[0]; /*offset*/
    m = address[1]; /*page number*/

    /*Use bit wise functions to extract the page number and offset*/
    int i;
    for(i=2; i<MAXINT; i++){
        /*Extracting offset*/
        unsigned int offset = address[i]<<m; /*gives the offset followed by m zeroes*/
        offset = offset>>m; /*gives the value of the offset in binary*/

        /*Extracting page number*/
        unsigned int pn = address[i]>>n; /*gives the value of the offset in binary*/

        printf("virtual address v%d is in page number %d and offset %d", i-1, pn, offset);
    }
    return 0;
}
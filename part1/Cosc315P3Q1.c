#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXINT 7

int main(){
    FILE *fp;
    char* filename = "./input.txt";
    int lineCount = 0;
    int n;
    int m;
    unsigned int *address;
    address = (int *) malloc(sizeof(int)*MAXINT);

    fp = fopen(filename, "r");
    /*Check if filepath is valid*/
    if(fp == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }
    /*Read addresses into array*/
    int j;
    for(j=0;j<MAXINT;j++){
        if(j==0){
            fscanf(fp, "%d", &n);
        }
        else if(j==1){
            fscanf(fp, "%d", &m);
        }
        else{
            fscanf(fp, "%u", &address[j]);
        }
    }
  
    /*Use bit wise functions to extract the page number and offset*/
    int i;
    for(i=2; i<MAXINT; i++){

        /*Extracting offset*/
        unsigned int offset = address[i]<<m+16; /*gives the offset followed by m zeroes*/
        offset = offset>>m+16; /*gives the value of the offset in binary*/

        /*Extracting page number*/
        unsigned int pn = address[i]>>n; /*gives the value of the offset in binary*/

        printf("virtual address v%d is in page number %d and offset %d\n", i-1, pn, offset);
    }
    return 0;
}

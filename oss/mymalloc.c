#include<stdio.h>
#include<stdlib.h>
#include"mymalloc.h"

static unsigned char arr[25000];
static int *start[25000][2];

static int end;

static void assignSlot(int point,int size){
    printf("asign %d\n",point);
    int remaining= start[point][1]-size;
    printf("%d\n",remaining);
    if(remaining>0){
        start[point][0]=point+size;
        start[point][1]=remaining;
        printf("memory allocated at %d with the size %d\n",point,size);
        printf("start0 %d %d\n",start[0][0],start[0][1]);

    }
    else{
        int x;
        for(x=point;x<end;x++){
            start[x][0]=start[x+1][0];
            start[x][1]=start[x+1][1];
        }
        printf("remanig is zero");
        end--;
    }
}

static int checkAvailabale(int size){

    printf("check alailable\n");
    int point;

    for(point=0;point<=end;point++){
        if(size>=start[point][1]){
            return point;
        }

    }


}

void * MyMalloc(int size){

    printf("MyMaloc\n");
    end=0;
    start[0][0]=0;
    start[0][1]=25000;
    int point=checkAvailabale(size);
    assignSlot(point,size);

}

//Check for available slots to assign



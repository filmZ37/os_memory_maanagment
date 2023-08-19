#include<stdio.h>
#include<stdlib.h>

void *malloc(size_t size);
void free(void *ptr);

int var1 = 6;
float var2 ;
char var3 = 'A';

void call_recursive(int n){
    if( n < 3){
        int data = n;
        printf("In stack: address of data %d is at %p.\n",data,&data);
        call_recursive(n+1) ;
    }

}

void make_overflow(){
    make_overflow();
}

int main(int argc,char** argv){
    
    //stack address section
    printf("In stack: address argc is at\t  %p.\n",&argc);
    printf("In stack: address argv is at\t  %p.\n",&argv);
    call_recursive(0);
    //make stack to overflow
    // make_overflow();

    //heap address section
    int *ptr1,*ptr2, *ptr3 ;
    ptr1 = (int*)malloc(4*sizeof(int));
    ptr2 = (int*)malloc(8*sizeof(int));
    ptr3 = (int*)malloc(16*sizeof(int));

    printf("In heap: starting address of *ptr1 is at %p.\n",ptr1);
    printf("In heap: starting address of *ptr2 is at %p.\n",ptr2);
    printf("In heap: starting address of *ptr3 is at %p.\n",ptr3);
    free(ptr1);
    free(ptr2);
    free(ptr3);

    //global variable address section
    printf("In data: address of var1 is at %p.\n",&var1);
    printf("In data: address of var2 is at %p.\n",&var2);
    printf("In data: address of var3 is at %p.\n",&var3);

    return 0;
}
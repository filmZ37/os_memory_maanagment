#include<stdio.h>
#include<stdlib.h>

void *malloc(size_t size);
void free(void *ptr);

void call_recursive(int n){
    if( n < 3){
        int data = n;
        printf("In stack: address of data %d is at %p.\n",data,&data);
        call_recursive(n+1) ;
    }

}

int main(int argc,char** argv){
    int *ptr1,*ptr2, *ptr3 ;

    //stack address section
    printf("In stack: address argc is at %p.\n",&argc);
    printf("In stack: address argv is at %p.\n",&argv);
    call_recursive(0);

    //heap address section
    ptr1 = (int*)malloc(4*sizeof(int));
    ptr2 = (int*)malloc(8*sizeof(int));
    ptr3 = (int*)malloc(16*sizeof(int));

    printf("In heap: starting address of *ptr1 is at %p.\n",ptr1);
    printf("In heap: starting address of *ptr2 is at %p.\n",ptr2);
    printf("In heap: starting address of *ptr3 is at %p.\n",ptr3);
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}
#include<stdio.h>

void call_recursive(int n){
    if( n < 3){
        int data = n ;
        printf("In stack address of data %d is at %p.\n",data,&data) ;
        call_recursive(n+1) ;
    }

}

int main(int argc,char** argv){
    //stack address section
    printf("In stack address argc is at %p.\n",&argc);
    printf("In stack address argv is at %p.\n",&argv);
    call_recursive(0);


    return 0;
}
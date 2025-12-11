#include <stdio.h>
#include "iostream"

int main(){
    int my_array2[] = {1,2,3,4}; /* Short Cut for Initializing array*/
    printf("The third element is %d.\n", my_array2[2]); /*Access element via indexing */
    // basic for loop
    for (int i=0;i<4;i++){
        std::cout<<i<<'\n';
    }
    // Ranged based loop
    for (int value: my_array2){
        std::cout<<value<<'\n';
    };
    return 0;
}


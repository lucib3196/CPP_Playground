#include "iostream"
int main(){
    int myArray[]{1,2,3,4};
    int* ptrArray = myArray;
    std::cout<< "My array pointer is pointing to "<< *ptrArray << '\n';
    std::cout<< "My array"<< myArray << '\n';
}
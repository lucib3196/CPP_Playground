#include <iostream>


void printAddresses(int val, int& ref){
    std::cout << "The address of the value param is "<< &val <<"\n";
    std::cout << "The address of the reference parameter is "<< &ref << "\n";
}

void printRef(const int& y){
    std::cout<<y<< "\n";
}

int main(){
    int x{5};
    std::cout << "the address of x is" << &x << "\n";
    printAddresses(x,x);

    printRef(x);

    const int z {5};
    printRef(z);

    return 0;
}
#include <iostream>

int main(){
    int x{5};
    int& ref {x};

    // Will print out 5 5
    std::cout<<x<<"\n";
    std::cout <<ref<< "\n";

    // Will print out 6 6 
    x = 6;
    std::cout<<x<<"\n";
    std::cout <<ref<< "\n";

    // Will print out 7 7
    ref = 7;
    std::cout<<x<<"\n";
    std::cout <<ref<< "\n";

    return 0;
}
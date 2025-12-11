#include <stdio.h>

int main() 
{
    int gettysburg = 0;
    int *gettysburg_address = &gettysburg;

    printf("Value at gettysburg_address: %d\n", *gettysburg_address);
    printf("Gettysburg Address: %p\n", (void*)gettysburg_address);

    *gettysburg_address = 17325;

    printf("Value at gettysburg_address: %d\n", *gettysburg_address);
    printf("Gettysburg Address: %p\n", (void*)gettysburg_address);

    return 0;
}

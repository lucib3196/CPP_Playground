#include <iostream>

struct Vector
{
    double *elem; // Point to elements
    int sz;       // Number of elements
};

void vector_init(Vector &v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s)
{
    // Reads s integers from cin and returns the sum; s is assumed to be postive
    Vector v;
    vector_init(v, s);

    for (int i = 0; i != s; ++i)
    {
        std::cin >> v.elem[i];
    };

    double sum = 0;
    for (int i = 0; i != s; ++i)
    {
        sum += v.elem[i];
    }
    return sum;
}
int main()
{
    int v_len = 10;
    std::cout << "Enter Digits up to " << v_len << "\n";
    double sum = read_and_sum(v_len);
    std::cout << "Total Sum: " << sum << "\n";
}

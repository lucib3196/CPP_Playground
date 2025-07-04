#include <iostream>

class Vector
{
public:
    Vector(int s)
        : elem{new double[s]}, sz{s} {}

    double &operator[](int i) { return elem[i]; }
    int size() const { return sz; }

private:
    double *elem; // pointer to the elements
    int sz;       // number of elements
};

double read_and_sum(int s)
{
    Vector v(s);
    for (int i = 0; i != v.size(); ++i)
    {
        std::cin >> v[i];
    };

    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
    {
        sum += v[i];
    }
    return sum;
};

int main(){
    double val = read_and_sum(5);
    std::cout<<val;
}
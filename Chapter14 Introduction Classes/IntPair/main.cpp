#include <iostream>

class IntPair
{
private:
    int val1{};
    int val2{};

public:
    IntPair(int a, int b) : val1{a}, val2{b} {}
    bool isEqual(const IntPair &other) const
    {
        return (val1 == other.val1) && (val2 == other.val2);
    };
    void print()
    {
        std::cout << "PAIR(" << val1 << ", " << val2 << ")\n";
    }
};

int main()
{
    IntPair p1{1, 2};
    IntPair p2{3, 4};

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
    std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

    return 0;
}

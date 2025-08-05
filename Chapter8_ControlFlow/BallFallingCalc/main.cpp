#include <iostream>

namespace Constants
{
    constexpr double gravity{9.8}; // m/s^2

}

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

double calcBallHeight(double towerHeight, int seconds)
{
    const double fallDistance{Constants::gravity * (seconds * seconds) / 2.0};
    const double ballHeight{towerHeight - fallDistance};

    if (ballHeight < 0.0)
    {
        return 0;
    }
    return ballHeight;
}

void printBallHeight(double ballHeight, int seconds)
{
    if (ballHeight > 0.0)
    {
        std::cout << "At " << seconds << " seconds, the ball is at a height of " << ballHeight << " m\n";
    }
    else
    {
        std::cout << "The ball hit the ground at " << seconds << " seconds\n";
    }
}

double calculateAndPrintBallHeight(double towerHeight, int seconds)
{
    const double ballHeight{calcBallHeight(towerHeight, seconds)};
    printBallHeight(ballHeight, seconds);
    return ballHeight;
}
int main()
{
    const double towerHeight = {getTowerHeight()};
    int seconds{0};
    while (calculateAndPrintBallHeight(towerHeight, seconds) > 0.0)
    {
        ++seconds;
    }

    return 0;
}
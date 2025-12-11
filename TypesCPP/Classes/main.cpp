#include <cstdio>

struct ClockYear
{
    void addYear()
    {
        year++;
    }
    bool set_year(int new_year)
    {
        if (new_year < 2019)
            return false;
        year = new_year;
        return true;
    };

    int get_year()
    {
        return year;
    }

private:
    int year;
};

int main()
{
    ClockYear myClock;
    myClock.set_year(2025);
    printf("year: %d\n", myClock.get_year());
    myClock.addYear();
    printf("Added a year: %d\n", myClock.get_year());

    // Using Member of Pointer Operator
    ClockYear *clock_ptr = &myClock;
    clock_ptr->set_year(2040);

    printf("Address of the clock %p\n", (void *)clock_ptr);
    printf("Value of the clock's year %d", clock_ptr->get_year());

    return 0;
}
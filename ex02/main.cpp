#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    if (numbers.size() != MAX_VAL || numbers[0] != 0)
        return 1;
    int mirror[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        tmp[0] = -1;
        test[1] = -1;
        if (numbers[0] == -1 || numbers[1] == -1)
            return 1;
    }

    Array<int> assigned;
    assigned = numbers;
    assigned[0] = -1;
    if (numbers[0] == -1 || assigned.size() != numbers.size())
        return 1;
    Array<int> &same = assigned;
    assigned = same;
    if (assigned[0] != -1)
        return 1;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    bool caught_negative = false;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        caught_negative = true;
        std::cerr << e.what() << '\n';
    }
    bool caught_upper = false;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        caught_upper = true;
        std::cerr << e.what() << '\n';
    }
    if (!caught_negative || !caught_upper)
        return 1;

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    return 0;
}

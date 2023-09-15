/*
Enrique Saracho Felix
15-09-2023
Plays one game of craps
*/
#include <iostream>
#include <ctime>

/*
Generates the sum of two dice rolls.
    Input: none.
    Output: an integer between 2 and 12.
*/
int rollDice();

int firstRoll();

int laterRolls(int);

int main()
{
    srand(time(0));
    int result = firstRoll();
}

int rollDice()
{
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;
    std::cout << "dice 1: " << dice1 << std::endl;
    std::cout << "dice 2: " << dice2 << std::endl;
    int sum = dice1 + dice2;
    std::cout << "total: " << sum << std::endl;
    return sum;
}

int firstRoll()
{
    std::cout << "7 or 11 to win" << std::endl;
    std::cout << "2, 3 or 12 to lose" << std::endl;

    int sum = rollDice();
    if (sum == 7 || sum == 11)
    {
        std::cout << "You have won!" << std::endl;
        std::cout << std::endl;
        return 1;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        std::cout << "You lose" << std::endl;
        std::cout << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Roll again" << std::endl;
        std::cout << std::endl;
        return laterRolls(sum);
    }

    return 0;
}

int laterRolls(int n)
{
    std::cout << n << " to win" << std::endl;
    std::cout << "7 to lose" << std::endl;

    int sum = rollDice();
    if (sum == n)
    {
        std::cout << "You have won!" << std::endl;
        std::cout << std::endl;
        return 1;
    }
    else if (sum == 7)
    {
        std::cout << "You lose" << std::endl;
        std::cout << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Roll again" << std::endl;
        std::cout << std::endl;
        return laterRolls(n);
    }
}
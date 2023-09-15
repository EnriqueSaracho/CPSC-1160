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

/*
Evaluates the first result of a game of craps.
    Input: none.
    Output: 1 if it's a win, 0 if its a loss.
*/
int firstRoll();

/*
Evaluates the results of a game of craps after the first roll.
    Input: n -> the sum of the roll from the first roll.
    Output: 1 if it's a win, 0 if its a loss.
*/
int laterRolls(int);

/*
Runs a game of craps a certain amount to times and calculates the win percentage.
    Input: none.
    Output: displays result on console.
*/
int main()
{
    srand(time(0));
    int result = 0;
    int total = 1000000;
    for (int i = 0; i < total; i++)
    {
        result += firstRoll();
    }

    double ptg = (result / (total * 1.0)) * 100;

    // std::cout << "Wins: " << result << std::endl;
    std::cout << "Percentage of wins: " << ptg << "%" << std::endl;
}

int rollDice()
{
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;
    int sum = dice1 + dice2;
    return sum;
}

int firstRoll()
{
    int sum = rollDice();
    if (sum == 7 || sum == 11)
    {
        return 1;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
        return 0;
    }
    else
    {
        return laterRolls(sum);
    }

    return 0;
}

int laterRolls(int n)
{
    int sum = rollDice();
    if (sum == n)
    {
        return 1;
    }
    else if (sum == 7)
    {
        return 0;
    }
    else
    {
        return laterRolls(n);
    }
}
/* This is a stupidly overcomplicated recursive implementation of fizzbuzz.
   This prints every digit from LOWER_BOUND to UPPER_BOUND (usually specified
   as 100 to 1, but here 300 to 1), substituting Fizz for multiples of MODFIZZ
   (usually 3), Buzz for multiples of MODBUZZ (usually 5), and FizzBuzz for
   multiples of MODFIZZ and MODBUZZ (usually 3 && 5).

   The same thing could be accomplished by:

   for (int i = 1; i <= UPPER_BOUND; ++i)
   {
       if (i % MODFIZZ == LOWER_BOUND) std::cout << "Fizz";
       if (i % MODBUZZ == LOWER_BOUND) std::cout << "Buzz";
       if (i % MODFIZZ != LOWER_BOUND && i % MODBUZZ != LOWER_BOUND) std::cout << i;
       std::cout << "\n";
   }

   In addition, this uses global variables to iterate over multiple values for
   MODFIZZ (as modFizz) and MODBUZZ (as modbuzz), just for giggles. In this case,
   I've set the program to follow Fibonacci-ish sequences. Like the for loop
   implementation, the do/while loop is recursive in a fairly needless manner.
*/

#include <iostream>

void doWhileLoop(int modFizz, int modBuzz, int iterations);
void forLoop(int i, const int modFizz, const int modBuzz);
int fibIsh(int i);
bool checkFizz(int i, const int modFizz);
bool checkBuzz(int i, const int modBuzz);

const int UPPER_BOUND = 300,
          LOWER_BOUND = 1,
          MODFIZZ = 3,
          MODBUZZ = 5,
          ITERATIONS = 10;      // number of fizzbuzz iterations
const bool ITERATE_FLAG = true; // set to false to disable fizzbuzz iteration

int main()
{
    int modFizz = MODFIZZ,
        modBuzz = MODBUZZ,
        iterations = 1;

    doWhileLoop(modFizz, modBuzz, iterations);
}

void doWhileLoop(int modFizz, int modBuzz, int iterations)
{
    std::cout << "Iteration #" << iterations << " - "
              << "Fizz on " << modFizz << ", Buzz on " << modBuzz
              << ", FizzBuzz on\n" << modFizz << " * " << modBuzz
              << ", otherwise just print the integer:\n\n";

    forLoop(LOWER_BOUND, modFizz, modBuzz);

    if (ITERATE_FLAG && iterations < ITERATIONS)
    {
        std::cout << "\n\n";
        doWhileLoop(fibIsh(modFizz), fibIsh(modBuzz), ++iterations);
    }
}

void forLoop(int i, const int modFizz, const int modBuzz)
{
    if (i <= UPPER_BOUND)
    {
        if (checkFizz(i, modFizz)) checkBuzz(i, modBuzz);
        else if (!checkBuzz(i, modBuzz)) std::cout << i;
        (i % 15 == 0) ? std::cout << "\n" : std::cout << " ";
        forLoop(++i, modFizz, modBuzz);
    }
}

int fibIsh(int i)
{
    if (1 % 2 == 0) return (i / 2) + i - 1;
    return (i / 2) + i;
}

bool checkFizz(int i, const int modFizz)
{
    i -= modFizz;
    if (i == 0)
    {
        std::cout << "Fizz";
        return true;
    }
    else if (i < 0) return false;
    else return checkFizz(i, modFizz);
}

bool checkBuzz(int i, const int modBuzz)
{
    i -= modBuzz;
    if (i == 0)
    {
        std::cout << "Buzz";
        return true;
    }
    else if (i < 0) return false;
    else return checkBuzz(i, modBuzz);
}

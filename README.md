# FizzBuzz
This is a stupidly overcomplicated recursive implementation of fizzbuzz.
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

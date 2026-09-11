// Time and Space Complexity in Recursion.

#include <iostream>
using namespace std;

/*
=========================================================
        RECURSION IN C++ - TIME & SPACE COMPLEXITY
        Example: Factorial Using Recursion
=========================================================

What is Recursion?
------------------
Recursion is a technique where a function calls itself
to solve a smaller version of the same problem.

A recursive function mainly has TWO parts:

1. BASE CASE
   -> Condition that stops the recursion.

2. RECURSIVE CASE
   -> Function calls itself with a smaller/simpler input.


---------------------------------------------------------
FACTORIAL
---------------------------------------------------------

Mathematically:

5! = 5 * 4 * 3 * 2 * 1
   = 120

We can also write:

5! = 5 * 4!

So:

factorial(n) = n * factorial(n - 1)

Base Case:

factorial(0) = 1

Therefore:

factorial(n) = n * factorial(n - 1)
when n > 0


---------------------------------------------------------
TIME COMPLEXITY
---------------------------------------------------------

For:

factorial(5)

The function calls are:

factorial(5)
factorial(4)
factorial(3)
factorial(2)
factorial(1)
factorial(0)

There are approximately n calls.

Therefore:

TIME COMPLEXITY = O(n)


---------------------------------------------------------
SPACE COMPLEXITY
---------------------------------------------------------

Every recursive function call is stored in the
CALL STACK until it finishes.

For factorial(5), the stack looks like:

factorial(5)
    |
factorial(4)
    |
factorial(3)
    |
factorial(2)
    |
factorial(1)
    |
factorial(0)

Maximum recursion depth = n.

Therefore:

SPACE COMPLEXITY = O(n)


IMPORTANT RULE
--------------

TIME  = Total amount of work / total function calls

SPACE = Maximum recursion depth / call stack


Final Answer:

Time Complexity  = O(n)
Space Complexity = O(n)

=========================================================
*/

// -------------------------------------------------------
// FACTORIAL FUNCTION
// -------------------------------------------------------

int factorial(int n)
{
    /*
    -------------------------------------------------------
    BASE CASE
    -------------------------------------------------------

    When n becomes 0, we stop the recursion.

    0! = 1

    Without a base case, the function would keep calling
    itself forever.
    */

    if (n == 0)
    {
        return 1;
    }

    /*
    -------------------------------------------------------
    RECURSIVE CASE
    -------------------------------------------------------

    We call factorial() again with n - 1.

    Example:

    factorial(5)
    = 5 * factorial(4)

    factorial(4)
    = 4 * factorial(3)

    factorial(3)
    = 3 * factorial(2)

    factorial(2)
    = 2 * factorial(1)

    factorial(1)
    = 1 * factorial(0)

    factorial(0)
    = 1

    Then the answers return back:

    factorial(1) = 1 * 1  = 1
    factorial(2) = 2 * 1  = 2
    factorial(3) = 3 * 2  = 6
    factorial(4) = 4 * 6  = 24
    factorial(5) = 5 * 24 = 120
    */

    return n * factorial(n - 1);
}

// -------------------------------------------------------
// MAIN FUNCTION
// -------------------------------------------------------

int main()
{
    int n;

    // Take input from the user
    cout << "Enter a number: ";
    cin >> n;

    // Call the recursive factorial function
    int answer = factorial(n);

    // Print the result
    cout << "Factorial of " << n << " = " << answer << endl;

    return 0;
}

/*
=========================================================
DRY RUN FOR n = 5
=========================================================

First, main() calls:

factorial(5)

Then:

factorial(5)
        |
        |-- 5 * factorial(4)
                     |
                     |-- 4 * factorial(3)
                                  |
                                  |-- 3 * factorial(2)
                                               |
                                               |-- 2 * factorial(1)
                                                            |
                                                            |-- 1 * factorial(0)

Now factorial(0) reaches the BASE CASE:

factorial(0) = 1


Now recursion starts returning:

factorial(1)
= 1 * factorial(0)
= 1 * 1
= 1

factorial(2)
= 2 * factorial(1)
= 2 * 1
= 2

factorial(3)
= 3 * factorial(2)
= 3 * 2
= 6

factorial(4)
= 4 * factorial(3)
= 4 * 6
= 24

factorial(5)
= 5 * factorial(4)
= 5 * 24
= 120


=========================================================
FINAL COMPLEXITY
=========================================================

Time Complexity:
O(n)

Why?
Because the function is called n times.


Space Complexity:
O(n)

Why?
Because n recursive calls are stored in the
call stack at the deepest point.


=========================================================
QUICK RECAP
=========================================================

Recursion:
    Function calls itself.

Base Case:
    Stops the recursion.

Recursive Case:
    Calls the same function with a smaller input.

For Factorial:

    Time  = O(n)
    Space = O(n)

Remember:

    TIME  -> Total work
    SPACE -> Maximum recursion depth

=========================================================
*/
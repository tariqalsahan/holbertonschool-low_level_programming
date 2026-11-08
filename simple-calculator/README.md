# Simple Calculator

A terminal-based interactive calculator written in C.

## Compile

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run

    ./calculator

Type the number of a menu option and press Enter.

## Supported operations

- 1) Add
- 2) Subtract
- 3) Multiply
- 4) Divide
- 0) Quit

## Numeric behavior

Menu options are read as integers with scanf.

## Known limitations

- Only the menu option is validated (integer within the menu range).
- Non-numeric input (for example x or hello) is not handled.

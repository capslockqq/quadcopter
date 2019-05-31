/**
 * \brief simple application to test the C++ toolchain
 *
 * \file main.cc
 * \author Matthias Kleemann
 */
#include <stdio.h>
#include "../application_code/CLed.hpp"
#include "../application_code/test.hpp"
/**
 * \brief main loop
 */
int main(void)
{
   hej();
   CLed t;
   t.DoStuff();
   printf("PC - lol\n\r");
}

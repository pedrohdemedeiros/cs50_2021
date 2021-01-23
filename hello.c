#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*Programa inicial que pede seu input, string, e devolve o mesmo*/
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}
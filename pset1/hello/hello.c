#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    string s = get_string("What is your name?\n");
    printf("hello, %s\n", s);
}
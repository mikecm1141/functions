#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int gcd(int x, int y);
float absoluteValue(float x);
float squareRoot(float x);

int main(void)
{
    int x = 16;
    int y = -45;

    printf("GCD of %d and %d is: %d\n", x, y, gcd(x,y));
    printf("Absolute Value of %d is %.2f\n", x, absoluteValue(x));
    squareRoot(x);
}

int gcd(int x, int y)
{
    if(x < 0)
        x *= -1;
    if(y < 0)
        y *= -1;

    if(y == 0)
        return x;
    else
        return gcd(y, x % y);
}

float absoluteValue(float x)
{
    if(x < 0)
        x *= -1;

    return x;
}

float squareRoot(float x)
{
    const float guard = .00001;
    float guess = 1.0;
    float squareRoot = 0.0;

    if(x < 0)
    {
        printf("Cannot find square root of a negative number %.2f.\n", x);
        return -1.0;
    }
    else
    {
        while(absoluteValue(guess * guess - x) >= guard)
            guess = (x / guess + guess) / 2.0;

        squareRoot = guess;
        printf("The square root of %.2f is %.4f\n", x, squareRoot);
    }
    
    return squareRoot;
}

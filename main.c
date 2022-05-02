#include <stdio.h>


void SwapIntegers(int* first, int* second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int main()
{
    int x, y;
    x = -5842;
    y = 68;
    
    printf("Before Swap: x = %d\ny = %d\n\n", x, y);
    SwapIntegers(&x, &y);
    
    printf("After Swap: x = %d\ny = %d\n", x, y);
    
    return 0;
}
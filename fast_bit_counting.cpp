#include <iostream>

int setbits(unsigned long long x)
{
    // TLEs
    int o = 0;
    while (x)
    {
        if (x&1)
            ++o;
        x >>= 1;
    }
    return o;
}

int setbits_1(unsigned long long x)
{
    // TLEs
    register unsigned long y = x >> 64;
    register unsigned long z = x;
    register int o = 0;
    while (y)
    {
        if (y&1)
            ++o;
        y >>= 1;
    }
    while (z)
    {
        if (z&1)
            ++o;
        z >>= 1;
    }
    return o;
}

int setbits_2(unsigned long long x)
{
    // this one works... but only just!
    const int fours[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
    register int o = 0;
    while (x)
    {
        o += fours[x&15];
        x >>= 4;
    }
    return o;
}

int setbits_3(unsigned long long x)
{
    // TLEs
    const int fours[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
    int o = 0;
    while (x)
    {
        o += fours[x&15];
        x >>= 4;
    }
    return o;
}

int main()
{
    std::cout << setbits(1596);
    std::cout << setbits_1(1596);
    std::cout << setbits_2(1596);
    std::cout << setbits_3(1596);
    return 0;
}

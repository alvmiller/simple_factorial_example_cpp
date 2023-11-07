#include <cassert>
#include <iostream>

//------------------------------------------------------------------------------
inline unsigned int factorial00(unsigned int n)
{
    unsigned int result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
inline unsigned int factorial01(unsigned int n)
{
    return (n == 0) ? 1 : n * factorial01(n - 1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
unsigned int tail_recursion_factorial02_core(unsigned int n, unsigned int a)
{
    if (n <= 1) {
        return a;
    }

    return tail_recursion_factorial02_core(n - 1, n * a);
}

unsigned int factorial02(unsigned int n)
{
    return tail_recursion_factorial02_core(n, 1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
template <unsigned int n>
struct factorial03
{
    enum { value = n * factorial03<n - 1>::value };
};

template <>
struct factorial03<1>
{
    enum { value = 1 };
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
constexpr unsigned int factorial04(unsigned int n)
{
    return (n == 0) ? 1 : n * factorial04(n - 1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
constexpr unsigned int factorial05(unsigned int n)
{
    unsigned int result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
consteval unsigned int factorial06(unsigned int n)
{
    return (n == 0) ? 1 : n * factorial06(n - 1);
}
//------------------------------------------------------------------------------

int main()
{
    assert(factorial00(5) == 120);
    assert(factorial01(5) == 120);
    assert(factorial02(5) == 120);
    assert(factorial03<5>::value == 120);
    assert(factorial04(5) == 120);
    assert(factorial05(5) == 120);
    assert(factorial06(5) == 120);

    static_assert(factorial03<5>::value == 120, "factorial03 failed value");
    static_assert(factorial04(5) == 120, "factorial04 failed value");
    static_assert(factorial05(5) == 120, "factorial05 failed value");
    static_assert(factorial06(5) == 120, "factorial06 failed value");

    return 0;
}

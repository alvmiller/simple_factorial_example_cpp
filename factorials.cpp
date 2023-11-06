#include <cassert>
#include <iostream>

//------------------------------------------------------------------------------
inline unsigned int factorial00(unsigned int n)
{
    return (n == 0) ? 1 : n * factorial00(n - 1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
unsigned int tail_recursive_factorial01_core(unsigned int n, unsigned int a)
{
    if (n <= 1) {
        return a;
    }

    return tail_recursive_factorial01_core(n - 1, n * a);
}

unsigned int factorial01(unsigned int n)
{
    return tail_recursive_factorial01_core(n, 1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
template <unsigned int n>
struct factorial02
{
    enum { value = n * factorial02<n - 1>::value };
};

template <>
struct factorial02<1>
{
    enum { value = 1 };
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
constexpr unsigned int factorial03(unsigned int n)
{
    return (n == 0) ? 1 : n * factorial03(n - 1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
constexpr unsigned int factorial04(unsigned int n)
{
    unsigned int result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
consteval unsigned int factorial05(unsigned int n)
{
    return (n == 0) ? 1 : n * factorial03(n - 1);
}
//------------------------------------------------------------------------------

int main()
{
    assert(factorial00(5) == 120);
    assert(factorial01(5) == 120);
    assert(factorial02<5>::value == 120);
    assert(factorial03(5) == 120);
    assert(factorial04(5) == 120);
    assert(factorial05(5) == 120);

    static_assert(factorial02<5>::value == 120, "factorial02 failed value");
    static_assert(factorial03(5) == 120, "factorial03 failed value");
    static_assert(factorial04(5) == 120, "factorial04 failed value");\
    static_assert(factorial05(5) == 120, "factorial04 failed value");

    return 0;
}

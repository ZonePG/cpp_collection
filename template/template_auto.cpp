// ----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>

template<int answer>
void foo()
{
    std::cout << "The answer is: " << answer << '\n';
}

int main(int argc, char const *argv[])
{
    foo<42>();
    return 0;
}

// The answer is: 42

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <iostream>

template<auto answer>
void foo()
{
    std::cout << "The answer is: " << answer << '\n';
}

int main(int argc, char const *argv[])
{
    foo<42>();

    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <iostream>
#include <type_traits>

template <
    auto answer,
    std::enable_if_t<std::is_integral_v<decltype(answer)>, int> = 0
    >
void foo()
{
    std::cout << "The answer is: " << answer << '\n';
}

int main(int argc, char const *argv[])
{
    foo<42>();

    return 0;
}

#endif
// ----------------------------------------------------------------------------
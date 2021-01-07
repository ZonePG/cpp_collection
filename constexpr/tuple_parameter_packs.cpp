// ----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>

template <typename... Args>
void foo(Args && ...args)
{ }

int main(void)
{
    foo("The answer is: ", 42);
    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <tuple>
#include <iostream>

int main(void)
{
    std::tuple t("the answer is: ", 42);
    std::cout << std::get<0>(t) << std::get<1>(t) << '\n';
    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <tuple>
#include <iostream>

template <typename ... Args>
void foo(Args && ...args)
{
    std::tuple t(std::forward<Args>(args)...);
    std::cout << std::get<0>(t) << std::get<1>(t) << '\n';
}

int main(void)
{
    foo("The answer is: ", 42);
}

#endif

// ----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <tuple>
#include <iostream>

template <typename ... Args>
void foo(Args && ...args)
{
    std::cout << sizeof...(Args) << '\n';
    std::cout << std::tuple_size_v<std::tuple<Args...>> << '\n';
}

int main(void)
{
    foo("The answer is", 42);
    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <tuple>
#include <iostream>

template <
    std::size_t I = 0,
    typename ... Args,
    typename FUNCTION
    >
constexpr void
for_each(const std::tuple<Args...> &t, FUNCTION &&func)
{
    if constexpr (I < sizeof...(Args)) {
        func(std::get<I>(t));
        for_each<I + 1>(t, std::forward<FUNCTION>(func));
    }
}

template <typename... Args>
void foo(Args && ...args)
{
    std::tuple t(std::forward<Args>(args)...);
    for_each(t, [](const auto &arg) {
        std::cout << arg;
    });
}

int main(void)
{
    foo("The answer is: ", 42);
    std::cout << '\n';

    return 0;
}

#endif
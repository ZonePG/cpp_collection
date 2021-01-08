// ----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <thread>
#include <string>
#include <iostream>

void foo()
{
    static std::string msg{"The answer is: 42\n"};
    while (true) {
        for (const auto &c : msg) {
            std::clog << c;
        }
    }
}

int main()
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <mutex>
#include <thread>
#include <string>
#include <iostream>

std::mutex m{};

void foo()
{
    static std::string msg{"The answer is: 42\n"};
    while (true) {
        m.lock();
        for (const auto &c : msg) {
            std::clog << c;
        }
        m.unlock();
    }
}

int main()
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <mutex>
#include <pthread>

std::mutex m{};

void foo()
{
    m.lock();
}

int main(int argc, char const *argv[])
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <array>
#include <mutex>
#include <thread>
#include <string>
#include <iostream>

std::mutex m{};
std::array<int,6> numbers{4,8,15,16,23,42};

int foo(int index)
{
    m.lock();
    // if the index that is provided is larger than the array,
    // the std::array object will throw an exception,
    // resulting before the function has an chance to call unlock(),
    // which will result in deadlock if another thread is sharing this array.
    auto element = numbers.at(index);
    m.unlock();

    return element;
}

int main(void)
{
    std::cout << "The answer is: " << foo(5) << '\n';
    return 0;
}

#endif
// ----------------------------------------------------------------------------
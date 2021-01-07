// ----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>

template <typename T>
class the_answer
{
public:
    the_answer(T t)
    {
        std::cout << "The answer is: " << t << '\n';
    }
};

template class the_answer<int>;
template class the_answer<unsigned>;
template class the_answer<double>;

int main(int argc, char const *argv[])
{
    the_answer{42};
    the_answer{42U};
    the_answer{42.1};

    return 0;
}

#endif
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include "explicit_template_declaration.h"

int main(void)
{
    the_answer is{42};
    is.print();
    
    return 0;
}

#endif
// ----------------------------------------------------------------------------
#include <iostream>
#include "explicit_template_declaration.h"

template <typename T>
the_answer<T>::the_answer(T t) :
    m_answer{t}
{ }

template <typename T>
void the_answer<T>::print()
{
    ::std::cout << "The answer is: " << m_answer << '\n';
}

// template class the_answer<int>;

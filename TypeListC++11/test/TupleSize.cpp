#include "TupleSize.h"

void test()
{
    static_assert(TupleSize<Empty>::value == 0, "");
    static_assert(TupleSize<std::tuple<char>>::value == 1, "");
    static_assert(TupleSize<std::tuple<char, char>>::value == 2, "");
}
#include "SplitAt.h"

#include <tuple>

void TestSplitAt()
{
	using namespace tpl;
    using Tup1 = std::tuple<int, float, double*, unsigned int, void*>;
	using Tup2 = std::tuple<char*>;

	static_assert( std::is_same<SplitAt<Empty, 0>::Left,  Empty>::value, "");
	static_assert( std::is_same<SplitAt<Empty, 0>::Right, Empty>::value, "");
	static_assert( std::is_same<SplitAt<Tup2, 0>::Left,  Empty>::value, "");
	static_assert( std::is_same<SplitAt<Tup2, 0>::Right, Tup2>::value, "");
	static_assert( std::is_same<SplitAt<Tup2, 1>::Left,  Tup2>::value, "");
	static_assert( std::is_same<SplitAt<Tup2, 1>::Right, Empty>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 0>::Left,  Empty>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 0>::Right, Tup1>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 5>::Left,  Tup1>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 5>::Right, Empty>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 4>::Left,  std::tuple<int, float, double*, unsigned int>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 4>::Right, std::tuple<void*>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 3>::Left,  std::tuple<int, float, double*>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 3>::Right, std::tuple<unsigned int, void*>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 2>::Left,  std::tuple<int, float>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 2>::Right, std::tuple<double*, unsigned int, void*>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 1>::Left,  std::tuple<int>>::value, "");
	static_assert( std::is_same<SplitAt<Tup1, 1>::Right, std::tuple<float, double*, unsigned int, void*>>::value, "");
}

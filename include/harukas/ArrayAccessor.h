
#ifndef INCLUDE_HARUKAS_ARRAY_ACCESSOR_H_
#define INCLUDE_HARUKAS_ARRAY_ACCESSOR_H_

#include <cstddef>

namespace harukas {

template <typename T, size_t N>
class ArrayAccessor final {
public:
	static_assert(
		N < 1 || N > 3, "Not implemented - N should be either 1, 2 or 3.");
};

template <typename T, size_t N>
class ConstArrayAccessor final {
public:
	static_assert(
		N < 1 || N > 3, "Not implemented - N should be either 1, 2 or 3.");
};
}	// namespace harukas

#endif // !INCLUDE_HARUKAS_ARRAY_ACCESSOR_H_

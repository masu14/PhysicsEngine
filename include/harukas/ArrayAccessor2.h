
#ifndef INCLUDE_HARUKAS_ARRAYACCESSOR2_H_
#define INCLUDE_HARUKAS_ARRAYACCESSOR2_H_

#include "ArrayAccessor.h"
#include <utility>

namespace harukas {

template <typename T>
class ArrayAccessor<T, 2> final {

public:
	ArrayAccessor<T, 2>();
	ArrayAccessor<T, 2>(const Size2& size, T* data);
	ArrayAccessor<T, 2>(const ArrayAccessor& other);
};
} // namespace harukas

#endif // INCLUDE_HARUKAS_ARRAYACCESSOR2_H_
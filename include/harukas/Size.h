
#ifndef INCLUDE_HARUKAS_SIZE_H_
#define INCLUDE_HARUKAS_SIZE_H_

#include "Point.h"

namespace harukas {

	template <size_t N> using Size = Point<size_t, N>;

}	// namespace harukas

#endif // INCLUDE_HARUKAS_SIZE_H_
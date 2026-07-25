
#ifndef INCLUDE_HARUKAS_MACROS_H_
#define INCLUDE_HARUKAS_MACROS_H_

#if defined(_WIN32) || defined(_WIN64)
#	define HARUKAS_WINDOWS
#endif

#if defined(DEBUG) || defined(_DEBUG)
#	define HARUKAS_DEBUG_MODE
#	include <cassert>
#	define HARUKAS_ASSERT(x) assert(x)
#else
#	define HARUKAS_ASSERT(x)
#endif	// defined(DEBUG) || defined(_DEBUG)

#if defined(HARUKAS_WINDOWS) && defined(_MSC_VER)
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif

#endif // INCLUDE_HARUKAS_MACROS_H_
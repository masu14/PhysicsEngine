
#ifndef INCLUDE_HARUKAS_POINT_H_
#define	INCLUDE_HARUKAS_POINT_H_

#include "Macros.h"
#include <array>
#include <type_traits>

namespace harukas {

template <typename T, size_t N>
class Point final {
public:
	static_assert(
		N > 0, "Size of static-sized point should be greater than zero.");
	static_assert(
		std::is_arithmetic<T>::value,
		"Point only can be instantiated with arithmetic type");

	Point();
	template <typename... Params>
	explicit Point(Params... params);
	template <typename U>
	explicit Point(const std::initializer_list<U>& lst);
	Point(const Point& other);

	template <typename U>
	void set(const std::initializer_list<U>& lst);
	void set(const Point& other);

	template <typename U>
	Point& operator=(const std::initializer_list<U>& lst);
	Point& operator=(const Point& other);
	
	const T& operator[](size_t i) const;
	T& operator[](size_t i);

private:
	std::array<T, N> _elements;

	template <typename... Params>
	void setAt(size_t i, T v, Params... params);
	void setAt(size_t i, T v);
};

} // namespace harukas

#include "detail/Point-inl.h"

#endif // INCLUDE_HARUKAS_POINT_H_
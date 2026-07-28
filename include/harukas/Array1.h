
#ifndef INCLUDE_HARUKAS_ARRAY1_H_
#define INCLUDE_HARUKAS_ARRAY1_H_

#include "Array.h"
#include "ArrayAccessor1.h"

namespace harukas {

template <typename T>
class Array<T, 1> final {
	
public:
	using ContainerType = std::vector<T>;
	using Iterator = typename ContainerType::iterator;
	using ConstIterator = typename ContainerType::const_iterator;

	Array();
	explicit Array(size_t size, const T& initVal = T());
	Array(const std::initializer_list<T>& lst);
	Array(const Array& other);
	Array(Array&& other) noexcept;

	void set(const T& value);
	void set(const Array& other);
	void set(const std::initializer_list<T>& other);

	void clear();
	void resize(size_t size, const T& initVal = T());

	T& at(size_t i);
	const T& at(size_t i) const;

	size_t size() const;

	T* data();
	const T* data() const;

	Iterator begin();
	ConstIterator begin() const;
	Iterator end();
	ConstIterator end() const;

	ArrayAccessor1<T> accessor();
	ConstArrayAccessor1<T> constAccessor() const;

	void swap(Array& other);
	void append(const T& newVal);
	void append(const Array& other);

	template <typename Callback>
	void forEach(Callback func) const;
	template <typename Callback>
	void forEachIndex(Callback func) const;
	template <typename Callback>
	void parallelForEach(Callback func);
	template <typename Callback>
	void parallelForEachIndex(Callback func) const;

	T& operator[](size_t i);
	const T& operator[](size_t i) const;

	Array& operator=(const T& value);
	Array& operator=(const Array& other);
	Array& operator=(Array&& other) noexcept;
	Array& operator=(const std::initializer_list<T>& lst);

	operator ArrayAccessor1<T>();
	operator ConstArrayAccessor1<T>() const;

private:
	ContainerType _data;
};

template <typename T>
using Array1 = Array<T, 1>;

} // namespace harukas

#include "detail/Array1-inl.h"

#endif // INCLUDE_HARUKAS_ARRAY1_H_
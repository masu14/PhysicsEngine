
#ifndef INCLUDE_HARUKAS_ARRAY_ACCESSOR1_H_
#define INCLUDE_HARUKAS_ARRAY_ACCESSOR1_H_

#include "ArrayAccessor.h"
#include <utility>

namespace harukas {

template <typename T>
class ArrayAccessor<T, 1> final {
public:
	ArrayAccessor();
	ArrayAccessor(size_t size, T* const data);
	ArrayAccessor(const ArrayAccessor& other);
	void set(const ArrayAccessor& other);
	void reset(size_t size, T* const data);
	T& at(size_t i);
	const T& at(size_t i) const;
	T* const begin() const;
	T* const end() const;
	T* begin();
	T* end();
	size_t size() const;
	T* const data() const;
	void swap(ArrayAccessor& other);

	template <typename Callback>
	void forEach(Callback func) const;
	template <typename Callback>
	void forEachIndex(Callback func) const;
	template <typename Callback>
	void parallelForEachIndex(Callback func) const;

	T& operator[](size_t i);
	const T& operator[](size_t i) const;
	ArrayAccessor& operator=(const ArrayAccessor& other);
	operator ConstArrayAccessor<T, 1>() const;

private:
	size_t _size;
	T* _data;
};

template <typename T> using ArrayAccessor1 = ArrayAccessor<T, 1>;

template <typename T>
class ConstArrayAccessor<T, 1> {
public:
	ConstArrayAccessor();
	ConstArrayAccessor(size_t size, const T* const data);
	explicit ConstArrayAccessor(const ArrayAccessor<T, 1>& other);
	ConstArrayAccessor(const ConstArrayAccessor& other);
	const T& at(size_t i) const;
	const T* const begin() const;
	const T* const end() const;
	size_t size() const;
	const T* const data() const;

	template <typename Callback>
	void forEach(Callback func) const;
	template <typename Callback>
	void forEachIndex(Callback func) const;
	template <typename Callback>
	void parallelForEachIndex(Callback func) const;

private:
	size_t _size;
	const T* _data;
};

template <typename T> using ConstArrayAccessor1 = ConstArrayAccessor<T, 1>;
}	// namespace harukas

#include "detail/ArrayAccessor1-inl.h"

#endif // INCLUDE_HARUKAS_ARRAY_ACCESSOR1_H_
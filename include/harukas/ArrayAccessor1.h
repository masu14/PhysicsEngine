
#ifndef INCLUDE_HARUKAS_ARRAY_ACCESSOR1_H_
#define INCLUDE_HARUKAS_ARRAY_ACCESSOR1_H_

#include "ArrayAccessor.h"
#include <utility>

namespace harukas {

template <typename T>
class ArrayAccessor<T, 1> final {
public:
	ArrayAccessor();
	ArrayAccessor(size_t size, T* data);
	ArrayAccessor(const ArrayAccessor& other);

	void set(const ArrayAccessor& other);
	void reset(size_t size, T* data);

	T& at(size_t i);
	const T& at(size_t i) const;

	T* begin() const;
	T* end() const;
	
	size_t size() const;
	T* data() const;

	void swap(ArrayAccessor& other);

	template <typename Callback>
	void forEach(Callback func) const;
	template <typename Callback>
	void forEachIndex(Callback func) const;
	template <typename Callback>
	void parallelForEach(Callback func) const;
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
class ConstArrayAccessor<T, 1> final {
public:
	ConstArrayAccessor();
	ConstArrayAccessor(size_t size, const T* data);

	explicit ConstArrayAccessor(const ArrayAccessor<T, 1>& other);
	ConstArrayAccessor(const ConstArrayAccessor& other);

	const T& at(size_t i) const;

	const T* begin() const;
	const T* end() const;

	size_t size() const;
	const T* data() const;

	template <typename Callback>
	void forEach(Callback func) const;
	template <typename Callback>
	void forEachIndex(Callback func) const;
	template <typename Callback>
	void parallelForEachIndex(Callback func) const;

	const T& operator[](size_t i) const;
private:
	size_t _size;
	const T* _data;
};

template <typename T> using ConstArrayAccessor1 = ConstArrayAccessor<T, 1>;
}	// namespace harukas

#include "detail/ArrayAccessor1-inl.h"

#endif // INCLUDE_HARUKAS_ARRAY_ACCESSOR1_H_
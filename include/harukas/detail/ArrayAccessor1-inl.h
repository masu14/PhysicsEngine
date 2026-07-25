
#ifndef INCLUDE_HARUKAS_DETAIL_ARRAY_ACCESSOR1_INL_H_
#define INCLUDE_HARUKAS_DETAIL_ARRAY_ACCESSOR1_INL_H_

#include "../Macros.h"

#include <utility>

namespace harukas {
	
template <typename T>
ArrayAccessor<T, 1>::ArrayAccessor() : _size(0), _data(nullptr) {
}

template <typename T>
ArrayAccessor<T, 1>::ArrayAccessor(size_t size, T* data) {
	reset(size, data);
}

template <typename T>
ArrayAccessor<T, 1>::ArrayAccessor(const ArrayAccessor& other) {
	set(other);
}

template <typename T>
void ArrayAccessor<T, 1>::set(const ArrayAccessor& other) {
	reset(other._size, other._data);
}

template <typename T>
void ArrayAccessor<T, 1>::reset(size_t size, T* data) {
	_size = size;
	_data = data;
}

template <typename T>
T& ArrayAccessor<T, 1>::at(size_t i){
	HARUKAS_ASSERT(i < _size);
	return _data[i];
}

template <typename T>
const T& ArrayAccessor<T, 1>::at(size_t i) const {
	HARUKAS_ASSERT(i < _size);
	return _data[i];
}

template <typename T>
T* ArrayAccessor<T, 1>::begin() const {
	return _data;
}

template <typename T>
T* ArrayAccessor<T, 1>::end() const {
	return _data + _size;
}

template <typename T>
size_t ArrayAccessor<T, 1>::size() const {
	return _size;
}

template <typename T>
T* ArrayAccessor<T, 1>::data() const {
	return _data;
}

template <typename T>
void ArrayAccessor<T, 1>::swap(ArrayAccessor& other) {
	std::swap(other.data, _data);
	std::swap(other.size, _size);
}

template <typename T>
template <typename Callback>
void ArrayAccessor<T, 1>::forEach(Callback func) const {
	for (size_t i = 0; i < size(); ++i) {
		func(at(i));
	}
}

template <typename T>
template <typename Callback>
void ArrayAccessor<T, 1>::forEachIndex(Callback func) const {
	for (size_t i = 0; i < size(); ++i) {
		func(i);
	}
}

template <typename T>
template <typename Callback>
void ArrayAccessor<T, 1>::parallelForEach(Callback func) const {
	
}

template <typename T>
template <typename Callback>
void ArrayAccessor<T, 1>::parallelForEachIndex(Callback func) const {

}

} // namespace harukas

#endif // INCLUDE_HARUKAS_DETAIL_ARRAY_ACCESSOR1_INL_H_
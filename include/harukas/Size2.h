
#ifndef INCLUDE_HARUKAS_SIZE2_H_
#define INCLUDE_HARUKAS_SIZE2_H_

namespace harukas {

class Size2 {

public:
	size_t x;
	size_t y;

	constexpr Size2() :x(0), y(0) {}
	constexpr Size2(size_t x_, size_t y_) : x(x_), y(y_) {}

	template <typename U>
	Size2(const std::initializer_list<U>& lst);

	constexpr Size2(const Size2& v) : x(v.x), y(v.y){}

	void set(size_t s);
	void set(size_t x, size_t y);
	template <typename U>
	void set(const std::initializer_list<U>& lst);
	void set(const Size2& pt);
	void setZero();

	Size2 add(size_t v) const;
	Size2 add(const Size2& v) const;
	Size2 sub(size_t v) const;
	Size2 sub(const Size2& v) const;
	Size2 mul(size_t v) const;
	Size2 mul(const Size2& v) const;
	Size2 div(size_t v) const;
	Size2 div(const Size2& v) const;

	Size2 rsub(size_t v) const;
	Size2 rsub(const Size2& v) const;
	Size2 rdiv(size_t v) const;
	Size2 rdiv(const Size2& v) const;

	void iadd(size_t v);
	void iadd(const Size2& v);
	void isub(size_t v);
	void isub(const Size2& v);
	void imul(size_t v);
	void imul(const Size2& v);
	void idev(size_t v);
	void idev(const Size2& v);
};

} // namespace harukas

#endif // !INCLUDE_HARUKAS_SIZE2_H_


#ifndef INCLUDE_HARUKAS_DETAIL_PARALLEL_INL_H_
#define INCLUDE_HARUKAS_DETAIL_PARALLEL_INL_H_

#include "../Constants.h"
#include "../Macros.h"

#include <algorithm>
#include <functional>
#include <future>
#include <vector>

#ifdef HARUKAS_TASKING_TBB
#elif defined(HARUKAS_TASKING_CPP11THREADS)
#include <thread>
#endif

namespace harukas {
namespace internal {

template <typename TASK_T>
inline void schedule(TASK_T&& fcn) {
#ifdef HARUKAS_TASKING_TBB

#elif defined(HARUKAS_TASKING_CPP11THREADS)

#else // OpenMP or Serial --> synchronous!
	fcn();
#endif
}

template <typename TASK_T>
using operator_return_t = typename std::result_of<TASK_T()>::type;

template <typename TASK_T>
inline auto async(TASK_T&& fcn) -> std::future<operator_return_t<TASK_T>> {
	using package_t = std::packaged_task<operator_return_t<TASK_T>()>;

	auto task = new package_t(std::forward<TASK_T>(fcn));
	auto future = task->get_future();

	schedule([=]() {
		(*task)();
		delete task;
		});

	return future;
}

} // namespace internal

template <typename RandomIterator, typename T>
void parallelFill(
	const RandomIterator& begin, const RandomIterator& end,
	const T& value, ExecutionPolicy policy) {
	auto diff = end - begin;
	if (diff <= 0) {
		return;
	}

	size_t size = static_cast<size_t>(diff);
	parallelFor(kZeroSize, size, [begin, value](size_t i) { begin[i] = value; }, policy);
}

template <typename IndexType, typename Function>
void parallelFor(
	IndexType start, IndexType end, 
	const Function& function, ExecutionPolicy policy) {
	if (start >= end) {
		return;
	}

#ifdef HARUKAS_TASKING_TBB

#elif HARUKAS_TASKING_CPP11THREADS

#else

#ifdef HARUKAS_TASKING_OPENMP

#else	// HARUKAS_TASKING_OPENMP
	for (auto i = start; i < end; ++i) {
		function(i);
	}
#endif	// HARUKAS_TASKING_OPENMP

#endif
}

template <typename IndexType, typename Function>
void parallelRangeFor(
	IndexType start, IndexType end,
	const Function& function, ExecutionPolicy policy) {
	if (start >= end) {
		return;
	}

#ifdef HARUKAS_TASKING_TBB

#else
	unsigned int numThreadsHint = maxNumberOfThreads();
	const unsigned int numThreads =
		(policy == ExecutionPolicy::kParallel)
		? (numThreadsHint == 0u ? 8u : numThreadsHint)
		: 1;

	IndexType n = end - start;
	IndexType slice = (IndexType)std::round(n / static_cast<double>(numThreads));
	slice = std::max(slice, IndexType(1));

	std::vector<std::future<void>> pool;
	pool.reserve(numThreads);
	IndexType i1 = start;
	IndexType i2 = std::min(start + slice, end);
	for (unsigned int i = 0; i + 1 < numThreads && i1 < end; ++i) {
		pool.emplace_back(internal::async([=]() {func(i1, i2); }));
		i1 = i2;
		i2 = std::min(i2 + slice, end);
	}
	if (i1 < end) {
		pool.emplace_back(internal::async([=]() {func(i1, end); }));
	}

	for (auto& f : pool) {
		if (f.valid()) {
			f.wait();
		}
	}
#endif
}

template <typename IndexType, typename Function>
void parallelFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	const Function& function, ExecutionPolicy policy){
	parallelFor(beginIndexY, endIndexY,
		[&](IndexType j) {
			for (IndexType i = beginIndexX; i < endIndexX; ++i) {
				function(i, j);
			}
		},
		policy);
}

template <typename IndexType, typename Function>
void parallelRangeFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	const Function& function, ExecutionPolicy policy) {
	parallelRangeFor(beginIndexY, endIndexY,
		[&](IndexType jBegin, IndexType jEnd) {
			function(beginIndexX, endIndexX, jBegin, jEnd);
		},
		policy);
}

template <typename IndexType, typename Function>
void parallelFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	IndexType beginIndexZ, IndexType endIndexZ,
	const Function& function, ExecutionPolicy policy) {
	parallelFor(beginIndexZ, endIndexZ,
		[&](IndexType k) {
			for (IndexType j = beginIndexY; j < endIndexY; ++j) {
				for (IndexType i = beginIndexX; i < endIndexX; ++i) {
					function(i, j, k);
				}
			}
		},
		policy);
}

template <typename IndexType, typename Function>
void parallelRangeFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	IndexType beginIndexZ, IndexType endIndexZ,
	const Function& function, ExecutionPolicy policy) {
	parallelRangeFor(beginIndexZ, endIndexZ,
		[&](IndexType kBegin, IndexType kEnd) {
			function(beginIndexX, endIndexX, beginIndexX, endIndexY, kBegin, kEnd);
		},
		policy);
}

} // namespace harukas

#endif // INCLUDE_HARUKAS_DETAIL_PARALLEL_INL_H_
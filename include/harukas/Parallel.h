
#ifndef INCLUDE_HARUKAS_PARALLEL_H_
#define INCLUDE_HARUKAS_PARALLEL_H_

namespace harukas {

enum class ExecutionPolicy { kSerial, kParallel };

template <typename RandomIterator, typename T>
void parallelFill(
	const RandomIterator& begin, const RandomIterator& end,
	const T& value, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Function>
void parallelFor(
	IndexType beginIndex, IndexType endIndex,
	const Function& function, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Function>
void parallelRangeFor(
	IndexType beginIndex, IndexType endIndex,
	const Function& function, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Function> 
void parallelFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	const Function& function, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Function>
void parallelRangeFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	const Function& function, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Function>
void parallelFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	IndexType beginIndexZ, IndexType endIndexZ,
	const Function& function, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Function>
void parallelRangeFor(
	IndexType beginIndexX, IndexType endIndexX,
	IndexType beginIndexY, IndexType endIndexY,
	IndexType beginIndexZ, IndexType endIndexZ,
	const Function& function, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename IndexType, typename Value, typename Function, typename Reduce>
Value parallelReduce(
	IndexType beginIndex, IndexType endIndex,
	const Value& identity, const Function& func,
	const Reduce& reduce, ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename RandomIterator>
void parallelSort(
	RandomIterator begin, RandomIterator end,
	ExecutionPolicy policy = ExecutionPolicy::kParallel);

template <typename RandomIterator, typename CompareFunction>
void parallelSort(
	RandomIterator begin, RandomIterator end,
	CompareFunction compare,
	ExecutionPolicy policy = ExecutionPolicy::kParallel);

void setMaxNumberOfThreads(unsigned int numThreads);
unsigned int maxNumberOfThreads();

}	// namespace harukas

#include "detail/Parallel-inl.h"

#endif	// INCLUDE_HARUKAS_PARALLEL_H_
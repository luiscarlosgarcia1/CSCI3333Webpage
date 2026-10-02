## Dr. Whylie’s Priority Queue

Suppose Dr. Whylie comes up to you and claims that he has invented a super-fast comparison-based priority queue. The speeds of the priority queue operations are as follows, where `n` is the number of items currently in the priority queue:

a. Insert a new item in `O(√(log n))` time.
b. Extract (remove and return) the smallest item from the priority queue in `O(√(log n))` time.

Is this possible for a comparison-based priority queue? If so, provide a data structure that achieves these running times. If not, prove that it is impossible.

## Explanation

No, this is not possible for a comparison-based priority queue.

Here is how we could use Dr. Whylie's priority queue to sort `n` numbers:

1. Insert all `n` numbers into the priority queue.
2. Extract the smallest item `n` times.

The extracted items come out from smallest to largest, so this would sort the numbers.

Each insert and each extract is claimed to take `O(sqrt(log n))` time. There are `n` inserts and `n` extracts, so the total sorting time would be:

```text
O(n sqrt(log n))
```

But every comparison-based sorting algorithm needs at least:

```text
Omega(n log n)
```

time in the worst case. Since `sqrt(log n)` grows more slowly than `log n`, `n sqrt(log n)` is asymptotically smaller than `n log n`. In other words, Dr. Whylie's queue would let us sort faster than the proven lower bound for comparison sorting.

That is a contradiction. Therefore, a comparison-based priority queue cannot guarantee both insert and extract-min in `O(sqrt(log n))` time.

# Week 2 Recap

## Binary Search

### 1. Recap

Binary search finds a target in a sorted array. It checks the middle value, then discards the half that cannot contain the target. Its running time is `O(log N)`.

### 2. Visual

Search for `23`:

```text
[ 4, 8, 12, 17, 23, 31, 42 ]
             ^
            17

23 > 17, so search the right half.

[ 23, 31, 42 ]
   ^
 target
```

### 3. Pseudocode

```text
binarySearch(a, x):
    low = 0
    high = a.size() - 1

    while low <= high:
        mid = (low + high) // 2
        if a[mid] < x: low = mid + 1
        else if a[mid] > x: high = mid - 1
        else: return mid

    return -1
```

## QuickSort

### 1. Recap

QuickSort is a divide-and-conquer algorithm: choose a **pivot**, split the remaining values into a group that are smaller than the pivot and a group that are larger than the pivot, then recursively sort both groups.

Its average running time is `O(N log N)`, although consistently poor pivot choices or an array with values close to decending order can produce `O(N^2)` time.

### 2. Visual

Suppose the pivot is `5`:

```text
Unsorted values
[ 8, 3, 5, 1, 7, 4 ]
        ^
      pivot

After partitioning around 5
[ 3, 1, 4 ], 5, [ 8, 7 ]
   <= 5           >= 5

QuickSort(left)     pivot     QuickSort(right)
   [ 1, 3, 4 ],       5,          [ 7, 8 ]

Final result: [ 1, 3, 4, 5, 7, 8 ]
```

### 3. Pseudocode

```text
quickSort(A):
    if a has zero or one element:
        stop

    choose pivot
    partition A in place around the pivot
    quickSort(left subarray)
    quickSort(right subarray)
```

QuickSort rearranges the original array; it does not build separate left and right arrays.

*Textbook basis: Section 7.7, “Quicksort.”*

## Merge Sort

### 1. Recap

Merge sort divides an array into smaller halves, sorts each half, then merges the sorted halves. Merging takes the smaller front value each time. Its running time is `O(N log N)`.

### 2. Visual

```text
   [ 8, 3, 5, 1 ]
      /      \
[ 8, 3 ]  [ 5, 1 ]
    /  \      /  \
  [ 8 ][ 3 ][ 5 ][ 1 ]
    \  /      \  /
  [ 3, 8 ]  [ 1, 5 ]
      \      /
    [ 1, 3, 5, 8 ]
```

### 3. Pseudocode

```text
mergeSort(a):
    if a has one element:
        return a

    split a into two halves
    return merge(mergeSort(left), mergeSort(right))

merge(left, right):
    repeatedly copy the smaller front value
    when one subarray is empty, copy what remains
```

*Textbook basis: Section 7.6, “Mergesort.”*

## Asymptotic Notation

### 1. Recap

Asymptotic notation compares how an algorithm's running time grows as input size, `N`, gets large. It ignores constant factors and lower-order terms so we can focus on the growth rate.

- `O` gives an upper bound.
- `Ω` gives a lower bound.
- `Θ` gives a tight bound.

### 2. Visual

```text
T(N) = 2N² + 7N + 4

small N:  7N and 4 matter
large N:  2N² dominates

T(N) = Θ(N²)

1 < log N < N < N log N < N² < 2ᴺ
```

### 3. Pseudocode

```text
for i from 0 to N - 1:
    for j from 0 to N - 1:
        do constant work
```

The inner loop runs `N` times for each of `N` outer-loop passes: `N × N = N²`. The running time is `Θ(N²)`.

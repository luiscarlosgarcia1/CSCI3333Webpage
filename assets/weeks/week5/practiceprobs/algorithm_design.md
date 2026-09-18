## Algorithm Design

Given a sorted array of n comparable items A sorted at indices A[1], A[2], ..., A[n], and a search value key, return the position (array index) of key in A if it is present, or -1 if it is not present. If key is present in A, your algorithm must run in order O(log k) time, where k is the index location of key in A, i.e., A[k] = key. Otherwise, if key is not present, your algorithm must run in O(log n) time. Please note that doing a binary search is not sufficient as this algorithm must run faster than O(log n) when the item searched for is close to the front of the array. A well-written description of the steps of your algorithm (pseudo code) is sufficient for this problem (no need for C++ code).

### Exponential Search

1. Check the first item in the array. If it is the key, return its index immediately.

2. Starting at the second item, repeatedly double the index being checked: check positions 1, 2, 4, 8, 16, and so on. Stop when either the checked value is greater than or equal to the key, or the checked index reaches or passes the end of the array.

3. The key, if it exists, must be between the previous checked position and the current checked position. If the current position passed the end of the array, use the last position in the array as the end of this range.

4. Use binary search only within this smaller range. If binary search finds the key, return its index; otherwise, return `-1`.

Because the range grows exponentially, it reaches a key at index `k` after `O(log k)` checks. The final binary search also takes `O(log k)` time. If the key is not in the array, the search may reach the end of the array, which takes `O(log n)` time.

# Unique Paths

## Problem

Start at top-left. Finish at bottom-right. Move only:

- right
- down

Return the number of different paths.

```text
m = 3, n = 3

S → . → .
↓   ↓   ↓
. → . → .
↓   ↓   ↓
. → . → F

answer = 6
```

## Step 1: Plain recursion

Define the helper first.

> `dfs(i, j)` = number of paths from cell `(i, j)` to the finish.

From `(i, j)`, move right or down. Add the answers because both moves create valid paths.

```text
dfs(i, j) = 1                                if (i, j) is finish
dfs(i, j) = 0                                if outside grid
dfs(i, j) = dfs(i, j + 1) + dfs(i + 1, j)   otherwise
```

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(0, 0, m, n);
    }

private:
    int dfs(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (i >= m || j >= n) {
            return 0;
        }

        return dfs(i, j + 1, m, n) +  // right
               dfs(i + 1, j, m, n);   // down
    }
};
```

### Problem: repeated work

```text
dfs(0, 0)
├── dfs(0, 1)
│   └── dfs(1, 1)  // solve
└── dfs(1, 0)
    └── dfs(1, 1)  // solve again
```

Same cell. Same answer. Too much repeated work.

| Version | Time | Extra space |
| --- | --- | --- |
| Plain recursion | O(2^(m + n)) | O(m + n) call stack |

## Step 2: Top-down DP = recursion + memory

Keep the same `dfs`. Add a 2D cache.

> `memo[i][j]` = number of paths from `(i, j)` to the finish.

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        memo.assign(m, vector<int>(n, -1));
        return dfs(0, 0, m, n);
    }

private:
    vector<vector<int>> memo;

    int dfs(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (i >= m || j >= n) {
            return 0;
        }

        // Already solved? Reuse it.
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = dfs(i, j + 1, m, n) + dfs(i + 1, j, m, n);
        return memo[i][j];
    }
};
```

There are only `m * n` cells. Solve each cell once.

| Version | What changed? | Time | Extra space |
| --- | --- | --- | --- |
| Plain recursion | Repeats cells | O(2^(m + n)) | O(m + n) stack |
| Top-down DP | Each cell solved once | O(mn) | O(mn) memo + stack |

`-1` is safe: number of paths cannot be negative.
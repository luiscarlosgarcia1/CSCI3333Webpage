## Count Words With a Prefix

Given a Trie that stores lowercase English words, write a function:

```cpp
int countWordsWithPrefix(TrieNode* root, string prefix);
```

This function should return the number of words in the trie that start with the given prefix. You must use a recursive helper function.

Helper function:

```cpp
int countWordsRec(TrieNode* node);
```

## Code

```cpp
#include <string>

using namespace std;

class node {
public:
    node* children[256] {};
    bool marked = false;
};

int countWordsRec(node* n)
{
    if (n == nullptr)
        return 0;

    // counter
    int sum = 0;

    // incrememnt counter if we are marked
    if (n->marked)
        sum++;

    // recursively count the completions beneath us
    for (int i = 0; i < 256; ++i)
        sum += countWordsRec(n->children[i]);

    // return the number of completions
    return sum;
}

int countWordsWithPrefix(node* root, string prefix)
{
    if (root == nullptr)
        return 0;

    node* cur = root;

    // loop through our trie to get to a point in the trie where the prefix is
    for (int i = 0; i < prefix.length(); ++i)
    {
        if (!cur->children[prefix[i]])
            return 0;

        cur = cur->children[prefix[i]];
    }

    // when we find the location of the prefix, call the recursive function to count
    // the number of completions beneath our node and return that value
    return countWordsRec(cur);
}
```

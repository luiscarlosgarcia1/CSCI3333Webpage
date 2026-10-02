## Longest Word With a Prefix

Write a function:

```cpp
string longestWordWithPrefix(TrieNode* root, string prefix);
```

It should return the longest word in the trie that starts with `prefix`. If multiple words tie, return any one.

You must use a recursive helper.

Helper:

```cpp
void longestWordRec(TrieNode* node, string current, string& longest);
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

void longestWordRec(node* n, string current, string& longest)
{
    // base case: node is nullptr
    if (n == nullptr)
        return;

    // are we at the end of a word and is it longer than the one we've already found
    if (n->marked && current.length() > longest.length())
        longest = current;

    for (int i = 0; i < 256; i++)
    {
        if (n->children[i])
            longestWordRec(n->children[i], current + char(i), longest);
    }
}

string longestWordWithPrefix(node* root, string prefix)
{
    if (root == nullptr)
        return "";

    node* cur = root;
    string res = "";

    // loop through our trie to get to a point in the trie where the prefix is
    for (int i = 0; i < prefix.length(); i++)
    {
        if (!cur->children[prefix[i]])
            return "";

        cur = cur->children[prefix[i]];
    }

    // when we find the location of the prefix, call the recursive function
    // to find the longest completion of our prefix and return it
    longestWordRec(cur, prefix, res);
    return res;
}
```

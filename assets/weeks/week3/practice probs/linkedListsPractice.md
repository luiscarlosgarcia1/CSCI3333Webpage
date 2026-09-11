## Linked List

For these questions, the data type `node` refers to the type defined by the class:

```cpp
class node
{
public:
    int data;
    node * next;
};
```

A node contains two fields: `data` and `next`.

Consider the linked list below, with node pointers `ptrA` and `ptrB` pointing to the specified nodes in the list, and `head` pointing to the first node in the list.

```text
head
  |
  v
[15] -> [8] -> [32] -> [12] -> [2] -> [57] -> [23] -> [19] -> Null
                         ^      ^
                       ptrA    ptrB
```

### a.

Assume `ptrB` points to the node with `2` in the data field and `ptrA` points to the node previous to that node. What C++ statements would delete the node with `2` from the list? Be sure your code does not create a memory leak.

<br><br><br>

### b.

Assume `ptrB` points to the node with `2` in the data field and `ptrA` points to the node previous to that node. What C++ statements would create and insert a node containing `63` into the list after the node containing `2`?

<br><br><br>

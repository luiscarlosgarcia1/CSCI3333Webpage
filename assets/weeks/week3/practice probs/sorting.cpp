#include <iostream>
#include <utility>

// Sorting
//
// For this question, suppose you have a linkedList class that includes methods
// 'split' and 'merge', already implemented (exactly as was done in the homework).
//
// split: Splits the contents of a list evenly into two given (initially empty)
// lists. If the number of items in the list is odd, the extra item goes in the
// first list. It runs in O(n) time, where n is the number of items in the list.
//
// merge: Takes two sorted lists and merges them into the calling (initially
// empty) list, creating one sorted list. It runs in O(n) time, where n is the
// total number of items in the two given lists.
//
// Add a sort() method to linkedList that sorts the items into ascending order
// with a fast running time. The split and merge methods may be used to help.

class linkedList {
private:
    class node {
    public:
        double data;
        node* next;
        node* prev;

        // Make a new node and set its data and links.
        node(double value) {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head;  // Pointer to the first node in the list.
    node* tail;  // Pointer to the last node in the list.
    int count;

public:
    // Moves this list's nodes alternately into A and B. When the size is odd,
    // A receives the extra node.
    void split(linkedList& A, linkedList& B) {
        A.clear();
        B.clear();

        bool putInA = true;
        while (head != nullptr) {
            node* item = head;
            head = head->next;
            --count;

            if (putInA) {
                A.appendNode(item);
            } else {
                B.appendNode(item);
            }
            putInA = !putInA;
        }
        tail = nullptr;
    }

    // Merges sorted A and B into this initially empty list, moving their nodes.
    void merge(linkedList& A, linkedList& B) {
        clear();

        while (A.head != nullptr || B.head != nullptr) {
            linkedList* source = nullptr;
            if (B.head == nullptr ||
                (A.head != nullptr && A.head->data <= B.head->data)) {
                source = &A;
            } else {
                source = &B;
            }

            node* item = source->head;
            source->head = item->next;
            if (source->head != nullptr) {
                source->head->prev = nullptr;
            } else {
                source->tail = nullptr;
            }
            --source->count;
            appendNode(item);
        }
    }

    // Merge sort: O(n log n) time and O(log n) call-stack space.
    void sort() {
        if (!head || !head->next) {
            return;
        }

        linkedList A;
        linkedList B;

        split(A, B);

        A.sort();
        B.sort();

        merge(A, B);
    }
};
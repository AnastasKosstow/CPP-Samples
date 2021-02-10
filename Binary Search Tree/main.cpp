
#include <iostream>
#include <vector>

#include "BinarySearchTree.h"

void printVector(const std::vector<int>* vec);

int main()
{
    const unsigned size = 4;
    int arr[size] = { 9, 2, 5, 3 };

    binarySearchTree::BinarySearchТрее BST(arr, size);
    BST.Insert(6);
    BST.Insert(21);
    BST.Insert(14);
    BST.Insert(19);
    BST.Insert(10);

    // Expected Result: 2 3 5 6 9 10 14 19 21
    std::vector<int>* vec = BST.GetAll();
    printVector(vec);


    // Find, Delete and replace with successor if any
    if (BST.Contains(14) &&
        BST.Contains(19))
    {
        BST.Delete(14);
        BST.Delete(19);
    }

    // Expected Result: 2 3 5 6 9 10 21
    vec = BST.GetAll();
    printVector(vec);

    return 0;
}

void printVector(const std::vector<int>* vec)
{
    std::copy(vec->begin(),
        vec->end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

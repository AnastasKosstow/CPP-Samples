
#pragma once

#include <vector>

namespace binarySearchTree
{
    class BinarySearchТрее
    {
    private:
        struct Node
        {
            int data_;

            Node* leftNode_;
            Node* rightNode_;

            Node(int data)
                : data_(data), leftNode_(nullptr), rightNode_(nullptr)
            {
            }

            /*
                #include <utility>

                Node* extract_left()
                {
                    return std::exchange(leftNode_, nullptr);
                }
                Node* extract_right()
                {
                    return std::exchange(rightNode_, nullptr);
                }
            */
        };

        Node* root_;
        unsigned size_;


        Node* Contains(int valueToFind, Node* node);

        Node* Delete(Node* nodePtr, int valueForDelete);

        Node* Insert(Node* focusNode, const int& value);

        std::vector<int>* GetAll(Node* focusNode, std::vector<int>* _v);

    public:
        BinarySearchТрее();

        BinarySearchТрее(int* const params, const unsigned& lenght);

        ~BinarySearchТрее();


        bool Contains(int valueToFind);

        void Delete(int valueForDelete);

        void Insert(const int& value);

        std::vector<int>* GetAll();
    };
}

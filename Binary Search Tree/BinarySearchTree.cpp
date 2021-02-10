
#include <vector>
#include <iostream>
#include "BinarySearchTree.h"

namespace binarySearchTree
{
	BinarySearchТрее::BinarySearchТрее()
		: root_(nullptr), size_(0)
	{
	}


	BinarySearchТрее::BinarySearchТрее(int* const params, const unsigned& lenght)
		: root_(nullptr), size_(0)
	{
		for (unsigned index = 0; index < lenght; index++)
			Insert(params[index]);
	}


	BinarySearchТрее::~BinarySearchТрее()
	{
	}


	/// <summary>
	/// Check if value exists
	/// </summary>
	bool BinarySearchТрее::Contains(int valueToFind)
	{
		Node* node = Contains(valueToFind, root_);

		return (node == NULL)
			? false
			: true;
	}


	/// <summary>
	/// Delete single Node and replace it with successor
	/// </summary>
	void BinarySearchТрее::Delete(int valueForDelete)
	{
		Delete(root_, valueForDelete);
	}



	/// <summary>
	/// Adding new elements using Recursion
	/// </summary>
	void BinarySearchТрее::Insert(const int& value)
	{
		if (root_ == NULL)
		{
			root_ = new Node(value);
			size_++;
			return;
		}

		root_ = Insert(root_, value);
	}


	/// <summary>
	/// Retrieve all elements from the tree
	/// </summary>
	std::vector<int>* BinarySearchТрее::GetAll()
	{
		std::vector<int>* values = new std::vector<int>();
		values->reserve(size_);

		if (root_ == NULL)
			return values;

		return GetAll(root_, values);
	}


	/// <summary>
	/// Private Functions for Recursion
	/// </summary>

	BinarySearchТрее::Node* BinarySearchТрее::Contains(int valueToFind, Node* node)
	{
		if (node == NULL)
			return NULL;

		if (valueToFind > node->data_)
			return Contains(valueToFind, node->rightNode_);

		else if (valueToFind < node->data_)
			return Contains(valueToFind, node->leftNode_);

		return node;
	}


	BinarySearchТрее::Node* BinarySearchТрее::Delete(Node* nodePtr, int valueForDelete)
	{
		if (nodePtr == NULL)
			return root_;

		// Recursive calls for ancestors of node to be deleted
		if (nodePtr->data_ > valueForDelete)
		{
			nodePtr->leftNode_ = Delete(nodePtr->leftNode_, valueForDelete);
			return nodePtr;
		}
		else if (nodePtr->data_ < valueForDelete) {
			nodePtr->rightNode_ = Delete(nodePtr->rightNode_, valueForDelete);
			return nodePtr;
		}

		if (nodePtr->leftNode_ == NULL && nodePtr->rightNode_ == NULL)
		{
			return nullptr;
		}
		else if (nodePtr->leftNode_ == NULL)
		{
			Node* temp = nodePtr->rightNode_;
			delete nodePtr;
			return temp;
		}
		else if (nodePtr->rightNode_ == NULL)
		{
			Node* temp = nodePtr->leftNode_;
			delete nodePtr;
			return temp;
		}

		// If both children exist
		else
		{
			Node* succParent = nodePtr;

			// Find successor
			Node* successor = nodePtr->rightNode_;
			while (successor->leftNode_ != NULL) {
				succParent = successor;
				successor = successor->rightNode_;
			}

			if (succParent != nodePtr)
				succParent->leftNode_ = successor->leftNode_;
			else
				succParent->rightNode_ = successor->rightNode_;

			// Copy Successor Data to root
			nodePtr->data_ = successor->data_;

			// Delete Successor and return root
			delete successor;
			return nodePtr;
		}
	}


	BinarySearchТрее::Node* BinarySearchТрее::Insert(Node* focusNode, const int& value)
	{
		if (focusNode == NULL)
		{
			return new Node(value);
			size_++;
		}

		if (value > focusNode->data_)
		{
			focusNode->rightNode_ = Insert(focusNode->rightNode_, value);
		}
		else focusNode->leftNode_ = Insert(focusNode->leftNode_, value);

		return focusNode;
	}


	std::vector<int>* BinarySearchТрее::GetAll(Node* focusNode, std::vector<int>* _v)
	{
		if (focusNode != nullptr)
		{
			GetAll(focusNode->leftNode_, _v);
			_v->emplace_back(focusNode->data_);
			GetAll(focusNode->rightNode_, _v);
		}
		return _v;
	}
}

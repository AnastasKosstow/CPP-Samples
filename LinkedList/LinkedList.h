
#pragma once

namespace linkedList
{
	template<typename T>
	class LinkedList
	{
	private:
		struct Node
		{
			T data_;

			Node* next_;

			Node(T data)
				: data_(data), next_(nullptr)
			{
			}
		};

		class Iterator
		{
		private:
			Node* currentNode_;

		public:
			Iterator(Node* first);

			_NODISCARD Iterator& operator++() noexcept;

			_NODISCARD T& operator*() const noexcept;

			_NODISCARD bool operator==(const LinkedList<T>::Iterator& _Right) const noexcept;

			_NODISCARD bool operator!=(const LinkedList<T>::Iterator& _Right) const noexcept;
		};

		size_t size_;

		Node* head_;
		Node* tail_;

	public:
		LinkedList();
		~LinkedList();

		const Iterator& begin();
		const Iterator& end();

		/// <summary>
		/// Returns the current size of LinkedList
		/// </summary>
		_NODISCARD const size_t Size();

		/// <summary>
		/// Check if LinkedList contains T value
		/// </summary>
		_NODISCARD bool Contains(const T& value);

		/// <summary>
		/// Adds a T object in the end of the LinkedList
		/// </summary>
		void Add(T value);

		/// <summary>
		/// Remove object by given T value
		/// </summary>
		void Remove(T value);
	};


	/* IMPLEMENTATION */


	// Iterator class
	template<typename T>
	LinkedList<T>::Iterator::Iterator(LinkedList<T>::Node* first)
	{
		currentNode_ = first;
	}


	template<typename T>
	_NODISCARD typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() noexcept
	{
		currentNode_ = currentNode_->next_;
		return *this;
	}


	template<typename T>
	_NODISCARD bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& _Right) const noexcept
	{
		return currentNode_ == _Right.currentNode_;
	}

	template<typename T>
	_NODISCARD bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& _Right) const noexcept
	{
		return !(*this == _Right);
	}

	template<typename T>
	_NODISCARD T& LinkedList<T>::Iterator::operator*() const noexcept
	{
		return currentNode_->data_;
	}


	// LinkedList class
	template<typename T>
	LinkedList<T>::LinkedList()
		: head_(nullptr), tail_(nullptr), size_(0)
	{
	}

	template<typename T>
	LinkedList<T>::~LinkedList()
	{
		Node* prev = head_;
		Node* next = head_;
		while (next)
		{
			prev = next;
			next = prev->next_;
			delete prev;
		}
	}

	template<typename T>
	typename const LinkedList<T>::Iterator& LinkedList<T>::begin()
	{
		return LinkedList<T>::Iterator(head_);
	}


	template<typename T>
	typename const LinkedList<T>::Iterator& LinkedList<T>::end()
	{
		return LinkedList<T>::Iterator(nullptr);
	}


	template<typename T>
	_NODISCARD const size_t LinkedList<T>::Size()
	{
		return size_;
	}


	template<typename T>
	_NODISCARD bool LinkedList<T>::Contains(const T& value)
	{
		Node* currentNode = head_;
		while (currentNode)
		{
			if (currentNode->data_ != NULL)
			{
				if (currentNode->data_ == value)
					return true;

				currentNode = currentNode->next_;
			}
		}
		return false;
	}


	template<typename T>
	void LinkedList<T>::Add(T value)
	{
		Node* nextNode = new Node(value);

		if (size_ == 0)
		{
			head_ = nextNode;
			tail_ = nextNode;
		}
		else
		{
			tail_->next_ = nextNode;
			tail_ = nextNode;
		}
		size_++;
	}


	template<typename T>
	void LinkedList<T>::Remove(T value)
	{
		Node* nodeToDelete = nullptr;

		Node* prevNode = head_;
		Node* currentNode = head_;
		while (currentNode != nullptr)
		{
			if (currentNode->data_ == value)
			{
				nodeToDelete = currentNode;
				break;
			}
			prevNode = currentNode;
			currentNode = currentNode->next_;
		}

		if (!nodeToDelete)
			return;

		if (nodeToDelete == head_)
		{
			Node* temp = head_->next_;
			delete head_;
			head_ = temp;
		}

		else if (nodeToDelete == tail_)
		{
			prevNode->next_ = nullptr;
			delete tail_;
			tail_ = prevNode;
		}

		else
		{
			Node* temp = nodeToDelete->next_;
			delete nodeToDelete;
			prevNode->next_ = temp;
		}

		size_--;
	}
}

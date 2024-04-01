#pragma once
#include <initializer_list> // for constructor khởi tạo luôn các biến infor
using namespace std;
template <class TValue>
class Node
{
public:
	TValue info;
	Node *next;

public:
	Node(TValue info) : info(info), next(nullptr) {}
};
template <class TValue>
class LinkedList
{
	typedef Node<TValue> *PNode;
	PNode head;

public:
	LinkedList() : head(nullptr) {}
	LinkedList(std::initializer_list<TValue> values) : head(nullptr)
	{
		for (const TValue &value : values)
		{
			pushBack(value);
		}
		// for syntax LinkedList<double> heso {1, 2, 3};
	}
	~LinkedList()
	{
		clear();
	}
	PNode getHead () const {return head;}
	bool isEmpty() const { return head == nullptr; }
	void clear()
	{
		while (head != nullptr)
		{
			PNode tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	int size() const
	{
		int count = 0;
		PNode current = head;
		while (current != 0)
		{
			current = current->next;
			count++;
		}
		return count;
	}
	void pushFront(TValue value)
	{
		PNode new_node = new Node(value);
		new_node->next = head;
		head = new_node;
	}
	void pushBack(TValue value)
	{
		PNode new_node = new Node(value);
		PNode current = head;
		if (isEmpty())
		{
			head = new_node;
			return;
		}

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	PNode getNodeAt(unsigned const int& index) const
	{
		PNode current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current;
	}
	void insertAfter(PNode current_node, TValue value)
	{
		if(isEmpty())	std::cout << "list is empty!" << endl;
		else if(current_node == nullptr) std::cout << "node not found!" << endl;
		else{
			PNode new_node = new Node<TValue>(value);
			if(current_node->next != nullptr)
				new_node->next = current_node->next;
			current_node->next = new_node;
		}
	}
	void insertBefore(PNode current_node, TValue value)
	{
		if(isEmpty())	std::cout << "list is empty!" << endl;
		else if(current_node == nullptr) std::cout << "node not found!" << endl;
		else{
			PNode new_node = new Node<TValue>(value);
			new_node->next = current_node;
			if (current_node != head)
			{
				PNode current = head;
				while (current->next != current_node)
					current = current->next;
				current->next = new_node;
			}else{
				head = new_node;
			}
		}
	}
	void remove(unsigned const int& index)
	{
		if(isEmpty())	std::cout << "list is empty!" << endl;
		else if(index < 0 || index >= size() )	cout << "index not found!" << endl;
		else{
			if (index == 0)
			{
				PNode temp = head;
				head = head->next;
				delete temp;
				
			}else{
				PNode current = head;
				for (int i = 0; i < index - 1; i++)
					current = current->next;
				PNode tmp = current;
				current->next = current->next->next;
				delete tmp;
			}
		}
	}
	friend std::ostream &operator<<(std::ostream &out, const LinkedList &H)
	{
		// Vì h là 1 hằng nên các phương thức trong đó cũng phải là hàm hằng
		// int size() const;
		// PNode getNodeAt(unsigned int index) const;
		if(H.isEmpty())	cout << "list is empty!";
		else{
			PNode current = H.head;
			while (current != nullptr)
			{
				out << current->info << '\t';
				current = current->next;
			}
		}
		return out;
	}
	TValue& operator[]  (int index)  
	{
		if(isEmpty())	cout << "list is empty!" << endl;
		else if(index < 0 || index >= size() )	cout << "index not found!" << endl;
		else{
			PNode current = head;
			for (int i = 0; i < index; i++)
				current = current->next;
			return current->info;
		}
		return TValue{};
	}
};
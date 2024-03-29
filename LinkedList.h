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
	PNode getNodeAt(unsigned int index) const
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
		if (isEmpty())
			return;
		PNode new_node = new Node(value);
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
	void insertBefore(PNode current_node, TValue value)
	{
		if (isEmpty())
			return;
		if (current_node == head)
		{
			pushFront(value);
			return;
		}
		PNode new_node = new Node(value);

		PNode current = head;
		while (current->next != current_node)
		{
			current = current->next;
		}

		new_node->next = current_node;
		current->next = new_node;
	}
	void deleteAt(int index)
	{
		if (index >= size() || index < 0)
		{
			return;
		}
		if (index == 0)
		{
			PNode temp = head;
			head = head->next;
			delete temp;
			return;
		}
		PNode current = head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		PNode tmp = current;
		current->next = current->next->next;
		delete tmp;
	}
	friend std::ostream &operator<<(std::ostream &out, const LinkedList &h)
	{
		// Vì h là 1 hằng nên các phương thức trong đó cũng phải là hàm hằng
		// int size() const;
		// PNode getNodeAt(unsigned int index) const;
		if (h.isEmpty()) // cương lĩnh chính trị của đảng
		{
			out << "nullptr\n";
			return out;
		}

		for (int i = 0; i < h.size(); i++)
		{
			out << h.getNodeAt(i)->info << '\n';
		}
		
	}
	TValue operator[]  (int index) const 
	{
		if (index >= size() || index < 0)
		{
			exit(1);
		}

		PNode current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->info;
	}
};
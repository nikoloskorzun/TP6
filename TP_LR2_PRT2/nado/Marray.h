#pragma once
using namespace std;
template<typename T>
class List
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext; //указатель на следующий элемент
		T data;//данные
		Node(T data = T(), Node* pNext = nullptr)

		{
			this->data = data;

			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;    //указатель на начало списка  

public:
	int size() { return Size; }
	~List();
	List();
	void push_back(const T data);
	void pop_front();
	T& operator[](const int index);
	bool operator > (List& r);
	bool operator <(List& r);


};
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;//âðåìåííàÿ ïåðåìåííàÿÿ, ïîêàçûâàþùàÿ êîíêðåòíûé ýëåìåíò
	int counter = 0;// ïåðåìåííàÿ ñ÷åò÷èê-ýëåìåíòîâ
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_back(const T data)
{
	head = new Node<T>(data, head);
	Size++;
}


template<typename T>
inline bool List<T>::operator>(List& r)
{
	if (this->GetSize() > r.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool List<T>::operator<(List& r)
{
	if (this->GetSize() < r.GetSize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

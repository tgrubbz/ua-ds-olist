
#include <iostream>
#include "olist.hpp"

using namespace std;

olist::olist() 
{
	// Set the root node
	root = new node { 0, nullptr };
	length = 0;
}

olist::~olist()
{

}

bool olist::insert(int num)
{
	// If the num exists in the list, it can't be inserted
	if(search(num))
	{
		return false;
	}

	// Set the prev ptr to the root
	// Set the current ptr to the 1st node in the list
	node *prev = root;
	node *current = root->next;

	// Move current to the node where current->num > num
	while(current != nullptr && current->num < num)
	{
		// Set the prev ptr to the current ptr
		// Set the current ptr to the next ptr
		prev = current;
		current = current->next;
	}

	// 
	current = new node { num, current };
	prev->next = current;
	length++;

	return true;
}

bool olist::remove(int num)
{
	return true;
}

bool olist::search(int num)
{
	// If the list is empty, the num can't be in the list
	if(is_empty()) 
	{
		return false;
	}

	// Set the current ptr to the 1st node in the list
	node *current = root->next;

	// While the current ptr is not the null ptr
	while(current != nullptr)
	{
		// If the current node num is equal to the search num
		if(current->num == num)
		{
			return true;
		}

		// Set the current ptr to the next ptr
		current = current->next;
	}

	return false;
}

bool olist::is_empty()
{
	return root->next == nullptr;
}

void olist::clear()
{

}

int olist::count()
{
	return length;
}

void olist::display()
{
	if(is_empty())
	{
		cout << "The list is empty" << endl;
	}

	node *current = root->next;

	while(current != nullptr)
	{
		cout << "[" << current->num << "]";
		current = current->next;
	}
}

void main() 
{
	olist list = olist();
	list.insert(1);
	list.insert(3);
	list.insert(2);
	list.insert(-1);
	list.display();
};
// $NAME <tsg8@uakron.edu>
//
// Ordered_list.hpp: Implementation of the Ordered_list class

#include <iostream>
#include "ordered_list.hpp"

using namespace std;

Ordered_list::Ordered_list() 
{
	// Set the root node
	root = new node { 0, nullptr };
	length = 0;
}

Ordered_list::~Ordered_list()
{
	// Call the clear function
	clear();
	delete root;
}

bool Ordered_list::insert(int num)
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

	// Set current to a new node with the inserted number that points to current
	// Set the prev->next ptr to the new current node
	current = new node { num, current };	
	prev->next = current;

	// Increment the length
	++length;

	return true;
}

bool Ordered_list::remove(int num)
{
	// If the num isn't in the list, return false
	if(!search(num))
	{
		return false;
	}

	// Set the prev ptr to the root
	// Set the current ptr to the 1st node in the list
	node *prev = root;
	node *current = root->next;

	// Move the current ptr to where current->num == num
	while(current != nullptr && current-> num != num)
	{
		prev = current;
		current = current->next;
	}

	// Set the prev-next ptr to the current->next ptr
	// Delete curent
	prev->next = current->next;
	delete current;

	// Decrement the length
	--length;

	return true;
}

bool Ordered_list::search(int num)
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

bool Ordered_list::is_empty()
{
	// Check to see if the root->next ptr is null
	return root->next == nullptr;
}

void Ordered_list::clear()
{
	// If the list is empty, the job is done
	if(is_empty())
	{
		return;
	}

	// Store the root->next
	node *temp = root->next;

	// While the temp ptr is not null
	while(temp != nullptr)
	{
		// Point the root to the next node
		root->next = temp->next;

		// Delete temp
		delete temp;

		// Set temp to the noot->next
		temp = root->next;
	}
	
	length = 0;
}

int Ordered_list::count()
{
	return length;
}

void Ordered_list::display()
{
	if(is_empty())
	{
		cout << "The list is empty";
	}

	node *current = root->next;

	while(current != nullptr)
	{
		cout << "[" << current->num << "]";
		current = current->next;
	}

	cout << endl;
}

// $Name <tsg8@zips.uakron.edu>
//
// Order_list.hpp: Definition of Order_list class

#ifndef ORDERED_LIST_HPP
#define ORDERED_LIST_HPP

struct node
{
	// The number associated with this node
	int num;

	// A pointer to the next node
	node *next;	
};

// Singly Linked Order list
struct Ordered_list
{
	node *root;
	int length;

	// Default Constructor
	Ordered_list();
	~Ordered_list ();

	// Inserts specified num into the list, in order
	// Does not insert dupes
	// Returns true if successful
	bool insert(int num);

	// Removes specified num from list
	// Returns true if successful
	bool remove(int num);

	// Searches the list for the specified num
	// Returns true if found
	bool search(int num);

	// Returns true if the list is empty
	bool is_empty();

	// Removes all of the elements (nodes) from the list
	void clear();

	// Returns the number of elements (nodes) in the list
	int count();

	// Displays the contents of the list to the console in brackets []
	void display();
};

#endif

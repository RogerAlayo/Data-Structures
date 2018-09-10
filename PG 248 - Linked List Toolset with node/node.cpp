#include "node.h"
#include <cassert>

size_t list_length(const node* head_ptr)
{
	size_t answer = 0;
	const node* cursor;		//if wasnt const then cursor = head_ptr wont work

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) //link returns node pointer
		++answer;
	return answer;
}
void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
	head_ptr = new node(entry, head_ptr);	//node returns node pointer
}
void list_insert(node* previous_ptr, const node::value_type& entry)
{
	node* insert_ptr = new node(entry, previous_ptr->link());
	previous_ptr->set_link(insert_ptr);
}
node* list_search(node* head_ptr, const node::value_type& target)
{
	node* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		if (cursor->data() == target)
		{
			return cursor;
		}
	}
	return NULL;
}
const node* list_search(const node* head_ptr, const node::value_type& target)
{
	const node* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		if (cursor->data() == target)
		{
			return cursor;
		}
	}
	return NULL;
}
node* list_locate(node* head_ptr, std::size_t position)
{
	assert(0 < position);
	node* cursor = head_ptr;

	for (size_t i = 1; (i < position) && (cursor != NULL); ++i)
	{
		cursor = cursor->link(); 
	}
	return cursor;
}
const node* list_locate(const node* head_ptr, std::size_t position)
{
	assert(0 < position);
	const node* cursor = head_ptr;

	for (size_t i = 1; (i < position) && (cursor != NULL); ++i)
	{
		cursor = cursor->link();
	}
	return cursor;
}
void list_head_remove(node*& head_ptr)
{
	if (head_ptr == NULL)
		return;
	
}
void list_remove(node* previous_ptr)
{
	if (previous_ptr == NULL)
		return;

}
void list_clear(node*& head_ptr) 
{
	if (head_ptr == NULL)
		return;


}
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
{
	head_ptr, tail_ptr = NULL;	//new head_ptr but won't interefere with original head_ptr since original head_ptr is called source_ptr in this implementation
	if (source_ptr == NULL)	//source_ptr is the original pointers head_ptr
		return;

	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;

	source_ptr = source_ptr->link();	//makes source_ptr point to second node

	while (source_ptr != NULL)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->link();
		source_ptr = source_ptr->link();
	}
}
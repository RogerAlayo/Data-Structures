#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template<typename Item>
class node
{
public:
	typedef Item valute_type;
	//Constructor
	node(const Item& init_data = Item(), const node* init_link = NULL) //why const reference param if init_data and init_limk changes
		{ data_field = init_data; link_field = init_link }		//did we need param init_data and init_link?? couldn't we just initialize the data fields directly
	//Mutator fns
	void set_data(const Item*& new_data) { data_field = new_data; }		//why const &
	void set_link(node* new_link) { link_field = new_link; }
	//Accessor fns
	Item data() const { return data_field; }

	node* link() { return link_field; }
	const node* link() const { return link_field; }


private:
	Item data_field;
	node* link_field;
};
#endif

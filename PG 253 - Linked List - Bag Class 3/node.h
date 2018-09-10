#include <cstdlib>
class node
{
public:
	typedef double value_type;
	node(const value_type& init_data = value_type(), const node* init_link = NULL) {
		data_field = init_data; link_field = init_link;}
	~node();

private:
	value_type data_field;
	node* link_field;
};


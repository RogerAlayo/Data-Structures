#include <iostream>
#include <stack>

template<typename Item>
bool is_balanced(const Item& a)
{
	const char LP = '(';
	const char RP = ')';

	std::stack<char> store;
	char next;
	bool failed = false;

	std::string::size_type i;	//size_type is a new data type	
	for(i = 0; !failed && (i < a.length()); ++i)
	{
		//next = a.at(i);	use only for strings
		next = a[i];
		if (next == LP)
		{
			store.push(next);
		}
		else if ((next == RP) && (!store.empty()))
		{
			store.pop();
		}
		else if ((next == RP) && (store.empty()))
			failed = true;
	}
		
	return (store.empty()) && (!failed);
}

int main()
{
	std::string expression("Mr.Jerry (highman) says (okay)");
	
	if (is_balanced(expression) == true)
	{
		std::cout << "balanced";
	}
	else
		std::cout << "not balanced";
	
	//int line(5 + 3 * (2 * 1) + (5 * 3));
	//is_balanced(line);

	return 0;
}
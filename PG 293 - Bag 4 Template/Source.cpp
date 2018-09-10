// FILE: bag4demo.cxx
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <string>
#include "bag4.h"       // Provides the bag<Item> template class

using namespace std;
using namespace main_savitch_6A;

const int ITEMS_PER_BAG = 4;
const int MANY_SENTENCES = 3;

template< typename Item, typename SizeType, typename MessageType>
void get_items(bag<Item>& collection, SizeType n, MessageType description)
{
	Item user_input;
	SizeType i;

	cout << "Please type " << n << " " << description;
	cout << ", separated by spaces. \n";
	cout << "Press the <return> key after the final entry:\n";

	for (i = 1; i <= n; ++i)
	{
		cin >> user_input;
		collection.insert(user_input);
	}

	cout << endl;
}

int main()
{
	bag<string> adjectives;
	bag<int> ages;
	bag<string> names;

	int line_number;

	cout << "Help me write a story.\n";
	get_items(adjectives, ITEMS_PER_BAG, "adjectives that describe a mood");
	get_items(ages,		  ITEMS_PER_BAG, "integers in the teens");
	get_items(names,	  ITEMS_PER_BAG, "first names");

	cout << "Thank you for your kind assistance.\n\n";

	cout << "LIFE\n";
	cout << "by A. Computer\n";

	for (line_number = 1; line_number <= MANY_SENTENCES; ++line_number)
	{
		cout << names.grab() << " was only "
			<< ages.grab() << " years old, but he/she was "
			<< adjectives.grab() << " .\n";
	}

	cout << "Life is " << adjectives.grab() << ".\n";
	cout << "The (" << adjectives.grab() << ") end\n";

	return EXIT_SUCCESS;
}
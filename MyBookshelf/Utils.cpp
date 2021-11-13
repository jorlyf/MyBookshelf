#include "Utils.h"

Indents Utils::get_print_indents(vector<Book*> &books)
{
	Indents indents;

	for (int i = 0; i < books.size(); i++)
	{
		indents.name = max(indents.name, books.at(i)->get_name().length());
		indents.author = max(indents.author, books.at(i)->get_author().length());
		indents.genre = max(indents.genre, books.at(i)->get_genre().length());
	}

	indents.name += 5;
	indents.author += 5;
	indents.genre += 5;

	return indents;
}
Indents Utils::get_print_indents(Book &book)
{
	Indents indents;

	indents.name = max(indents.name, book.get_name().length());
	indents.author = max(indents.author, book.get_author().length());
	indents.genre = max(indents.genre, book.get_genre().length());

	indents.name += 5;
	indents.author += 5;
	indents.genre += 5;

	return indents;
}
string Utils::get_string(unsigned int max_length)
{
	string value;
	getline(cin, value);
	clear_cin();

	while (value.length() > max_length)
	{
		cout << "Вводите не более " << max_length << " символов!" << endl;
		getline(cin, value);
		clear_cin();
	}
	return value;
}
int Utils::get_int(unsigned int beginvalue, unsigned int endvalue)
{
	int value;
	istringstream st;
	string input;
	 
	while (true)
	{
		getline(cin, input);
		clear_cin();
		st.str(input);

		if (input == "")
			return 0;

		if (st >> value)
		{
			if (value > beginvalue && value < endvalue)
				return value;
			else
				cout << "Введите число не меньше " << beginvalue << ", но не больше " << endvalue << endl;
		}

		else
			cout << "Некорректный ввод!" << endl;
	}
}
int Utils::get_int()
{
	int value;
	istringstream st;
	string input;

	while (true)
	{
		getline(cin, input);
		clear_cin();
		st.str(input);

		if (input == "")
			return 0;

		if (st >> value)
			return value;

		else
			cout << "Некорректный ввод числа!" << endl;
	}
}
string Utils::get_lower_case_string(string value)
{
	string newvalue;
	for (int i = 0; i < value.size(); i++)
		newvalue.push_back(tolower(value[i]));

	return newvalue;
}
void Utils::clear_cin()
{
	cin.clear(); //
	_flushall(); // очистка буфера ввода
}


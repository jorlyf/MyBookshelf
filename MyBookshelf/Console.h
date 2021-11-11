#pragma once
#include "Bookshelf.h"
#include "Book.h"
#include "Indents.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Console
{
private:
	Bookshelf bookshelf;
	char key;

	void print_menu();
	void print_hello();
	void print_books(vector<Book*> &books);
	void print_book(Book &book, Indents &indents, bool print_note);
	void print_only_one_book(Book &book, Indents &indents);
	void print_header(Indents &indents);

	bool is_have_books(vector<Book*> &books);

public:
	void run();
};

#pragma once
#include "Book.h"
#include <vector>

using namespace std;

class Bookshelf
{
private:
	vector<Book*> books;
	unsigned int last_book_id;

	void load_from_file();

public:
	vector<Book*> &get_books();
	Book &get_book_at(unsigned int index);
	Book &get_book_by_id(unsigned int value);
	Book &get_book_by_name(string value);
	Book &get_book_by_author(string value);
	Book &get_book_by_genre(string value);
	Book &get_book_by_rating(uint8_t value);
	Book &get_book_by_rating_diaposon(uint8_t startvalue, uint8_t endvalue);

	void sort_books_by_id();
	void sort_books_by_name();
	void sort_books_by_author();
	void sort_books_by_genre();
	void sort_books_by_rating();
	void sort_books_by_created_date();

	Book create_book(string name);
	bool add_book(Book& book);
	bool delete_book(Book& book);
	bool delete_book(unsigned int id);
};

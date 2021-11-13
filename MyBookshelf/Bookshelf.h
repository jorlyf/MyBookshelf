#pragma once
#include "Book.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "Settings.h"

using namespace std;

class Bookshelf // основная модель данных
{
private:
	vector<Book*> books;   // вектор с объектами книг
	ofstream ofs;          // запись в файл
	ifstream ifs;          // чтение из файла
	unsigned int last_book_id;

	void read_books_file(string path);
	void write_books_file(string path, ofstream::openmode mode);

public:
	Bookshelf();

	vector<Book*>& get_books();
	Book& get_book_at(unsigned int index);
	Book& get_book_by_id(unsigned int value);
	Book& get_book_by_name(string value);
	Book& get_book_by_author(string value);
	Book& get_book_by_genre(string value);
	Book& get_book_by_rating(short value);
	Book& get_book_by_rating_diaposon(short beginvalue, short endvalue);

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

	void save(); // сохранение данных
};

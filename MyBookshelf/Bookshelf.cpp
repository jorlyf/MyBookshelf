#include "Bookshelf.h"

vector<Book*> &Bookshelf::get_books()
{
	return this->books;
}
Book& Bookshelf::get_book_at(unsigned int index)
{
	Book* book = this->books.at(index);
	if (book == nullptr) return *(Book*)NULL; // позволяет вернуть nullptr по ссылке

	return *book;
}


Book Bookshelf::create_book(string name)
{
	Book book = Book(last_book_id++, name);
	return book;
}
bool Bookshelf::add_book(Book &book)
{
	this->books.push_back(&book);
	return true;
}
bool Bookshelf::delete_book(Book &book)
{
	return delete_book(book.get_id());
}
bool Bookshelf::delete_book(unsigned int id)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		if (this->books.at(i)->get_id() == id)
		{
			this->books.erase(this->books.begin() + i);
			return true;
		}
	}
	return false;
}

void Bookshelf::load_from_file()
{
	last_book_id = 1;
}


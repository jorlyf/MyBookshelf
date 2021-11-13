#include "Bookshelf.h"

Bookshelf::Bookshelf()
{
	this->last_book_id = 0;
	read_books_file(Settings.BOOKS_FILENAME);
}

vector<Book*>& Bookshelf::get_books()
{
	return this->books;
}
Book& Bookshelf::get_book_at(unsigned int index)
{
	Book* book = this->books.at(index);
	if (book == nullptr) return *(Book*)NULL; // позволяет вернуть nullptr по ссылке

	return *book;
}
Book& Bookshelf::get_book_by_id(unsigned int id)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		Book* book = this->books.at(i);
		if (book == nullptr) continue;
		if (book->get_id() == id)
			return *book;
	}
	return *(Book*)NULL; // позволяет вернуть nullptr по ссылке 
}
Book& Bookshelf::get_book_by_name(string value)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		Book* book = this->books.at(i);
		if (book == nullptr) continue;
		if (book->get_name() == value)
			return *book;
	}
	return *(Book*)NULL; // позволяет вернуть nullptr по ссылке 
}
Book& Bookshelf::get_book_by_author(string value)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		Book* book = this->books.at(i);
		if (book == nullptr) continue;
		if (book->get_author() == value)
			return *book;
	}
	return *(Book*)NULL; // позволяет вернуть nullptr по ссылке 
}
Book& Bookshelf::get_book_by_genre(string value)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		Book* book = this->books.at(i);
		if (book == nullptr) continue;
		if (book->get_genre() == value)
			return *book;
	}
	return *(Book*)NULL; // позволяет вернуть nullptr по ссылке 
}
Book& Bookshelf::get_book_by_rating(short value)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		Book* book = this->books.at(i);
		if (book == nullptr) continue;
		if (book->get_rating() == value)
			return *book;
	}
	return *(Book*)NULL; // позволяет вернуть nullptr по ссылке 
}
Book& Bookshelf::get_book_by_rating_diaposon(short beginvalue, short endvalue)
{
	for (int i = 0; i < this->books.size(); i++)
	{
		Book* book = this->books.at(i);
		if (book == nullptr) continue;
		if (book->get_rating() > beginvalue && book->get_rating() < endvalue)
			return *book;
	}
	return *(Book*)NULL; // позволяет вернуть nullptr по ссылке 
}


Book Bookshelf::create_book(string name)
{
	Book book = Book(++last_book_id, name);
	return book;
}
bool Bookshelf::add_book(Book& book)
{
	this->books.push_back(new Book(book));
	save();
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

void Bookshelf::save()
{
	write_books_file(Settings.BOOKS_FILENAME, ofstream::binary);
}

void Bookshelf::read_books_file(string path)
{
	ifs.open(path);
	if (!ifs.is_open()) { cout << "Не удалось открыть файл для чтения!" << endl; return; }

	Book book;
	while (ifs.read((char*)&book, sizeof(Book)))
	{
		this->books.push_back(new Book(book));
		this->last_book_id = max(this->last_book_id, book.get_id());
	}

	ifs.close();
}
void Bookshelf::write_books_file(string path, ofstream::openmode mode)
{
	ofs.open(path, mode);
	if (!ofs.is_open()) { cout << "Не удалось открыть файл для записи!" << endl; return; }

	for (int i = 0; i < this->books.size(); i++)
		ofs.write((char*)this->books.at(i), sizeof(Book));


	ofs.close();
}


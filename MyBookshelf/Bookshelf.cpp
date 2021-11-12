#include "Bookshelf.h"

Bookshelf::Bookshelf()
{
	read_file(this->books, Settings.BOOKS_FILENAME, ifstream::in);
}

vector<Book*> &Bookshelf::get_books()
{
	return this->books;
}
Book &Bookshelf::get_book_at(unsigned int index)
{
	Book* book = this->books.at(index);
	if (book == nullptr) return *(Book*)NULL; // позволяет вернуть nullptr по ссылке

	return *book;
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
	write_file(this->books, Settings.BOOKS_FILENAME, ofstream::trunc);
}

template <typename T>
void Bookshelf::read_file(vector<T>& vector, string path, ifstream::openmode mode)
{
	ifs.open(path, mode);
	if (!ifs.is_open()) { cout << "Не удалось открыть файл для чтения!" << endl; return; }

	T pnt;
	while (ifs.read((char*)&pnt, sizeof(T)))
		vector.push_back(pnt);

	ifs.close();
}

template <typename T>
void Bookshelf::write_file(vector<T>& vector, string path, ofstream::openmode mode)
{
	ofs.open(path, mode);
	if (!ofs.is_open()) { cout << "Не удалось открыть файл для записи!" << endl; return; }

	for (int i = 0; i < vector.size(); i++)
		ofs.write((char*)vector.at(i), sizeof(T));

	ofs.close();
}

template <typename T>
void Bookshelf::write_file(T& object, string path, ofstream::openmode mode)
{
	ofs.open(path, mode);
	if (!ofs.is_open()) { cout << "Не удалось открыть файл для записи!" << endl; return; }

	ofs.write((char*)object, sizeof(T));

	ofs.close();
}


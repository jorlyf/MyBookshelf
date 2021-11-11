#include "Book.h"

Book::Book(unsigned int id, string name)
{
	this->id = id;
	set_name(name);
	set_created_date();
}
void Book::set_created_date()
{
	const time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);
	created_date = string(buf);
}

unsigned int Book::get_id() { return this->id; }
string Book::get_name() { return this->name; }
string Book::get_author() { return this->author; }
string Book::get_note() { return this->note; }
string Book::get_genre() { return this->genre; }
string Book::get_created_date() { return this->created_date; }
short Book::get_rating() { return this->rating; }

bool Book::set_name(string value)
{
	if (value.length() < 0) return false;
	if (value.length() > 40) return false;

	this->name = value; return true;
}
bool Book::set_author(string value)
{
	if (value.length() < 0) return false;
	if (value.length() > 40) return false;

	this->author = value; return true;
}
bool Book::set_note(string value)
{
	if (value.length() < 0) return false;
	if (value.length() > 1024) return false;

	this->note = value; return true;
}
bool Book::set_genre(string value)
{
	if (value.length() < 0) return false;
	if (value.length() > 25) return false;

	this->genre = value; return true;
}
bool Book::set_rating(short value)
{
	if (value < 1 || value > 10) return false;

	this->rating = value; return true;
}

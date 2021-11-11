#pragma once
#include <string>
#include <time.h>

using namespace std;

class Book
{
private:
	unsigned int id;
	string name;
	string author;
	string note;
	string genre;
	string created_date;
	short rating; // 1 - 10

	void set_created_date();

public:
	Book(unsigned int id, string name);
	void load();

	unsigned int get_id();
	string get_name();
	string get_author();
	string get_note();
	string get_genre();
	string get_created_date();
	short get_rating();

	bool set_name(string value);
	bool set_author(string value);
	bool set_note(string value);
	bool set_genre(string value);
	bool set_rating(short value);
};

#pragma once
#include<iostream>

/* String Class */
 
class StringClass
{
	char* stringPtr = nullptr;
	size_t stringSize;

	/* Private Functiions */
	size_t getLength(const char*);  /* Get the Length of the String */
	void copyString(const char*, char*, size_t);  /* Copy Data from from one String into Another */
	char* pointerToLocation(char*, size_t) const; /* Return pointer to a position */

public:

	/* Constructors */
	StringClass(); /* Default Constructor */
	StringClass(const StringClass&); /* Copy Constructor */
	StringClass(const char*); /* Parameterized Constructor */
	StringClass(StringClass&&) noexcept; /* Move Constructor  */

	/* Destructor */
	~StringClass();

	/* Operator */
	StringClass& operator = (const StringClass&); /* Assignment Operator */
	StringClass& operator = (const StringClass&&) noexcept; /* Move Assignment Operator */
	bool operator == (const StringClass&) const; /* Equal Operator */
	char& operator [] (size_t); /* Bracket Operator */
	friend std::ostream& operator << (std::ostream&, const StringClass&); /* Insertion  Operator */

	/* Functions */
	size_t length(); /* Get the Length of the String */
	void push_back(char); /* Adds a Char at the end of the String */
	void insert(size_t, const StringClass&); /* Adds a String at a Given Position */
	void erase(size_t, size_t); /* Erase Characters from the string at a given position and length */
	StringClass& substr(size_t, size_t); /* Get Substring from the string at a given position and length */
	int compare(const StringClass&) const; /*  Compare string with the input string */
	StringClass& append(const StringClass&); /* Append string at the end with a Substring */
	void pop_back(); /* Remove a char at the end of the string */
	void swap(StringClass&); /* Swaps the Data of the Given String */
	void clear(); /* Clears the String */
};
 



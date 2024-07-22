#include <iostream>
#include "stringclass.h" 

/************************   CONSTRUCTORS    *************************/

/* Default Constructor */
StringClass::StringClass(): stringSize(0), stringPtr(nullptr)
{
	
}

/* Parameterized Constructor */
StringClass::StringClass(const char* str)
{
	try
	{
		if (*str != '\0')
		{
			/* Variable initialization */
			char* tempStr = nullptr;

			/** Implementation **/			
			stringSize = getLength(str); /* Get the size of the String */

			stringPtr = new char[stringSize + 1];  /* Create Dynamic Memory...1 more than the size for  null character*/

			copyString(str, stringPtr, stringSize); /* Copy Data */			
		}
		else
		{
			stringSize = 0;
			stringPtr = nullptr;
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;		
		throw;
	}	 
}


/* Copy Constructor */
StringClass::StringClass(const StringClass& strObj) 
{
	try
	{
		if (this != &strObj) /* Check if Objects are not same */
		{			
			/* Variable initialization */
			stringSize = strObj.stringSize;

			/** Implementation  **/			
			stringPtr = new char[stringSize + 1];  /* Create Dynamic Memory...1 more than the size for  null character */

			copyString(strObj.stringPtr, stringPtr, stringSize); /* Copy Data */			
		}
		else
		{
			stringSize = strObj.stringSize;
			stringPtr = strObj.stringPtr;
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;		
		throw;
	}
}

/* Move Constructor  */
StringClass::StringClass(StringClass&& strObj) noexcept
{	 
	std::cout << "Move Constructor" << std::endl;	 

	/* Variable initialization */
	stringSize = strObj.stringSize;

	/** Implementation  **/		
	stringPtr = new char[stringSize + 1];  /* 1 more than the size for  null character ...Create Dynamic Memory */

	copyString(strObj.stringPtr, stringPtr, stringSize); /* Copy Data */		
}


/* Destructor */
StringClass::~StringClass()
{
	if (stringPtr != nullptr)
	{
		delete stringPtr;
	}
}


/************************   OPERATOR IMPLEMENTATION    *************************/

/* Assignment Operator */
StringClass& StringClass::operator = (const StringClass& strObj)
{	
	try
	{
		if(this != &strObj)
		{			
			stringSize = strObj.stringSize;

			/* Deleting previous Dynamic memory */
			delete stringPtr;

			/* Create Dynamic Memory */
			stringPtr = new char[strObj.stringSize + 1];  /* 1 more than the size for  null character */

			copyString(strObj.stringPtr, stringPtr, stringSize); /* Copy Data */

			return *this;			
		}
		else
		{
			return *this;
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;			
	}	
}

/* Move Assignment Operator */
StringClass& StringClass::operator = (const StringClass&& strObj) noexcept
{	
	if (this != &strObj) /* Check if Objects are same */
	{
		if (strObj.stringPtr != nullptr && strObj.stringSize != 0) /* If Object has no valid data */
		{
			stringSize = strObj.stringSize;

			/* Deleting previous Dynamic memory */
			delete stringPtr;

			/* Create Dynamic Memory */
			stringPtr = new char[strObj.stringSize + 1];  /* 1 more than the size for  null character*/

			copyString(strObj.stringPtr, stringPtr, stringSize); /* Copy Data */
			return *this;
		}
		else
		{
			return  *this;
		}
	}
	else
	{
		return *this;
	}	
}

/* Equal Operator */
bool StringClass::operator == (const StringClass& strObj) const 
{	
	try
	{
		if (this != &strObj) /* Check if Objects are same */
		{
			/* Variable initialization */
			bool isMatching = true;
			char* currPtr = stringPtr;
			char* objPtr = strObj.stringPtr;

			/** Implementation  **/
			while (*currPtr && (*currPtr == *objPtr))
			{
				currPtr++;
				objPtr++;
			}

			if (*currPtr != *objPtr)
			{
				isMatching = false;
			}
			return isMatching;			 
		}
		else
		{
			return true; /* If Objects are same then return true */
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/* Bracket Operator */
char& StringClass::operator [] (size_t pos)  
{	
	try
	{
		if (stringSize != 0 && stringPtr != nullptr) /* If Object has no valid data */
		{
			if (stringSize > pos) /* Check If the Referenced Position is bigger than the size of the string */
			{
				/* Variable initialization */
				char* currPtr = stringPtr;
				size_t currPos = 0;

				/** Implementation  **/
				while (currPos != pos)
				{
					currPtr++;
					currPos++;
				}
				return *currPtr;
			}
			else
			{
				throw std::out_of_range("Referenced Position is Bigger than the size of the String");
			}		
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Insertion  Operator */
std::ostream& operator << (std::ostream& outStream, const StringClass& strObj)
{	
	try
	{
		if (strObj.stringPtr != nullptr && strObj.stringSize != 0) /* Check if Object is valid */
		{			
			/* Variable initialization */
			char* currPtr = strObj.stringPtr;
			size_t currSize = strObj.stringSize;

			/** Implementation  **/
			while (currSize > 0)
			{
				outStream << *currPtr;
				currPtr++;
				currSize--;
			}	
			return outStream;
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}			 
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/************************   FUNCTION IMPLEMENTATION    *************************/

/****** PRIVATE  FUNCTION IMPLEMENTATION    ******/

void StringClass::copyString( const char* sourceStr, char* destinationStr, size_t size)
{
	try
	{
		if (size > 0)
		{
			while (size > 0)
			{
				*destinationStr++ = *sourceStr++;
				--size;
			}
		}	
		*destinationStr = '\0';
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Calculate Length of the String */
size_t StringClass::getLength(const char* str)
{
	try
	{
		if (*str != '\0')
		{		
			size_t length = 0;
			while (*str)
			{
				++str;
				++length;
			}
			return length;
		}
		else
		{
			throw std::exception("Not a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/* Return pointer to a position */
char* StringClass::pointerToLocation(char* str, size_t pos) const
{
	try
	{
		if (*str != '\0')
		{			
			while (pos > 0)
			{
				pos--;
				str++;
			}
			return --str;
		}
		else
		{
			throw std::exception("Not a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/****** PUBLIC  FUNCTION IMPLEMENTATION    ******/

/* Calculate Length of the String */
size_t StringClass::length()
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0)
		{
			return getLength(stringPtr);

		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}		
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/* Insert a char to the string */
void StringClass::push_back(const char charVar )
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0)
		{
			/* Variable initialization */
			char* currPtr = stringPtr;
			char* newPtr = nullptr;
			char* newStartPtr = nullptr;
			size_t currSize = stringSize;

			/* Implementation  */
			newPtr = new char[stringSize+2]; /* to accomodate new char variable and null */		

			copyString(currPtr, newPtr, currSize); /* copy data into the memory */

			newStartPtr = pointerToLocation(newPtr, currSize); /* Get the pointer to the last element */

			*(++newStartPtr) = charVar; /* Update string with the received char value */

			*(++newStartPtr) = '\0'; /* set the last to null */

			delete stringPtr; /* Delete old memory */

			stringPtr = newPtr; /* Refer pointer to the new memory */

			stringSize = stringSize + 1;
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Insert a new string into the string at a given position */
void StringClass::insert(size_t pos, const StringClass& strObj)
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			if (strObj.stringPtr != nullptr && strObj.stringSize != 0)  /* Check if Input string is valid */
			{
				/* Variable initialization */
				char* currPtr = stringPtr;
				char* newPtr = nullptr;
				char* newStartPtr = nullptr;
				size_t currSize = stringSize;
				size_t strSize = 0;
				size_t newSize = 0;

				/* Implementation  */
				strSize = strObj.stringSize; 

				newSize = stringSize + strSize; /* Initialize the length for the new string */

				newPtr = new char[newSize + 1]; /* Initialize the new Memory for the new string */

				copyString(stringPtr, newPtr, pos - 1); /* Copy data before the insertion point into the new memory */

				currPtr = pointerToLocation(newPtr, pos); /* Get the location of the insertion point */

				copyString(strObj.stringPtr, currPtr, strObj.stringSize); /* Copy the received string into the new string */

				currPtr = currPtr + strObj.stringSize; /* Get the location of the end of the string */

				newStartPtr = stringPtr + (pos); /* Get the position of the remaining string  */

				copyString(newStartPtr, currPtr, (stringSize - pos)); /* Copy remainig data into the new string */

				delete stringPtr; /* Free old memory */

				stringPtr = newPtr; /* Reassign pointer */

				stringSize = stringSize + strObj.stringSize; /* Reassign size */
			}
			else
			{
				throw std::exception("Input String is not a Valid String");
			}
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/* Erase Characters from the string at a given position and length */
void StringClass::erase(size_t pos, size_t len)
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			if (len != 0)  /* Check if length is not zero */
			{
				/* Variable initialization */
				char* currPtr = nullptr;
				char* newPtr = nullptr;
				char* newStartPtr = nullptr;
				size_t newSize = 0;

				/* Implementation  */				 

				newSize = stringSize - len; /* Initialize the length for the new string */

				newPtr = new char[newSize + 1]; /* Initialize the new Memory for the new string */

				copyString(stringPtr, newPtr, pos - 1); /* Copy data before the deletion point into the new memory */

				currPtr = pointerToLocation(newPtr, pos); /* Get the location of the insertion point */				

				newStartPtr = stringPtr + pos + len; /* Get the position of the remaining string  */

				newSize = stringSize - (pos + len); /* length of the remaining string */

				copyString(newStartPtr, currPtr, newSize); /* Copy remainig data into the new string */

				delete stringPtr; /* Free old memory */

				stringPtr = newPtr; /* Reassign pointer */

				stringSize = stringSize - len; /* Reassign size */
			}
			else
			{
				throw std::exception("Value of the length to erase is zero");
			}
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Get Substring from the string at a given position and length */
StringClass& StringClass::substr(size_t pos, size_t len)
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			if (len != 0)  /* Check if length is not zero */
			{
				/* Variable initialization */
				char* currPtr = nullptr;

				/* Implementation  */
				StringClass* StringClassObj = new StringClass(); /* Create new class */				

				StringClassObj->stringPtr = new char[len + 1]; /* Initialize the new Memory for the new string */

				StringClassObj->stringSize = len;

				currPtr = pointerToLocation(stringPtr, pos); /* Get the starting location of the substring */

				copyString(currPtr, StringClassObj->stringPtr, len); /* Copy data of the substring */

				return *StringClassObj;				
			}
			else
			{
				throw std::exception("Value of the length of the substring is zero");
			}
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Compare string with the input string 

return value:
	0: strings are equal/same
	<0: Input string is bigger than the string or character of string is bigger than the character of the Input string
	>0: Input string is lower than the string or character of string is lower than the character of the Input string
*/
int StringClass::compare(const StringClass& strObj) const
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			if (strObj.stringPtr != nullptr && strObj.stringSize != 0) /* Check if Input String is valid */   
			{
				/* Variable initialization */
				char* currPtr = stringPtr;
				char* objPtr = strObj.stringPtr;				 

				/* Implementation  */

				if (stringSize != strObj.stringSize) /* If Size of bith strings are not same */
				{
					return (int)(stringSize - strObj.stringSize);
				}
				else
				{					
					while (*currPtr && (*currPtr == *objPtr))
					{
						currPtr++;
						objPtr++;
					}

					if (*currPtr == *objPtr)
					{
						return 0;
					}
					else
					{
						return (*currPtr - *objPtr);
					}
				}
			}
			else
			{
				throw std::exception("Input String is Invalid");
			}
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Append string at the end with a Substring */
StringClass& StringClass::append(const StringClass& strObj)
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			if (strObj.stringPtr != nullptr && strObj.stringSize != 0) /* Check if Input String is valid */
			{
				/* Variable initialization */
				char* currPtr = stringPtr;
				char* newPtr = nullptr;
				char* newStartPtr = nullptr;

				/* Implementation  */
				newPtr = new char[stringSize + strObj.stringSize + 1];				

				copyString(currPtr, newPtr, stringSize); /* Copy data of the string into new string */

				newStartPtr = pointerToLocation(newPtr, stringSize); /* Get the location of the insertion point */		

				copyString(strObj.stringPtr, newStartPtr, strObj.stringSize); /* Copy data of the string into new string */

				delete stringPtr;  /* Free old memory */

				stringPtr = newPtr; /* Reassign pointer */

				stringSize = stringSize + strObj.stringSize; /* Reassign size */		

				return *this;
			}
			else
			{
				throw std::exception("Input Class Object is not initialized with a Valid String");
			}
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/* Remove a char at the end of the string */
void StringClass::pop_back()
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{			
			/* Variable initialization */
			char* currPtr = stringPtr;
			char* newPtr = nullptr;		

			/* Implementation  */
			stringSize = stringSize - 1; /* Reassign size */

			newPtr = new char[stringSize + 1]; /* Initialize the new Memory for the new string */

			copyString(currPtr, newPtr, stringSize); /* Copy data before the deletion point into the new memory */

			delete stringPtr; /* Free old memory */

			stringPtr = newPtr; /* Reassign pointer */			
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}

/* Swaps the Data of the Given String */
void StringClass::swap( StringClass& strObj) 
{	
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			if (strObj.stringPtr != nullptr && strObj.stringSize != 0)  /* Check if Input string is valid */
			{
				/* Variable initialization */
				char* currPtr = stringPtr;
				char* newPtr = nullptr;
				char* newStartPtr = nullptr;
				size_t currSize = stringSize;
				size_t strSize = 0;
				size_t newSize = 0;

				/* Implementation ... Interchange Pointers of Objects  */
				newPtr = stringPtr;
				strSize = stringSize;
				stringPtr = strObj.stringPtr;
				stringSize = strObj.stringSize;
				strObj.stringPtr = newPtr;
				strObj.stringSize = strSize;
			}
			else
			{
				throw std::exception("Input Class Object is not initialized with a Valid String");
			}
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


/* Clears the String */
void StringClass::clear( )
{
	try
	{
		if (stringPtr != nullptr && stringSize != 0) /* Check if Object is valid */
		{
			delete  stringPtr;
			stringPtr = nullptr;
			stringSize = 0;
		}
		else
		{
			throw std::exception("Class Object is not initialized with a Valid String");
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << "\n!!Exception.." << exp.what() << std::endl;
		throw;
	}
}


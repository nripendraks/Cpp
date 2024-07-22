
#include <iostream>
#include"stringclass.h"
#include<vector>

using namespace std;

int main()
{
	try
	{
		StringClass* StrPtr = new StringClass("Hellow World!!");

		delete StrPtr;
	}
	catch (const std::exception& exp )
	{
		cout << "\n!!Exception.." << exp.what()<<endl;		
	} 	
	return 0;
}

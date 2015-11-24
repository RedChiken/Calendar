#include <iostream>
#include <fstream>
#include "Schedule.h"
using namespace std;

/*
this class can open and close file.
and also can read, write file.
overwriting and deletion will be also done in this class.
you guys just get this object(dont call it in class) and use function.

this class is not successfully completed.
*/

class FileLibrarian{
public:
	FileLibrarian();
	FileLibrarian(const FileLibrarian &flb);
	virtual ~FileLibrarian();

private:
	FileLibrarian();
	ofstream writeFile;
	ifstream readFile;
	
	bool isFileExist(string fileName);

	void write(struct context);
	struct context read(string date);
};
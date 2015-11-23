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
	FileLibrarian(string fileName);
	FileLibrarian(const FileLibrarian &flb);
	virtual ~FileLibrarian();

	void write(struct context);
	struct context read(string date);
	
private:
	string fileName;
	ofstream writeFile;
	ifstream readFile;
	
	bool isFileExist(string fileName);

};
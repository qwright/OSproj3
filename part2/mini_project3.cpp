#include <iostream>
#include <string>
#include "fs_func.hpp"

using namespace std;

int main(int argc, char *argv[]){
	
	myFileSystem disk("DISK0");
	~disk;

	return 0;
}

#include <iostream>
#include <string>
#include "fs_func.hpp"
#include "inode.hpp"

using namespace std;

int main(int argc, char *argv[]){
	
	myFileSystem disk("DISK0");
	char test[8] = {'T','e','s','t'};
	//int cr_file = disk.create(test, 50);
  int ls_stat = disk.ls();

	return 0;
}

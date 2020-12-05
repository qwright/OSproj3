#include "fs_func.hpp"
#include "inode.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

myFileSystem::myFileSystem(const char diskName[])
{
   // Open the file with name diskName
	string disk = diskName;
	streampos size;
	
   // Read the first 1KB and parse it to structs/objecs representing the super block
   // 	An easy way to work with the 1KB memory chunk is to move a pointer to a
   //	position where a struct/object begins. You can use the sizeof operator to help
   //	cleanly determine the position. Next, cast the pointer to a pointer of the
   //	struct/object type.
	 cout  << "Opened " << diskName << ", reading..." << endl;

	 ifstream fin (diskName, ios::binary|ios::ate);

	 if(fin.is_open()){
		 size = fin.tellg();//ios::ate gives us ptr at end of file, so we can check size
		 mem = new char [1024];

		 fin.seekg(0, ios::beg);//set ptr to beggining of stream 
		 fin.read(mem, 1024);
		 cout << "File size: " << size << " bytes" << endl;
		}else{
			cout << "Load failed!" << endl;
	 	}
	 cout.flush();
	 for(int i=0; i < 16; i++){
		 std::string used;
		 if(mem[8*i]==0){
			used = "Free";
		 }else{
			 used = "Used";
		 }
			 cout << "Block " << i << " is " << used << endl;
	 }
	 
	 fin.seekg(128, ios::beg);
	 Inode one;
	 fin.read((char*) & one, sizeof(one));
	 cout << "Node 1: " << one.is_used() << endl;

	 cout << endl;
	 fin.close();
	 cout << "File closed" << endl;

	
   // Be sure to close the file in a destructor or otherwise before
   // the process exits.
}

myFileSystem::~myFileSystem()
{
	 delete[] this->mem;
}


int myFileSystem::create(char name[8], int size)
{ //create a file with this name and this size

  // high level pseudo code for creating a new file

  // Step 1: Look for a free inode by searching the collection of objects
  // representing inodes within the super block object.
  // If none exist, then return an error.
  // Also make sure that no other file in use with the same name exists.

  // Step 2: Look for a number of free blocks equal to the size variable
  // passed to this method. If not enough free blocks exist, then return an error.

  // Step 3: Now we know we have an inode and free blocks necessary to
  // create the file. So mark the inode and blocks as used and update the rest of
  // the information in the inode.

  // Step 4: Write the entire super block back to disk.
  //	An easy way to do this is to seek to the beginning of the disk
  //	and write the 1KB memory chunk.
	return 0;
} // End Create



int myFileSystem::delete_file(char name[8])
{
  // Delete the file with this name

  // Step 1: Look for an inode that is in use with given name
  // by searching the collection of objects
  // representing inodes within the super block object.
  // If it does not exist, then return an error.

  // Step 2: Free blocks of the file being deleted by updating
  // the object representing the free block list in the super block object.

  // Step 3: Mark inode as free.

  // Step 4: Write the entire super block back to disk.
	return 0;

} // End Delete


int myFileSystem::ls(void)
{ 
  // List names of all files on disk

  // Step 1: Print the name and size fields of all used inodes.
	return 0;

} // End ls

int myFileSystem::read(char name[8], int blockNum, char buf[1024])
{

   // read this block from this file
   // Return an error if and when appropriate. For instance, make sure
   // blockNum does not exceed size-1.

   // Step 1: Locate the inode for this file as in Step 1 of delete.

   // Step 2: Seek to blockPointers[blockNum] and read the block
   // from disk to buf.
	return 0;

} // End read


int myFileSystem::write(char name[8], int blockNum, char buf[1024])
{

   // write this block to this file
   // Return an error if and when appropriate.

   // Step 1: Locate the inode for this file as in Step 1 of delete.

   // Step 2: Seek to blockPointers[blockNum] and write buf to disk.
	return 0;
   
} // end write


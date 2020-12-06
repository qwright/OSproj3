#include "inode.hpp"
#include <iostream>
#include <string>
#include <cstring>

Inode::Inode(const std::string &name, int size, int ptr[])
{
	strcpy(this->name, name.c_str());
	this->size = size;
	this->used = 1;
	for(int i=0; i < 8; i++){
		blockPtr[i] = ptr[i];
	}
}

Inode::~Inode()
{
}

int Inode::is_used()
{
	return this->used;
}

int Inode::get_name()
{
	for(int i=0; i < 8; i++)
	{
		std::cout << this->name[i] << std::endl;
	};
	std::cout << std::endl;
	return 0;
}

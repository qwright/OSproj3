#include <string>

class Inode
{
	private:
	char name[8];
	int size;
	int blockPtr[8];
	int used;//0 is free, 1 is used

	public:
	Inode(const std::string &name, int size, int ptr[]);
	~Inode();
	int is_used();
	int get_name();
};


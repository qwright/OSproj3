class Inode
{
	private:
	char name[8];
	int size;
	int blockPtr[8];
	int used;//0 is free, 1 is used
	
	public:
	int inode_used();
};


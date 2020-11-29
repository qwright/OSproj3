
class myFileSystem
{
	public:
		myFileSystem(const char diskName[]);
		~myFileSystem();
		int create(char name[8], int size);
		int delete_file(char name[8]);
		int ls(void);
		int read(char name[8], int blockNum, char buf[1024]);
		int write(char name[8], int blockNum, char buf[1024]);
};


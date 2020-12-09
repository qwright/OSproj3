# File System Project

## Contributors

Quinn Wright and Chinmay Gopal

## Design Choices

Unfortunately this part of the project ran into time and scope trouble. Both of us found it hard to coordinate with each other due to time differences and implemented seperate versions in C++ and C respectively. Neither were able to get a working implementation of the code with our limited experience in these languages. With our main problem revolving around accessing the disk and properly using syntax, there are only a few functions that work.

Design of the file system was in theory very simple. We were to have a buffer that was read from the disk, and use that to change/keep track of data using a superblock structure with a list of inodes. This was then written back to the disk after altering it (note that you can use the buffer for as long as needed, so long that it stays synced with the disk). 

With more time, we would hopefully figure out how to correctly access the disk and then better program the functions, as the theory seems to be somewhat understandable. Most of the issues were not logic based but syntax based. 

Currently only Create, Delete, and ls are partially implemented. 

## Run Instructions

Clone this repositiory `git clone https://github.com/qwright/OSproj3.git` and navigate to part2 folder.

If using the C implementation, build the disk with `gcc lab3.create_fs.c main` 

or C++ with `g++ mini_project3.cpp fs_func.cpp inode.cpp`

and run with `./mini_project3` or `./a.out` respectively. 

This might be futile however and you are better off just reading the code for the reasons above.

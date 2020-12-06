#Paging Memory Management Project

##Contributors
Christian Pasteris and Jesse Plamondon

##Design Choices
The paging system was designed to read 16 bit decimal addresses from an input file, as well as the bits allocated to the page number and offset; this is read by the program
into an array of 32 bit unsigned integers. The program seperates the page number and the offset from the address using shifts by the number of bits specified by each portion as well as an additional
16 bits to account for the additional 16 bits of 0's added when the addresses are read by the system. The program then outputs the page nuber and offset as decimal interpretations
of the binary address components.

##Run Instructions

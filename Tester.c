#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <sys/stat.h>
#include <fcntl.h>
   
#include <stdio.h>


char    *ft_strchr(const char *str, int compared)
    {
	unsigned int	value;

	value = 0;
	while (str[value])
	{
		if (str[value] == (char)compared)
		{
			return ((char *)&str[value]);
		}
		value++;
	}	
	if ((char)compared == str[value])
		return ((char *)&str[value]);
	return (NULL);
}

int find_newline(char *temp,char **line)
{
  int inc; 
  inc = 0;
  while(temp[inc] && temp[inc] !='\n')
  {
   printf("%c",temp[inc]); 
    inc++;
  }
  //i think there will neade to be a conditional when it find a \n vs being full;
return (inc);
}
int get_next_line(int fd, char **line)
{
int BUFFER_SIZE = 32;
char    *temp;
int     status;
int     lenght;

temp = malloc(sizeof(BUFFER_SIZE) * 32);
status = read(fd,temp,BUFFER_SIZE);
//read return the number of elem it was able to read
 lenght = find_newline(temp,line);
 printf("%d",lenght);
return (status);
}
   int main(int argc,char* argv[])
{
static char  *val;
char  *buffer;
char **lines;
int file_location;
int status;
argc = 0;
	file_location = open(argv[1],O_RDONLY );
     status =  get_next_line(file_location,lines);

	//read the element until  your find a newline or a you fill the buffre 
	//which will be deleted on each round this memory will then be put on a static buffer(persistant between each call;
	//the memory static is cleared when a newline is found and the string is sennt;
	// the longer the buffer is the number of time the read function is called;
    //the **lines the line count we are at... in the buffer;
    //#do we know in advance the number of line?;
}

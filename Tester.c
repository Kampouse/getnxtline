#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <sys/stat.h>
#include <fcntl.h>
   
#include <stdio.h>
size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char*)malloc(
		sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}


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

char *find_newline(char *temp)
{
  int inc; 
  char *output;
	  inc = 0;
  while(temp[inc] && temp[inc] !='\n')
  {
    inc++;
  }
 	output = ft_substr(temp,0,inc);
	free(temp);
	return(output);
  //i think there will neade to be a conditional when it find a \n vs being full;
}
int get_next_line(int fd)
{
int BUFFER_SIZE = 32;
char			*temp;
char			*tempb;
unsigned int     readsize;
static char 	*storage;
temp = malloc(sizeof(char) * BUFFER_SIZE);

readsize = read(fd,temp,BUFFER_SIZE);
if(readsize > 0)
{
 tempb = find_newline(temp);
}
else
	return(0);

 if(!storage && readsize > 0) 
	 storage = tempb;
 	else 
  		storage = ft_strjoin(storage,tempb);
 printf("%s",storage);
 printf("%lu",ft_strlen(storage));
return (readsize);
}
   int main(int argc,char* argv[])
{
int file_location;
int status;
status = 0;
argc = 0;
	file_location = open(argv[1],O_RDONLY );
	
     while(get_next_line(file_location) > 0)
	 {
		 printf("%d \n",status++);
	 }

	//read the element until  your find a newline or a you fill the buffre 
	//which will be deleted on each round this memory will then be put on a static buffer(persistant between each call;
	//the memory static is cleared when a newline is found and the string is sennt;
	// the longer the buffer is the number of time the read function is called;
    //the **lines the line count we are at... in the buffer;
    //#do we know in advance the number of line?;
}

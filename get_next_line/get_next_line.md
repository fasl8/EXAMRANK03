# get_next_line

| Assignment name | Expected files | Allowed functions |
| --------------- | -------------  | ----------------- |
| get_next_line      | get_next_line.c get_next_line.h  | read, free, malloc |

### rules:
* Your function must be declared as follows(Prototype): ``` char  *get_next_line(int fd); ```

i. LINE:
* Your function must return a line that has been read from the file descriptor passed as parameter.
* What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).
* The line should be returned including the '\n' in case there is one at the end of the line that has been read.
  
ii. BUFFER
* When you've reached the EOF, you must store the current buffer in a char * and return it.
  
iii. NULL
* If the buffer is empty you must return NULL.
* In case of error return NULL.
* In case of not returning NULL, the pointer should be free-able.
  
iiii. MEMORY
* Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.
* Your function must be memory leak free.
* When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

iiiii. FUNCTION
* Calling your function get_next_line in a loop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size or either the text or one of its lines.
* Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...
* No call to another function will be done on the file descriptor between 2 calls of get_next_line.

iiiiii. FILE
* Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.

### how to write the code step by step:
1. include the header file(which contains function prototypes or declarations): ``` #include "get_next_line.h" ```
2. include the prototypes(takes fd (file descriptor), return a ponter char): ``` char	*get_next_line(int fd) ```
3. Index to track the current position in the buffer: ``` int i = 0; ```
4. Variable to store the result of the read system call: ``` int store_read; ```
5. Variable to store the current character read from the file: ``` char	line; ```
6. Pointer to char to store the characters read from the file: ``` char	*buffer; ```
7. if the file descriptor fd is less than 0(not a valid file descriptor), if the read system call with NULL buffer and size 0 fails(error reading from the file descriptor), if the defined BUFFER_SIZE is less than or equal to 0( invalid or non-positive buffer size.)
```
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
```
8. ```
    	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
   ```
9. read a single character from the file descriptor fd into the variable line. The number of bytes read is stored ``` store_read = read(fd, &line, 1); ```

10. reads characters from the file and stores them in the buffer until a newline character ('\n') is encountered or the end of the file is reached
```
	while (store_read > 0)
	{
		buffer[index++] = line;
		if (line == '\n')
			break ;
		store_read = read(fd, &line, 1);
	}
```
11. ``` buffer[index] = '\0'; ```
12. if no characters were read (i == 0) and if the read system call returned a non-positive value (b <= 0) -> end of the file has been reached and time to free:
```
	if (index == 0 && store_read <= 0)
		return (free(buffer), (NULL));
```
13. ``` return (buffer); ```

# ft_printf

| Assignment name | Expected files | Allowed functions |
| --------------- | -------------  | ----------------- |
| ft_printf      | ft_printf.c  | malloc, free, write, va_start, va_arg, va_copy and va_end|

### rules:
* Write a function named ft_printf which prototype should be: ``` int ft_printf(const char *, ... ) ```
* mimic the real printf but it will manage only the following conversions:
s (string)
d (decimal) 
x (lowercase hexademical)

### example:
1. ft_printf("%s\n", "toto") -> toto$
2. ft_printf("Magic %s is %d", "number", 42) -> Magic number is 42%
3. ft_printf("Hexadecimal for %d is %x\n", 42, 42) -> Hexadecimal for 42 is 2a$

### write the code step by step:
1. ``` #include <stdarg.h> ```: handling variable arguments in functions.
2. ``` #include <unistd.h> ```: for the write function.
#### printstr
3. takes a string ``` char *str ```: represents the string that needs to be printed
4. pointer to an integer ``` int *len ```: keeps track of the total length of characters printed
5. If the string is NULL, it sets str to point to the string "(null)".
```
	if (!str)
		str = "(null)";
```
6. iterates through each character in the string and writes it to the standard output, and update the length
```
	while (*str)
		*len += write(1, str++, 1);
```
#### printdigit
7. ``` long long int i, ```: integer that needs to be printed, work with integers of different sizes
8. ``` int base ```: specifies the base in which the integer should be printed (base 10 -> decimal form, base 16 -> hexadecimal form).
9. pointer to an integer ``` int *len ```: keeps track of the total length of characters printed
10. If the number is negative, it writes a "-" sign and converts the absolute value
```
	if (i < 0)
	{
		i *= -1;
		*len += write(1, "-", 1);
	}
```
11. store the characters representing digits in hexadecimal form
```
	char	*hexa;
	hexa = "0123456789abcdef";
```
12. check is greater than or equal to the specified base. If true, it means there are more digits to be printed, handling the remaining digits of the integer.
```
	if (i >= base)
		printdigit((i / base), base, len);
```
13. taking the remainder (i % base) when dividing the current value of i by the specified base,

example : i = 8 -> 8 % 10 = 8 -> hexa[8] -> 8

example : i = 17 -> 17 / 16 = 1 -> hexa[1] -> 1 output -> back to the original i = 1 -> and again write 1 
```
Index:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
Digit:  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
```
#### ft_printf
15. 

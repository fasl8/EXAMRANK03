# ft_printf

| Assignment name | Expected files | Allowed functions |
| --------------- | -------------  | ----------------- |
| ft_printf      | ft_printf.c  | malloc, free, write, va_start, va_arg, va_copy and va_end|

### rules:
* Write a function named ft_printf which prototype should be: ``` int ft_printf(const char *, ... ) ```
* mimic the real printf but it will manage only the following conversions:
```
s (string)
d (decimal) 
x (lowercase hexademical)
```

### example:
1. ft_printf("%s\n", "toto") -> toto$
2. ft_printf("Magic %s is %d", "number", 42) -> Magic number is 42%
3. ft_printf("Hexadecimal for %d is %x\n", 42, 42) -> Hexadecimal for 42 is 2a$

### write the code step by step:
1. ``` #include <stdarg.h> ```: handling variable arguments in functions.
2. ``` #include <unistd.h> ```: for the write function.

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);
  while (*format != '\0') {
    if (*format == '%') {
      
      count += print_special_format(format, args);
      format += 2;
    } else {
      
      count += putchar(*format);
      format++;
    }
  }
  va_end(args);

  return count;
}

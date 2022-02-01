
#ifndef My_string
#define	My_string1

char *strcat(char *dest, const char *src);
char *strcpy(char *dest, const char *src);
size_t strlen(const char *);
int strcmp(const char *, const char *);
char *strncpy(char *dest, const char *src, size_t n);
char *strncat(char *dest, const char *src, size_t n);
char *strncpy(char *dest, const char *src, size_t n);
char *strchr(const char *, int c);
char *strrchr(const char *, int c);
char *strpbrk(const char *, const char *accept);
size_t strcspn(const char *, const char *reject);
size_t strspn(const char *, const char *accept);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *, const char * delim);
int sprintf(char *str, const char *format, ...);
int sscanf(const char *str, const char *format, ...);

#endif
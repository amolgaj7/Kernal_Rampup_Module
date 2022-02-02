
#ifndef My_string
#define My_string

char *my_strcat(char s1[], char s2[]);
char *my_strtok(char *str, const char *tok);
char *my_strcpy(char *dest, const char *src);
size_t my_strlen(const char *);
int my_strcmp(const char *s1, const char *s2);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strncat(char *dest, const char *src, size_t n);
char *my_strchr(char *, int c);
char *my_strrchr(const char *p, int ch);
char *my_strpbrk(char *str1, char *str2);
//int sprintf(char *str, const char *format, ...);
//int sscanf(const char *str, const char *format, ...);
int my_strncmp(char *s1, char *s2, unsigned long count);
unsigned int my_strspn(const char *s1, const char *s2);
unsigned int my_strcspn(const char *s1, const char *s2);
const char *my_strstr(const char *s1, const char *s2);

char *my_strcat(char s1[], char s2[])
{

    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        ;

    for (j = 0; s2[j] != '\0'; j++)
        s1[i + j] = s2[j];

    s1[i + j] = '\0';

    return s1;
}

size_t my_strlen(const char *p)
{
    unsigned int count = 0;

    while (*p != '\0')
    {
        count++;
        p++;
    }

    return count;
}

char *my_strtok(char *str, const char *tok)
{
    int i = 0;
    while (str[i] != '\0')
    {
        for (int j = 0; j < my_strlen(tok); j++)
        {
            if (str[i] == tok[j])
            {
                str[i] = '\0';
                return str;
            }
        }
        i++;
    }
    return NULL;
}

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return 0;

    else if (*s1 > *s2)
        return 1;

    else
        return -1;
}

char *my_strcpy(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    // return if no memory is allocated to the destination
    if (dest == NULL)
    {
        return NULL;
    }

    // take a pointer pointing to the beginning of the destination string
    char *ptr = dest;

    // copy first `num` characters of C-string pointed by source
    // into the array pointed by destination
    while (*src && n--)
    {
        *dest = *src;
        dest++;
        src++;
    }

    // null terminate destination string
    *dest = '\0';

    // the destination is returned by standard `strncpy()`
    return ptr;
}

char *my_strncat(char *dest, const char *scr, size_t n)
{
    // make `ptr` point to the end of the destination string
    char *ptr = dest + my_strlen(dest);

    // Appends characters of the source to the destination string
    while (*scr != '\0' && n--)
    {
        *ptr++ = *scr++;
    }

    // null terminate destination string
    *ptr = '\0';

    // destination string is returned by standard `strncat()`
    return dest;
}

int my_strncmp(char *s1, char *s2, unsigned long count)
{
    for (int i = 0; i < count; i++)
    {
        if (s1[i] != s2[i])
        {
            return i;
        }
    }
    return 0;
}

char *my_strchr(char *s, int c)

{
    while (*s != (char)c)
    {
        if (!*s++)
        {
            return NULL;
        }
    }
    return s;
}

char *my_strrchr(const char *p, int ch)
{
    char *save;
    for (save = NULL;; ++p)
    {
        if (*p == ch)
            save = (char *)p;
        if (!*p)
            return (save);
    }
    /* NOTREACHED */
}

char *my_strpbrk(char *str1, char *str2)
{
    int i = 0;
    int j = 0;

    int pos = 0;
    int flg = 0;

    while (*(str1 + i))
        i++;

    pos = i;
    i = 0;
    while (*(str2 + i))
    {
        j = 0;
        while (*(str1 + j))
        {
            if (str2[i] == str1[j])
            {
                if (j <= pos)
                {
                    pos = j;
                    flg = 1;
                }
            }
            j++;
        }
        i++;
    }

    if (flg == 1)
        return &str1[pos];

    return NULL;
}

unsigned int my_strspn(const char *s1, const char *s2)
{
    unsigned int len = 0;
    //return 0 if any one is NULL
    if ((s1 == NULL) || (s2 == NULL))
        return len;
    //return s1 char position if found in s2
    //if not found return NULL
    while (*s1 && my_strchr(s2, *s1++))
    {
        len++;
    }
    return len;
}

unsigned int my_strcspn(const char *s1, const char *s2)
{
    unsigned int len = 0;
    //return 0 if any one is NULL
    if ((s1 == NULL) || (s2 == NULL))
        return len;
    //till not get null character
    while (*s1)
    {
        //return s1 char position if found in s2
        if (my_strchr(s2, *s1))
        {
            return len;
        }
        else
        {
            //increment s1
            s1++;
            //increment len variable
            len++;
        }
    }
    return len;
}

int compare(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return 0;
        }

        s1++;
        s2++;
    }

    return (*s2 == '\0');
}

// Function to implement `strstr()` function
const char *my_strstr(const char *s1, const char *s2)
{
    while (*s1 != '\0')
    {
        if ((*s1 == *s2) && compare(s1, s2))
        {
            return s1;
        }
        s1++;
    }

    return NULL;
}

#endif
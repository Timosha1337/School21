#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

int     ft_isalpha(int argument);
int     ft_isdigit( int arg );
int     ft_isalnum(int argument);
int     ft_isascii(int ch);
int     ft_isprint( int arg );
size_t  ft_strlen(const char *str);
void *ft_memset(void *str, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void * src, size_t n);
void *ft_memmove( void *str1, const void *str2, size_t n );
size_t ft_strlcpy(char * dst, const char * src, size_t n);
size_t ft_strlcat(char *dest, const char *src, size_t size);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr( const char * string, int symbol);
char *ft_strrchr (const char *str, int ch);
int ft_strncmp(const char *str1, const char *str2, size_t n);
void *ft_memchr (const void *arr, int c, size_t n);
int ft_memcmp (const void *arr1, const void *arr2, size_t n);
char *ft_strstr(const char *scr, const char *sought);
int ft_atoi (const char *str);

int main()
{
    char *number = "";
    int n = atoi(number);
    printf("%i\n",n);
    printf("%i\n",INT_MIN);
}

int ft_atoi (const char *str)
{
    int res;
    int ngt;

    res = 0;
    ngt = 1;
    if (!str)
        return (0);
    while (*str == '\t' || *str == '\n' || *str == '\v' ||
            *str == '\f' || *str == '\r' || *str == ' ')
        *str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            ngt = -1;
     *str++;
    }

    while (*str >= '0' && *str <= '9')
        res = (res * 10) + (*str++ - '0');
    return (res * ngt);
}

char *ft_strstr(const char *src, const char *sought)
{
    int i;
    char *c;

    i = 0;
    while (*src != '\0')
    {
        if (*src == sought[i])
        {
            if (i == 0)
                c = (char*)src;
            i++;
            if (sought[i]=='\0')
                return (c);
        }
        else
            i = 0;
        *src++;
    }
    return (NULL);
}

int ft_memcmp (const void *arr1, const void *arr2, size_t n)
{
    const unsigned char *arr1CChar = arr1;
    const unsigned char *arr2CChar = arr2;

    while (n--)
    {
        if (*arr1CChar != *arr2CChar)
        {
            return ((int)*arr1CChar - *arr2CChar);
        }
        *arr1CChar++;
        *arr2CChar++;
    }
    return (0);
}

void *ft_memchr (const void *arr, int c, size_t n)
{
    const unsigned char *arrChar;

    arrChar = arr;
    if(arr == NULL)
        return (NULL);
    while (n--)
    {
        if (*arrChar == (unsigned char)c)
            return ((void *)arrChar);
        *arrChar++;
    }
    return (NULL);
}
int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n--)
    {
         if (str1[n] > str2[n])
             return (1);
         else if (str1[n] < str2[n])
             return (-1);
         else
             return (0);
    }
}

char *ft_strrchr (const char *string, int symbol)
{
    char *value;

    while (*string || symbol == '\0' )
    {
        if (*string == symbol)
            value = (char  *)string;
        if (*string == '\0')
            break;
        *string++;
    }
    if (*value == symbol)
        return (value);
    return (NULL);
}

char *ft_strchr( const char * string, int symbol)
{
    char *value;

    value = string;
    while (*value != symbol)
        *value++;
    if (*value == symbol)
        return (value);
    return (NULL);
}

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
        return (c + 32);
    return (c);
}

int ft_toupper(int c)
{
    if (c >= 97 && c<= 122)
        return (c - 32);
    return (c);
}
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dstSize;
    size_t i;

    i = 0;
    dstSize = ft_strlen(dst);

    if (src!=NULL)
    {
        while (src[i] && dstSize + i < size - 1)
        {
            dst[i+dstSize] = src[i];
            i++;
        }
        dst[i+dstSize] = 0;
    }

    if (dstSize>size)
        dstSize = size;
    return (dstSize + ft_strlen(src));
}
size_t ft_strlcpy(char * dst, const char * src, size_t n)
{
    size_t	i;

    i = n;
    if (n > 0)
    {
        while (i-- > 1 && *src)
            *dst++ = *src++;
        *dst++ = '\0';
    }

    while (src[i])
        i++;
    printf("%i\n",i+n-1);
    return (i+n);
}

int     ft_isalpha(int argument)
{
    if ((argument >= 'A' && argument <= 'Z') || (argument >= 'a' && argument <= 'z'))
        return (1);
    return(0);
}

int     ft_isdigit( int arg )
{
    if(arg >= '0' && arg<='9')
        return (1);
    return (0);
}

int     ft_isalnum(int argument)
{
    return (ft_isdigit(argument)|| ft_isalpha(argument));
}

int     ft_isascii(int ch)
{
    if (ch >=0 && ch <= 126)
        return (1);
    return (0);
}

int     ft_isprint( int arg )
{
    if (arg >= 32)
        return (1);
    return (0);
}
size_t  ft_strlen(const char *str)
{
    size_t i =0;
    while (*str!='\0')
    {
        *str++;
        i++;
    }
    return (i);
}
void *ft_memset(void *str, int c, size_t n)
{
    unsigned char *strChar;

    if (str == NULL)
        return (NULL);
    strChar = (unsigned char *) str;
    while (n > 0)
    {
        *strChar = (unsigned char) c;
        *strChar++;
        n--;
    }
    return (strChar);
}
void ft_bzero(void *str, size_t n)
{
    unsigned char *strChar;

    strChar = (unsigned char *)str;
    while (n--)
    {
        *strChar = '\0';
        *strChar++;
    }
}
void *ft_memcpy(void *dest, const void * src, size_t n)
{
    unsigned char *destChar;
    unsigned char *srcChar;

    destChar = (unsigned char *) dest;
    srcChar = (unsigned char *) src;
    while (n--)
        *destChar++=*srcChar++;
    return (dest);
}
void *ft_memmove( void *str1, const void *str2, size_t n )
{
    unsigned char *str1Char;
    const unsigned char *str2Char;
    unsigned char current;
    unsigned char next;

    str1Char = (unsigned char *) str1;
    str2Char = (const unsigned char *) str2;
    if (str1 < str2)
    {
        while (n--)
        {
            *str1Char++ = *str2Char++;
        }
    }
    else
    {   current = *str2Char;
        while (n--)
        {
            next = *str1Char;
            *str1Char++ = current;
            current = next;
        }
    }
    return (str1);
}




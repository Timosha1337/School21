#include <stdio.h>
#include <string.h>

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
size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t ft_strlcat(char *dest, const char *src, size_t size);
int main() {
    unsigned char src[10]="1234567890";
    ft_memmove(&src[4],&src[3],3);
    printf ("src: %s\n",src);
    return 0;
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




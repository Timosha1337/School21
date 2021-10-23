#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


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
void *ft_calloc(size_t num, size_t size);
char *ft_strdup(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
int get_count_words(char const *s, char c);
char *ft_itoa(int n);
int count_numbers(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

int main()
{
    ft_putnbr_fd(-123123,1);
}
void	ft_putnbr_fd(int n, int fd)
{
    char symb;

    if (n < 0) {
        write(fd, "-", 1);
        n*=-1;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
    {
        symb = n + '0';
        write(fd, &symb, 1);
    }
}

void ft_putendl_fd(char *s, int fd)
{
    if(s)
        write(fd, s, ft_strlen(s));
    write(fd,'\n',1);
}
void ft_putstr_fd(char *s, int fd)
{
    if(s)
        write(fd, s, ft_strlen(s));
}
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;

    i = 0;
    if(s && f)
    {
        while (s[i])
        {
            f(i,&s[i]);
            i++;
        }
    }
}
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *res;
    unsigned int i;

    i = 0;
    res = (char*) malloc(ft_strlen(s));
    if (!res || !f || !s)
        return (NULL);
    while (s[i])
    {
        res[i] = f(i,s[i]);
        i++;
    }
    res[i] = 0;
    return (res);
}
int count_numbers(int n)
{
    int res;
    res=0;
    while (n!=0)
    {
        n/=10;
        res++;
    }
    return (res);
}
char *ft_itoa(int n)
{
    char *res;
    int minus;
    int count;

    if (n==0)
        return ("0");
    minus = 0;
    if (n < 0)
    {
        n *= -1;
        minus = 1;
    }
    count = count_numbers(n) + minus;
    if(!count)
        return (NULL);
    res = (char*) malloc(count);
    res[count]=0;
    count--;

    while (n!=0)
    {
        res[count] = (char )((n%10)+48);
        n/=10;
        count--;
    }
    if(minus > 0)
        res[count]='-';
    return (res);
}
char *get_wrd(char const *s, int start, int end)
{
    char *res;
    int i;
    i = 0;
    res = malloc(end - start);//-1
    while (start < end)
        res[i++] = s[start++];
    res[i] = 0;
    return (res);
}
int get_count_words(char const *s, char c)
{
    int i;
    int flag;
    int count;

    i = 0;
    flag = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != c && !flag)
            flag = 1;
        if (s[i] == c && flag)
        {
            count++;
            flag = 0;
        }
        if (s[i+1] == '\0' && flag)
            count++;
        i++;
    }
    return (count);
}
char **ft_split(char const *s, char c)
{
    char **res;
    int i;
    int flag;
    int startFinish[2];
    int j;

    j = 0;
    i = 0;
    flag =0;
    res = (char **) malloc(get_count_words(s,c));
    while (s[i])
    {
        if (s[i] != c && !flag)
        {
            flag = 1;
            startFinish[0] = i;
        }
        if (s[i] == c && flag)
        {
            flag = 0;
            startFinish[1] = i;
        }
        if (s[i+1] == '\0' && flag)
            startFinish[1] = i;
        if (startFinish[1] > startFinish[0])
        {
            res[j] = get_wrd(s, startFinish[0], startFinish[1]);
            j++;
            startFinish[0] = 0;
            startFinish[1] = 0;
        }
        i++;
    }
    return (res);
}

int ft_math(char  s1, char const *set)
{
    int j;

    j = 0;
    while (set[j])
    {
        if(s1 == set[j])
            return (1);
        j++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int i;
    int end;
    char *res;

    start = 0;
    i = 0;
    end = (int)ft_strlen(s1);
    while (s1[start] && ft_math(s1[start],set))
        start++;
    while (end - 1 > start && ft_math(s1[end - 1], set))
        end--;
    res = malloc(end - start);
    while (start < end)
        res[i++] = s1[start++];
    res[i] = 0;
    return (res);
}
char *ft_strtrim_fake(char const *s1, char const *set)
{
    char *res;
    char  *buf;
    int i;
    int j;
    int setLen;

    setLen = (int) ft_strlen(set);
    i = 0;
    j = 0;
    res = malloc(1);
    buf = malloc(1);
    while (*s1)
    {
        while (set[i])
        {
            if (*s1 == set[i])
                break;
            else
                i++;
        }
        if (setLen == i)
        {
            buf[j] = *s1;
            res = malloc(j);
            res = buf;
            j++;
            buf = malloc(j);
            buf = res;
            if (!res || !buf)
                return (NULL);
        }
        i = 0;
        *s1++;
    }
    res[j] = 0;
    return (res);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char * concat;
    int i;

    i = 0;
    concat = malloc(ft_strlen(s1)+ ft_strlen(s2));
    if (!concat)
        return (NULL);
    while (*s1)
    {
        concat[i] = *s1;
        i++;
        *s1++;
    }
    while (*s2)
    {
        concat[i] = *s2;
        i++;
        *s2++;
    }
    concat[i]=0;
    return(concat);
}
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    int i;


    i = 0;
    sub = malloc(len);
    if(s == NULL || start > ft_strlen(s) || !sub)
        return (NULL);
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = 0;
    return (sub);
}

char *ft_strdup(const char *str)
{
    char *res;
    int i;

    if(!str)
        return (NULL);
    i = 0;
    res =  malloc(ft_strlen(str));
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
    res[i] = 0;
    return (res);
}

void *ft_calloc(size_t count, size_t size)
{
    void * res;

    res = (void *) malloc(size * count);
    if (!res)
        return (NULL);
    ft_bzero(res,count);
    return (res);
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




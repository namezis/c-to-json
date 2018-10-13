/**
 * Tools for string processing.
 *
 * @authors: Denis Chernikov, Vladislav Kuleykin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alloc_wrap.h"
#include "string_tools.h"

char *concat_array(char **array, int n, char *delimiter)
{
    if (n < 0)
    {
        return NULL;
    }
    if (n == 0)
    {
        return (char *) calloc(1, sizeof(char));
    }
    if (n == 1)
    {
        return *array;
    }
    int i, j, k;
    size_t d_len = strlen(delimiter);
    size_t len = d_len * (n - 1);
    for (i = 0; i < n; ++i)
    {
        len += strlen(array[i]);
    }
    char *res = (char *) my_malloc(sizeof(char) * (len + 1),
            "string concatenation");
    size_t cur_len;
    k = 0;
    for (i = 0; i < n; ++i)
    {
        j = 0;
        while (array[i][j] != '\0')
        {
            res[k++] = array[i][j++];
        }
        if (k == len) break;
        j = 0;
        while (delimiter[j] != '\0')
        {
            res[k++] = delimiter[j++];
        }
    }
    res[k] = '\0';
    return res;
}

char *repeat(int n, char *str)
{
    if (n < 0)
    {
        return NULL;
    }
    if (n == 0)
    {
        return (char *) calloc(1, sizeof(char));
    }
    if (n == 1)
    {
        return str;
    }
    size_t src_len = strlen(str);
    size_t res_len = src_len * n;
    char *res = (char *) my_malloc(sizeof(char) * (res_len + 1),
            "string repetition");
    int i;
    for (i = 0; i < res_len; ++i)
    {
        res[i] = str[i % src_len];
    }
    res[i] = '\0';
    return res;
}

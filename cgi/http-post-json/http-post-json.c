#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jsmn.h"

#define MAX_LEN 1000
#define EXTRA 5

/* 4 for field name "data", 1 for "=" */
#define MAX_INPUT (MAX_LEN + EXTRA + 2 )

/* 1 for added line break, 1 for trailing NULL */
#define DATAFILE "../data/data.txt"

void unencode(char *src, char *last, char *dest)
{
    for(; src != last; src++, dest++)
    {
        if(*src == '+')
            *dest = ' ';
        else if(*src == '%')
        {
            int code;

            if(sscanf(src + 1, "%2x", &code) != 1)
                code = '?';

            *dest = code;
            src += 2;
        }
        else
            *dest = *src;

    }

    *dest = '\n';
    *++dest = '\n';
}

int main(char** argv)
{
    char *lenstr;
    char input[MAX_INPUT], data[MAX_INPUT];
    long len;
    int numtoken;
    
    FILE *f;

    jsmn_parser parser;
    jsmntok_t tokens[1000];

    /* Header */
    printf("%s%c%c\n",
            "Content-Type:text/html; charset=iso-8859-1",
            13,
            10);
    printf("<TITLE>Response</TITLE>\n");

    /* POST data length */
    lenstr = getenv("CONTENT_LENGTH");

    if(lenstr == NULL ||
            sscanf(lenstr, "%ld", &len) != 1 ||
            len > MAX_LEN)
    {
        printf("<P>Error in invocation - wrong FORM probably.");
        return 0;
    }

    /* Read POST data */
    fgets(input, len + 1, stdin);

    printf("<P>POST request content length %ld\n", len);
    printf("<P>POST request content %s\n", input);

    /* JSON ? */
    jsmn_init(&parser);

//  numtoken = jsmn_parse(&parser, input, strlen(input), tokens, 100);

    /* Passing NULL instead of tokens will show the number of tokens */
    numtoken = jsmn_parse(&parser, input, strlen(input), NULL, NULL);

    switch(numtoken)
    {
    case JSMN_ERROR_INVAL:
        printf("<P>Bad token, JSON string is corrupted.\n");
        break;

    case JSMN_ERROR_NOMEM:
        printf("<P>Not enough tokens, JSON string is too large.\n");
        break;
        
    case JSMN_ERROR_PART:
        printf("<P>JSON string is too short, expecting more JSON data.\n");
        break;
    }

    printf("<P>Number of JSON tokens %d\n", numtoken);



#if 0
    unencode(input+EXTRA, input+len, data);

    f = fopen(DATAFILE, "a");

    if(f == NULL)
        printf("<P>Sorry, cannot store your data.");
    else
        fputs(data, f);

    fclose(f);
#endif

    return 0;
}


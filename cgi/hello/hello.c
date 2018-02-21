#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void){
    int errno = 200;
    char *errstr = "OK";

#define TIMESTR_LEN 100
    char timestr[TIMESTR_LEN] = {0, };
    time_t now = time(0);
    struct tm tm = *gmtime(&now);

    /* HTTP version and response status */
    printf("HTTP/1.1 %d %s\n", errno, errstr);
    /* Host information */
    printf("Host: http://localhost:3000\n");


    /* Date */
    memset(timestr, 0x0, TIMESTR_LEN);
    strftime(timestr, sizeof(timestr), "%a, %d %b %Y %H:%M:%S %Z", &tm);
    printf("Date: %s\n", timestr);

    /* Content type */
	printf("Content-Type: text/plain\n");
    /* Character set */
	printf("charset=UTF-8\n\n");

    /* Body */
	printf("Hello world!\n");

	return 0;
}


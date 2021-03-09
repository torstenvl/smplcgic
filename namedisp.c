#include <stdio.h>
#include <stdlib.h>
#include "smplcgic.h"

int main(void) {
    char *cgi;
    char *username;

    cgi = cgi_init();
    if (IS_CGI_ERROR(cgi)) { perror(cgi_err); exit(EXIT_FAILURE); }

    username = cgi_valof(cgi, "username");
    if (IS_CGI_ERROR(username)) { perror(cgi_err); exit(EXIT_FAILURE); }

    printf("Content-type: text/html\n\n");
    printf("\
<!DOCTYPE html>\n\
<html>\n\
    <head><title>Hello, there</title></head>\n\
    <body>\n\
        <h1>Hello, %s!</h1>\n\
    <body>\n\
</html>\n",
    username);

    cgi_free(username);
    cgi_free(cgi);

    return EXIT_SUCCESS;
}

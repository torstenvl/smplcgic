# smplcgic

Simple CGI in C Library

This is a simple library that makes writing CGI in C very easy.

Only GET and POST methods with encoding type application/x-www-form-urlencoded is supported.  This library will not work with multipart encodings, and so is not suitable to applications requiring file upload capability.

Usage:

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

To install this:

* Compile this along with the smplcgic.c file into a .cgi file: `cc namedisp.c smplcgic.c -o namedisp.cgi`
* Install the .cgi file on your webserver
* Ensure the execute permission is set on the .cgi file
* Ensure the web server is configured to execute .cgi files
* Ensure the directory is allowed to execute .cgi files
* Reference this .cgi file in the `action` attribute of your `<form>` tag

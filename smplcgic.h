#ifndef TCGIC_H
#define TCGIC_H





///////////////////////////
// Function declarations //
///////////////////////////
char *cgi_init(void);
char *cgi_valof(char *, char *);
char *cgi_allvalof(char *, char *, int);
void  cgi_free(void *);

char *findvalue(char *, char *);
char *extractvalue(char *);



////////////////////
// ERROR HANDLING //
////////////////////

// Pointer return values will point to these instead of returning NULL,
// with each of these globals set to value '\0' on initialization.
// This allows error detection by comparing the first element to '\0'
// and then more specific information being determined by which, exactly,
// the returned pointer references.

// Bonus: if the user-programmer tries using the return value without
// checking for an error, it will just be an empty string.
char cgi_memAllocErr;            /* Error allocating memory */
char cgi_nullReqMeth;            /* REQUEST_METHOD not set/accessible */
char cgi_nullQryStrn;            /* QUERY_STRING not set/accessible */
char cgi_nullContLen;            /* CONTENT_LENGTH not set/accessible */
char cgi_usupReqMeth;            /* Unsupported request method */
char cgi_zeroContLen;            /* Zero content length (POST) */
char cgi_negMultIndx;            /* Negative index in multvalof */
char cgi_varNotFound;            /* Variable not in data string */
char cgi_nullArgPssd;            /* Null pointers passed to valof */

// Macro for clean syntax
#define IS_CGI_ERROR(x) (x[0] == '\0')

// Additional information about the error can be stored in this global
// string buffer, with constant size TCEZ.
#define CGIERRZ 256
char cgi_err[CGIERRZ];





#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* trim(char* input) {
    char* start = input;
    while (isspace(*start)) { //trim left
        start++;
    }

    char* ptr = start;
    char* end = start;
    while (*ptr++ != '\0') { //trim right
        if (!isspace(*ptr)) { //only move end pointer if char isn't a space
            end = ptr;
        }
    }

    *end = '\0'; //terminate the trimmed string with a null
    return start;
}


int strcount(char* buf,char* c){
    int size=1;
    for(int i=0;i<=strlen(buf);i++){
      if(buf[i]==c[0]){
        size++;
      }
    }
    return size;
}


int strpos(char *haystack, char *needle)
{
   char *p = strstr(haystack, needle);
   if (p)
      return p - haystack;
   return -1;   // Not found = -1.
}

char** strsplit( const char* s, const char* delim ) {
	void* data;
	char* _s = ( char* )s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while ( ( _s = strstr( _s, delim ) ) ) {
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = ( nbWords + 1 ) * sizeof( char* );
	ptrs =
	data = malloc( ptrsSize + sLen + 1 );
	if ( data ) {
		*ptrs =
		_s = strcpy( ( ( char* )data ) + ptrsSize, s );
		if ( nbWords > 1 ) {
			while ( ( _s = strstr( _s, delim ) ) ) {
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	return data;
}


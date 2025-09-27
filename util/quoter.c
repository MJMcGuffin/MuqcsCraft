/*
   gcc -o quoter quoter.c

   synopsis:
      cat inputfile | quoter > outputfile
*/

#include <stdio.h>
#include <string.h>  /* for strlen() */

#define BUFFER_SIZE 2048
char buffer[ BUFFER_SIZE + 5 ];
char buffer2[ 2*BUFFER_SIZE + 5 ];

void main() {
   int isFirstLine = 1;
   int hasNewLine = 0;
   int dosMode = 0;
   while ( NULL != fgets(buffer, BUFFER_SIZE, stdin)) {
      // I think buffer is guaranteed to end with a null byte,
      // and before that there may be \r\n or \n or not.
      int srcIndex = 0, destIndex = 0;
      if ( !isFirstLine )
         buffer2[ destIndex++ ] = '+';
      buffer2[ destIndex++ ] = '\"';
      while ( buffer[ srcIndex ] != '\0' && buffer[ srcIndex ] != '\r' && buffer[ srcIndex ] != '\n' ) {
         if ( buffer[ srcIndex ] == '\"' ) {
            buffer2[ destIndex++ ] = '\\';
            buffer2[ destIndex++ ] = '\"';
            ++srcIndex;
         }
         if ( buffer[ srcIndex ] == '\'' ) {
            buffer2[ destIndex++ ] = '\\';
            buffer2[ destIndex++ ] = '\'';
            ++srcIndex;
         }
         else {
            buffer2[ destIndex++ ] = buffer[ srcIndex++ ];
         }
      }
      if ( buffer[ srcIndex ] == '\r' )
         dosMode = 1;
      if ( buffer[ srcIndex ] == '\r' || buffer[ srcIndex ] == '\n' )
         hasNewLine = 1;
      if ( hasNewLine ) {
         buffer2[ destIndex++ ] = '\\';
         buffer2[ destIndex++ ] = 'n';
      }
      buffer2[ destIndex++ ] = '\"';
      buffer2[ destIndex ] = 0;
      if ( dosMode )
         printf( "%s\r\n", buffer2 );
      else
         printf( "%s\n", buffer2 );
      isFirstLine = 0;
   }
}


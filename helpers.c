/******************************************************************************
** Student name: 	Marco Tessari
** Student number: 	S3382522
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "helpers.h"

void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

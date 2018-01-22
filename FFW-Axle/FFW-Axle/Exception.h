#ifndef _EXCEPTION_H
#define _EXCEPTION_H
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

#define EXCEPTION_THROW 0
#define EXCEPTION_CATCH 1

#define EXCEPTION_INDEXOUTOFBOUNDS 1
#define EXCEPTION_NULLPOINTER 2

/*
	Throws an index out of bounds exception and prints out the index it is trying to get along with some additional details about the error
	@param index The index that is out of bounds
	@param additionalDetails More details about the exception
	@param catchException If 1 it will return the ID of the exception else it will close the program
	@return Returns the ID of the exception in case the exception is to be caught if asked to
*/
int throwIndexOutOfBoundsException(int index, char* additionalDetails, char catchException);

/*
	Throws a null pointer exception.
	@param additionalDetails More details about the exception
	@param catchException If 1 it will return the ID of the exception else it will close the program
*/
void throwNullPointerException(char* additionalDetails, char catchException);

/*
	Checks if a value is NULL
	@param value The value to check is NULL
	@param message The details of the error message
	@param catchExceptionIfThrown If 0 the program will exit. If 1 the function will return to allow for handling of the error
	@return Returns 1 if the exception was caught. Returns 0 if the value was not NULL
*/
int checkIfNULL(const void* value, char* message, char catchExceptionIfThrown);

#endif
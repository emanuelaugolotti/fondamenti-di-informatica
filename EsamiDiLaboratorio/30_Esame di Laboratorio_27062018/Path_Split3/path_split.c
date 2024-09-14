#define _CRT_SECURE_NO_WARNINGS
#include "path_split.h"

void path_split(const char* str, char** path, char** filename)
{
	if (str == NULL || path == NULL || filename == NULL) {
		*path = NULL;        //path[0] = NULL;
		*filename = NULL;   //path[0] = NULL;
		return;
	}
	size_t lenTot = strlen(str);

	if (lenTot == 0) {  //Stringa vuota
		*filename = calloc(1, 1);
		*path = calloc(1, 1);
		return;
	}

	char* trovato;
	trovato = strrchr(str, '\\');

	if (trovato == NULL) {  //Nella stringa non c'è nessun "\\"
		*filename = calloc(1, 1);
		*path = calloc(lenTot + 1, 1);
		strcpy(*path, str);
		return;
	}

	size_t lenFilename = strlen(trovato + 1);
	*filename = calloc(lenFilename + 1, 1);    //filename[0] = calloc(lenFilename + 1, 1);
	strcpy(*filename, trovato + 1);            //strcpy(filename[0], trovato + 1);

	size_t lenPath = lenTot - lenFilename;
	*path = calloc(lenPath + 1, 1);
	strncpy(*path, str, lenPath);

	return;
}
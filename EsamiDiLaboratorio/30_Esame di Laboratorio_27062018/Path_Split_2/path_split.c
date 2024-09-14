#define _CRT_SECURE_NO_WARNINGS
#include "path_split.h"

void path_split(const char* str, char** path, char** filename)
{
	if (str == NULL || path == NULL || filename == NULL) {
		path[0] = NULL;
		filename[0] = NULL;
		return;
	}
	char* outFilename;
	char* outPath;
	size_t lenTot = strlen(str);

	if (lenTot == 0) {  //Stringa vuota
		outFilename = calloc(1, 1);
		outPath = calloc(1, 1);
		path[0] = outPath;
		filename[0] = outFilename;
		return;
	}

	char* trovato;
	trovato = strrchr(str, '\\');

	if (trovato == NULL) {  //Nella stringa non c'è nessun "\\"
		outFilename = calloc(1, 1);
		outPath = calloc(lenTot + 1, 1);
		strcpy(outPath, str);
		path[0] = outPath;
		filename[0] = outFilename;
		return;
	}

	size_t lenFilename = strlen(trovato + 1);
	outFilename = calloc(lenFilename + 1, 1);
	strcpy(outFilename, trovato + 1);

	size_t lenPath = lenTot - lenFilename;
	outPath = calloc(lenPath + 1, 1);
	strncpy(outPath, str, lenPath);

	path[0] = outPath;
	filename[0] = outFilename;
	return;
}
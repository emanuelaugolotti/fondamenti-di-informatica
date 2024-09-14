#include "scacchiera.h"

int main(void)
{
	struct scacchiera s = { {
'R','P',' ',' ',' ',' ','p','r',

'N','P',' ',' ',' ',' ','p','n',

' ','P',' ',' ',' ',' ','Q',' ',

'K',' ',' ','P','p',' ',' ','k',

' ','P',' ',' ',' ',' ','p','q',

'B','P',' ','B','b','n','p','b',

'N','P',' ',' ',' ',' ','p',' ',

'R','P',' ',' ',' ',' ','p','r' } };
	
	stampa_scacchiera(&s);
	return 0;
}
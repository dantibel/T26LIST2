/* Belov Danil, 10-6, 15.11.2021 */

#ifndef __LIST_H_
#define __LIST_H_

#define VOID void

/* Debug memory allocation support */
#ifndef _NDEBUG
#  define _CRTDBG_MAP_ALLOC
#  include <crtdbg.h>
#  define SetDbgMemHooks() \
     _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
       _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else /* _DEBUG */
#  define SetDbgMemHooks() ((void)0)
#endif /* _DEBUG */

#include <stdlib.h>

#include <commondf.h>

#define STR_MAX 100

/* double-linked list type representation */
typedef struct tagLIST LIST;
struct tagLIST
{
  CHAR Str[STR_MAX];
  LIST *Next, *Prev;
};

VOID Display( LIST *L );
VOID GetStr( CHAR *S, INT Len );

/* edit list functions */
BOOL AddFirst( LIST **L, CHAR *NewStr );
BOOL AddLast( LIST **L, CHAR *NewStr );
BOOL DelFirst( LIST **L, CHAR *Str );
BOOL DelLast( LIST **L, CHAR *Str );
BOOL ShiftNext( LIST **L );
BOOL ShiftPrev( LIST **L );
BOOL AddCurrent( LIST **L, CHAR *NewStr );
BOOL DelCurrent( LIST **L, CHAR *Str );
VOID ClearList( LIST **L );
#endif
/* END OF 'LIST2.H' FILE */
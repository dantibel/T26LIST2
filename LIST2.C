/* Belov Danil, 10-6, 10.11.2021 */

#include <stdio.h>
#include <string.h>

#include "list2.h"

/* Print list function */
VOID Display( LIST *L )
{
  LIST *save;

  printf("\n");
  if (L == NULL)
    printf("List is empty\n");
  else
  {
    save = L;
    while (L != NULL && L->Prev != NULL)
      L = L->Prev;
    
    while (L != NULL)
    {
      printf("%s%s", L->Str, L == save ? "(*)" : "");
      printf("%s", (L = L->Next) == NULL ? "\n" : ", ");
    }
    printf("\n");
  }
} /* End of 'Display' function */


/* Input string function */
VOID GetStr( CHAR *S, INT Len )
{
  INT i = 0;
  CHAR c;

  while ((c = getchar()) != '\n')
    if (S != NULL && i < Len - 1)
      S[i++] = c;
  if (S != NULL && i < Len)
    S[i] = 0;
} /* End of 'GetStr' function */


/* Add new element to begin of the list function */
BOOL AddFirst( LIST **L, CHAR *NewStr )
{
  LIST *next = NULL;

  while (*L != NULL)
  {
    next = *L;
    L = &(*L)->Prev;
  }

  if ((*L = malloc(sizeof(LIST))) == NULL)
    return FALSE;

  (*L)->Next = next;
  (*L)->Prev = NULL;
  strncpy((*L)->Str, NewStr, STR_MAX - 1);
  return TRUE;
} /* End of 'AddFirst' function */


/* Add new element to end of the list function */
BOOL AddLast( LIST **L, CHAR *NewStr )
{
  LIST *prev = NULL;

  while (*L != NULL)
  {
    prev = *L;
    L = &(*L)->Next;
  }

  if ((*L = malloc(sizeof(LIST))) == NULL)
    return FALSE;

  (*L)->Next = NULL;
  (*L)->Prev = prev;
  strncpy((*L)->Str, NewStr, STR_MAX - 1);
  return TRUE;
} /* End of 'AddLast' function */


/* Delete element from begin of the list function */
BOOL DelFirst( LIST **L, CHAR *Str )
{
  LIST *old = NULL;

  if (*L == NULL)
    return FALSE;

  while ((*L)->Prev != NULL)
    L = &(*L)->Prev;

  if (Str != NULL)
    strncpy(Str, (*L)->Str, STR_MAX - 1);
  old = (*L)->Next;
  free(*L);
  *L = old;
  if (*L != NULL)
    (*L)->Prev = NULL;
  return TRUE;
} /* End of 'DelFirst' function */


/* Delete element from end of the list function */
BOOL DelLast( LIST **L, CHAR *Str )
{
  LIST *old = NULL;
 
  if (*L == NULL)
    return FALSE;

  while ((*L)->Next != NULL)
    L = &(*L)->Next;
  old = *L;

  if (Str != NULL)
    strncpy(Str, old->Str, STR_MAX - 1);

  old->Prev->Next = NULL;
  free(old);
  *L = NULL;
  return TRUE;
} /* End of 'DelLast' function */


/* Shift active element function */
BOOL ShiftNext( LIST **L )
{
  if (*L != NULL && (*L)->Next != NULL)
  {
    *L = (*L)->Next;
    return TRUE;
  }
  return FALSE;
} /* End of 'ShiftNext' function */


/* Shift active element function */
BOOL ShiftPrev( LIST **L )
{
  if (*L != NULL && (*L)->Prev != NULL)
  {
    *L = (*L)->Prev;
    return TRUE;
  }
  return FALSE;
} /* End of 'ShiftPrev' function */


BOOL AddCurrent( LIST **L, CHAR *NewStr )
{
  LIST *current, *next = NULL;

  if (*L == NULL)
    return FALSE;

  current = *L, next = current->Next;

  if ((*L = malloc(sizeof(LIST))) == NULL)
    return FALSE;

  strncpy(current->Str, NewStr, STR_MAX - 1);
  next->Prev = *L;
  (*L)->Next = next;
  current->Next = *L;
  (*L)->Prev = current;
  return TRUE;
} /* End of 'AddCurrent' function */


/* Delete element from current position function */
BOOL DelCurrent( LIST **L, CHAR *Str )
{
  LIST *current = NULL, *old = NULL;

  if (*L == NULL)
    return FALSE;

  current = *L;

  if (Str != NULL)
    strncpy(Str, current->Str, STR_MAX - 1);

  if ((*L)->Prev != NULL)
  {
   (*L)->Prev->Next = (*L)->Next;
   if ((*L)->Next != NULL)
     (*L)->Next->Prev = (*L)->Prev;
   old = (*L)->Prev;
  }
  else
  {
    *L = (*L)->Next;
    (*L)->Prev = NULL;
    old = *L;
  }

  free(current);
  *L = old;
  return TRUE;
} /* End of 'DelCurrent' function */


/* Clear list function */
VOID ClearList( LIST **L )
{
  while ((*L) != NULL && (*L)->Prev != NULL)
    *L = (*L)->Prev;
  
  while (*L != NULL)
  {
    LIST *old = *L;

    *L = (*L)->Next;
    free(old);
  }
} /* End of 'ClearList' function */
/* END OF 'LIST2.C' FILE */
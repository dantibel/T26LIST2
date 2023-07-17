/* Belov Danil, 10-6, 10.11.2021 */

#include <stdio.h>
#include <conio.h>

#include "list2.h"

/* Program main function */
VOID main( VOID )
{
  BOOL run = TRUE, first = TRUE;
  CHAR Str[STR_MAX];
  LIST *Start = NULL;

  SetDbgMemHooks();
  while (run)
  {
    printf("\n========================================================================================  \n"
      " 0 - exit        | 1 - add first   | 2 - add last    | 3 - del first   | 4 - del last       \n"
      " 5 - shift prev  | 6 - shift next  | 7 - add current | 8 - del current | 9 - clear list\n"
      "========================================================================================\n\n");
    if(!first)
      Display(Start);
    else
      first = FALSE;
    switch (_getch())
    {
    /* exit */
    case '0':
      run = FALSE;
      break;
    /* add new string to begin */
    case '1':
      printf("String: ");
      GetStr(Str, STR_MAX);

      if (AddFirst(&Start, Str))
        printf("SUCCESS (1)\n");
      else 
        printf("FAIL (1)\n");
      break;
    /* add new string to end */
    case '2':
      printf("String: ");
      GetStr(Str, STR_MAX);

      if (AddLast(&Start, Str))
        printf("SUCCESS (2)\n");
      else 
        printf("FAIL (2)\n");
      break;
    /* delete string from begin */
    case '3':
      if (DelFirst(&Start, Str))
        printf("SUCCESS (3)\n");
      else 
        printf("FAIL (3)\n");
      break;
    /* delete string from end */
    case '4':
      if (DelLast(&Start, Str))
        printf("SUCCESS (4)\n");
      else 
        printf("FAIL (4)\n");
      break;
    case '5':
      if (ShiftPrev(&Start))
      break;
    case '6':
      if (ShiftNext(&Start))
      break;
    case '7':
      printf("String: ");
      GetStr(Str, STR_MAX);

      if (!AddCurrent(&Start, Str))
        AddFirst(&Start, Str);
      break;
    case '8':
      if (!DelCurrent(&Start, Str))
        printf("FAIL (8)\n");
      break;
    case '9':
      ClearList(&Start);
      break;
    }
  }
  ClearList(&Start);
} /* End of program main fucnction */
/* END OF 'T26LIST.C' FILE */
/*
 Title:		progress.c
 Author:	Badre
 Created:	23/02/2024 
 Last Updated: 20/03/2024

 Modinfo: 
 23/03/2024		Update DoProgress
 				      Changed chat to uint8_t 
*/
#include <stdio.h>
#include <string.h>
#include "agon_timer.h"
#include "progress.h"
#include "conio_agon.h"

void progressBar(int x, int y, int pmax, char* title, char sep)
{
  cursorEnable(false);
  textattr(BLACK, BRIGHT_GREEN);
  gotoxy(x, y);
  printf( "%s\r\n", title);
  for (int i = 0; i < pmax; i++) {
    printf("%c", sep);
    delayms(50);
  }

  crlf();
  cursorEnable(true);
}

void loadingPercent(int x, int y, int pmax, char* title)
{
  cursorEnable(false);
  textattr(BLACK, BRIGHT_GREEN);
  gotoxy(x, y);
  clreol();
  gotoxy(x, y);
  printf( "%s\r\n", title);
  clreol();  
  for (int i = 0; i <= pmax; i++) {
    gotoxy(x+1, y);
    printf("%d%%", i);
    clreol();   
    delayms(50);
  }
   crlf();
  cursorEnable(true);
}

void loadingSpinner(int x, int y, int pmax, char* title)
{
  static char bars[] = { '/', '-', '\\', '|' }; 
  static int pos = 0;

  cursorEnable(false);
  textattr(BLACK, BRIGHT_GREEN);
  gotoxy(x, y);
  clreol();
  printf( "%s\r\n", title);
  clreol();
  for (int i = 0; i <= pmax; i++) {
    if (pos > 3) pos = 0;
    printf("%c\r", bars[pos]);
    pos++;
    delayms(50);
  }
  //printf("%%\r");
  //clreol();
  crlf();
  cursorEnable(true);
}

void DoProgress(const char * label, int step, int total, uint8_t sep )
{
  //progress width
  const int pwidth = 50;

  //minus label len
  int width = pwidth - strlen( label );
  int pos = ( step * width ) / total ;

  int percent = ( step * 100 ) / total;

  printf( "%s %3d%% [", label, percent );

  //fill progress bar with =
  for ( int i = 0; i < pos; i++ )  printf( "%c", sep );

  //fill progress bar with spaces
  printf( "%*c", width - pos + 1, ']');
  //Terminal.printf( " %3d%% [%d/%d]\r", percent, step, total);
  printf(" [%d/%d]\r", step, total);
}

/*void DoSome()
{
  int total = 200;
  int step = 0;

  _cursoroff();
  _textattr(Color::Black, Color::BrightGreen);
  _clreol();
  _gotoxy(1, 2);

  xprintf( "Files : %d\r\n", total);
  while ( step < total )
  {
    //do some action
    delay(10);
    step += 1;
    DoProgress( "Progress:", step, total, '#' );
  }

   _crlf();
   _crlf();
  _cursoron();
}*/

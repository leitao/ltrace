/* Ltrace Test : parameters.c.
   Objectives  : Verify that Ltrace can handle all the different
   parameter types

   This file was written by Steve Fink <sphink@gmail.com>. */

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void func_ignore(int a, int b, int c);
void func_intptr(int *i);
void func_intptr_ret(int *i);
int func_strlen(char*);
void func_strfixed(char*);
void func_ppp(int***);
void func_stringp(char**);
void func_short(short, short);
void func_ushort(unsigned short, unsigned short);
void func_float(float, float);

typedef enum {
  RED,
  GREEN,
  BLUE,
  CHARTREUSE,
  PETUNIA
} color_t;
void func_enum(color_t);
void func_typedef(color_t);

int 
main ()
{
  int x = 17;
  int *xP, **xPP;
  char buf[200];
  char *s;

  func_ignore(1, 2, 3);

  func_intptr(&x);

  func_intptr_ret(&x);

  func_strlen(buf);
  printf("%s\n", buf);

  func_strfixed(buf);
  printf("%s\n", buf);

  x = 80;
  xP = &x;
  xPP = &xP;
  func_ppp(&xPP);

  s = (char*) malloc(100);
  strcpy(s, "Dude");
  func_stringp(&s);

  func_enum(BLUE);

  func_short(-8, -9);
  func_ushort(33, 34);
  func_float(3.4, -3.4);

  func_typedef(BLUE);

  return 0;
}

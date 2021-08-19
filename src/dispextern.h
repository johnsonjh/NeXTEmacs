/* Interface definitions for display code.
   Copyright (C) 1985 Free Software Foundation, Inc.

This file is part of GNU Emacs.

GNU Emacs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.  No author or distributor
accepts responsibility to anyone for the consequences of using it
or for whether it serves any particular purpose or works at all,
unless he says so in writing.  Refer to the GNU Emacs General Public
License for full details.

Everyone is granted permission to copy, modify and redistribute
GNU Emacs, but only under the conditions described in the
GNU Emacs General Public License.   A copy of this license is
supposed to have been given to you along with GNU Emacs so you
can know your rights and responsibilities.  It should be in a
file named COPYING.  Among other things, the copyright notice
and this notice must be preserved on all copies.  */


/* Nonzero means do not assume anything about current
 contents of actual terminal screen */

extern int screen_garbaged;

/* Desired terminal cursor position (to show position of point),
 origin zero.  */

extern int cursor_hpos, cursor_vpos;

/* Nonzero means last display completed
   and cursor is really at cursor_hpos, cursor_vpos.
   Zero means it was preempted. */

extern int display_completed;

struct matrix
{
  /* Height of this matrix.  */
  int height;
  /* Width of this matrix.  */
  int width;
  /* Vector of used widths of lines, indexed by vertical position.  */
  int *used;
  /* Vector of line contents.
     m->contents[V][H] is the character at position V, H.
     Note that ->contents[...][screen_width] is always 0
     and so is ->contents[...][-1].  */
  unsigned char **contents;
  /* Long vector from which the line contents are taken.  */
  unsigned char *total_contents;
  /* Vector indicating, for each line, whether it is highlighted.  */
  char *highlight;
  /* Vector indicating, for each line, whether its contents mean anything.  */
  char *enable;
};

/* Current screen contents.  */
extern struct matrix *current_screen;
/* Screen contents to be displayed.  */
extern struct matrix *new_screen;
/* Temporary buffer for screen contents.  */
extern struct matrix *temp_screen;

/* Get ready to display on screen line VPOS at column HPOS
   and return the string where the text of that line is stored.  */

unsigned char *get_display_line ();

/* Buffer used by `message' for formatting a message, and by print.c.  */
extern char *message_buf;

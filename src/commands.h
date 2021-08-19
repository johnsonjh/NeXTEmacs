/* Definitions needed by most editing commands.
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


#define Ctl(c) ((c)&037)

/* Define the names of keymaps, just so people can refer to them in calls to defkey */

extern Lisp_Object Vglobal_map;

extern Lisp_Object Vesc_map;

extern Lisp_Object Vctl_x_map;

extern Lisp_Object Vminibuffer_local_map;

extern Lisp_Object Vminibuffer_local_ns_map;

/* keymap used for minibuffers when doing completion */
extern Lisp_Object Vminibuffer_local_completion_map;

/* keymap used for minibuffers when doing completion and require a match */
extern Lisp_Object Vminibuffer_local_must_match_map;

/* Last character of last key sequence.  */
extern int last_command_char;

/* Command character to be re-read, or -1 */
extern int unread_command_char;

/* Previous command symbol found here for comparison */
extern Lisp_Object last_command;

/* Nonzero means ^G can quit instantly */
extern int immediate_quit;

extern Lisp_Object Vexecuting_macro;

/* Nonzero if input is coming from the keyboard */
#define FROM_KBD (NULL (Vexecuting_macro) && !noninteractive)

/* Set this nonzero to force reconsideration of mode line. */

extern int update_mode_lines;

/* Nonzero means reading single-character input with prompt
   so put cursor on minibuffer after the prompt.  */

extern int cursor_in_echo_area;

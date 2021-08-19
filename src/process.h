/* Definitions for asynchronous process control in GNU Emacs.
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


/*
 * Structure records pertinent information about open channels.
 * There is one channel associated with each process.
 */

struct Lisp_Process
  {
    int size;
    struct Lisp_Vector *v_next;
    /* Descriptor by which we read from this process */
    Lisp_Object infd;
    /* Descriptor by which we write to this process */
    Lisp_Object outfd;
    /* Name of this process */
    Lisp_Object name;
    /* List of command arguments that this process was run with */
    Lisp_Object command;
    /* (funcall FILTER PROC STRING)  (if FILTER is non-nil)
       to dispose of a bunch of chars from the process all at once */
    Lisp_Object filter;
    /* (funcall SENTINEL PROCESS) when process state changes */
    Lisp_Object sentinel;
    /* Buffer that output is going to */
    Lisp_Object buffer;
    /* Number of this process */
    Lisp_Object pid;
    /* Non-nil if this is really a command channel */
    Lisp_Object command_channel_p;
    /* Non-nil if this is really a child process */
    Lisp_Object childp;
    /* Marker set to end of last buffer-inserted output from this process */
    Lisp_Object mark;
    /* Non-nil means kill silently if Emacs is exited.  */
    Lisp_Object kill_without_query;
    /* Symbol indicating status of process.
       This may be a symbol: run, open, or closed.
       Or it may be a list, whose car is stop, exit or signal
       and whose cdr is a pair (EXIT_CODE . COREDUMP_FLAG)
       or (SIGNAL_NUMBER . COREDUMP_FLAG).  */
    Lisp_Object status;
    /* Non-nil if communicating through a pty.  */
    Lisp_Object pty_flag;
    /* Event-count of last event in which this process changed status.  */
    Lisp_Object tick;
    /* Event-count of last such event reported.  */
    Lisp_Object update_tick;
};

#define ChannelMask(n) (1<<(n))

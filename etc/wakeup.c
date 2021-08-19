/* Program to produce output at regular intervals.  */

#include <stdio.h>

main (argc, argv)
     int argc;
     char **argv;
{
  int period = 60;

  if (argc > 1)
    period = atoi (argv[1]);

  while (1)
    {
      printf ("Wake up!\n");
      fflush (stdout);
      sleep (period);
    }
}

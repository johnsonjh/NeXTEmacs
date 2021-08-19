# 1 "server.c"
 



















 






# 1 "../src/config.h" 1
 





















 



# 1 "../src/s-mach.h" 1
 




















# 1 "../src/s-bsd4-3.h" 1
 




















 












 




 



 

 




 


 





 
 





 





 



 




 

 



 







 


 

 






 





 



 



 



# 22 "../src/s-mach.h" 2




# 27 "../src/config.h" 2


 




# 1 "../src/m-NeXT.h" 1
 
 
























 








 



 




 





 



 





 



 











 





 
 

 


 









# 34 "../src/config.h" 2


 










 

 

 


 

 



 

 











 











 


 

 



 



 










 





 

# 28 "server.c" 2







# 45 "server.c"



 

# 1 "/usr/include/sys/file.h" 1
 





 








 
 







 
# 1 "/usr/include/sys/fcntl.h" 1
 
 















 


















 






 

 


 











 





 
 





 





 
struct flock {
        short   l_type;		 
        short   l_whence;	 
        long    l_start;	 
        long    l_len;           
        short   l_pid;		 
        short   l_xxx;		 
};


# 26 "/usr/include/sys/file.h" 2






# 1 "/usr/include/kern/queue.h" 1
 







 

















































 








# 1 "/usr/include/machine/vm_types.h" 1
 

 






typedef	unsigned int	vm_offset_t;
typedef	unsigned int	vm_size_t;



# 68 "/usr/include/kern/queue.h" 2

# 1 "/usr/include/kern/lock.h" 1
 







 

















































































 



















# 1 "/usr/include/sys/boolean.h" 1
 





 













 




# 1 "/usr/include/machine/boolean.h" 1
 

 

 









typedef unsigned int		boolean_t;


# 26 "/usr/include/sys/boolean.h" 2





 

















# 111 "/usr/include/kern/lock.h" 2






 



struct slock {
	int		lock_data;	 
};

typedef struct slock	simple_lock_data_t;
typedef struct slock	*simple_lock_t;


extern simple_lock_t	simple_lock_alloc();
extern void		simple_lock_free();

# 140 "/usr/include/kern/lock.h"

 
















 









struct lock {
# 179 "/usr/include/kern/lock.h"

# 196 "/usr/include/kern/lock.h"

	 



	boolean_t	want_write;	 
	boolean_t	want_upgrade;	 
	boolean_t	waiting;	 
	boolean_t	can_sleep;	 
	int		read_count;	 


	char		*thread;
		 
		 

	int		recursion_depth; 


	 



	 simple_lock_data_t interlock; 

};

typedef struct lock	lock_data_t;
typedef struct lock	*lock_t;

 


extern lock_t		lock_alloc();
extern void		lock_free();

extern void		lock_init();
extern void		lock_sleepable();
extern void		lock_write();
extern void		lock_read();
extern void		lock_done();
extern boolean_t	lock_read_to_write();
extern void		lock_write_to_read();
extern boolean_t	lock_try_write();
extern boolean_t	lock_try_read();
extern boolean_t	lock_try_read_to_write();




extern void		lock_set_recursive();
extern void		lock_clear_recursive();






# 69 "/usr/include/kern/queue.h" 2

# 1 "/usr/include/kern/macro_help.h" 1
 






 






















 


























# 70 "/usr/include/kern/queue.h" 2


 


















 



struct queue_entry {
	struct queue_entry	*next;		 
	struct queue_entry	*prev;		 
};

typedef struct queue_entry	*queue_t;
typedef	struct queue_entry	queue_head_t;
typedef	struct queue_entry	queue_chain_t;
typedef	struct queue_entry	*queue_entry_t;

 




















 









 









 







 










 









# 192 "/usr/include/kern/queue.h"

 








 






# 218 "/usr/include/kern/queue.h"

 





















 









# 268 "/usr/include/kern/queue.h"

 









 







 


struct mpqueue_head {
	struct queue_entry	head;		 
	struct slock		lock;		 
};

typedef struct mpqueue_head	mpqueue_head_t;

















# 321 "/usr/include/kern/queue.h"






# 32 "/usr/include/sys/file.h" 2


 



struct	file {
	queue_chain_t	links;	 
	int	f_flag;		 
	short	f_type;		 
	short	f_count;	 
	short	f_msgcount;	 
	struct	fileops {
		int	(*fo_rw)();
		int	(*fo_ioctl)();
		int	(*fo_select)();
		int	(*fo_close)();
	} *f_ops;
	caddr_t	f_data;      
	off_t	f_offset;
 	struct	ucred *f_cred;	 
};

queue_head_t	file_list;
struct	file *getf();
struct	file *falloc();


 










 



 




 







 






























# 50 "server.c" 2

# 1 "/usr/include/sys/types.h" 1
 





 













































 









 



 


 


 


typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
typedef	unsigned short	ushort;		 














typedef struct  _physadr { short r[1]; } *physadr;
typedef struct  label_t {
        int     val[13];
} label_t;




typedef	struct	_quad { long val[2]; } quad;

typedef	long	daddr_t;
typedef	char *	caddr_t;
typedef	u_long	ino_t;





typedef unsigned long size_t;




typedef	long	time_t;

typedef	short	dev_t;



typedef	long	off_t;

typedef	short	uid_t;
typedef	short	gid_t;


 









typedef long	fd_mask;





typedef	struct fd_set {
	fd_mask	fds_bits[(((256 )+(( (sizeof(fd_mask) * 8		)	)-1))/( (sizeof(fd_mask) * 8		)	)) ];
} fd_set;









# 51 "server.c" 2

# 1 "/usr/include/sys/socket.h" 1
 







 










































 







 








 








 














 











 


struct	linger {
	int	l_onoff;		 
	int	l_linger;		 
};

 




 






















 



struct sockaddr {
	u_short	sa_family;		 
	char	sa_data[14];		 
};

 



struct sockproto {
	u_short	sp_family;		 
	u_short	sp_protocol;		 
};

 






















 




 


struct msghdr {
	caddr_t	msg_name;		 
	int	msg_namelen;		 
	struct	iovec *msg_iov;		 
	int	msg_iovlen;		 
	caddr_t	msg_accrights;		 
	int	msg_accrightslen;
};








extern int accept(int, struct sockaddr *, int *);
extern int bind(int, struct sockaddr *, int);
extern int connect(int, struct sockaddr *, int);
extern int getpeername(int, struct sockaddr *, int *);
extern int getsockname(int, struct sockaddr *, int *);
extern int getsockopt(int, int, int, void *optval, int *);
extern int setsockopt(int, int, int, void *optval, int);
extern int listen(int, int);
extern int recv(int, void *, int, int);
extern int recvfrom(int, void *, int, int, struct sockaddr *, int *);
extern int recvmsg(int, struct msghdr *, int);
extern int send(int, void *, int, int);
extern int sendto(int, void *, int, int, struct sockaddr *, int);
extern int sendmsg(int, struct msghdr *, int);
extern int socket(int, int, int);
extern int socketpair(int, int, int, int *);




# 52 "server.c" 2

# 1 "/usr/include/sys/signal.h" 1
 





 






 







# 1 "/usr/include/machine/signal.h" 1
 













 






struct	sigcontext {
	int	sc_onstack;		 
	int	sc_mask;		 
	int	sc_sp;			 
	int	sc_pc;			 
	int	sc_ps;			 
	int	sc_d0;			 
};



# 22 "/usr/include/sys/signal.h" 2









 


























 

 


 







 



struct	sigvec {
	void	(*sv_handler)();	 
	int	sv_mask;		 
	int	sv_flags;		 
};





 



struct	sigstack {
	char	*ss_sp;			 
	int	ss_onstack;		 
};


# 105 "/usr/include/sys/signal.h"














 
extern int sigblock(int);
extern int sigpause(int);
extern int sigreturn(struct sigcontext *);
extern int sigsetmask(int);
extern int sigstack(struct sigstack *, struct sigstack *);
extern int sigvec(int, struct sigvec *, struct sigvec *);
 
extern int siginterrupt(int, int);



extern void (*signal(int, void (*)(int)))(int);




 













# 53 "server.c" 2

# 1 "/usr/include/sys/un.h" 1
 





 









 










 


struct	sockaddr_un {
	short	sun_family;		 
	char	sun_path[108];		 
};





# 54 "server.c" 2

# 1 "/usr/include/stdio.h" 1
 















# 1 "/usr/include/stddef.h" 1
 








typedef long ptrdiff_t;




typedef unsigned short wchar_t;




extern int errno;



# 17 "/usr/include/stdio.h" 2

# 1 "/usr/include/stdarg.h" 1



 


typedef char *va_list;

 








void va_end (va_list);		 









# 18 "/usr/include/stdio.h" 2




extern	struct	_iobuf {
	int	_cnt;
	char	*_ptr;		 
	char	*_base;		 
	int	_bufsiz;
	short	_flag;
	char	_file;		 
	char	_smallbuf;	 
} _iob[];

















# 58 "/usr/include/stdio.h"

typedef long fpos_t;










extern int remove(const char *filename);
extern int rename(const char *old, const char *new);
extern struct _iobuf  *tmpfile(void);
extern char *tmpnam(char *s);
extern int fclose(struct _iobuf  *stream);
extern int fflush(struct _iobuf  *stream);
extern void setbuf(struct _iobuf  *stream, char *buf);
extern int setvbuf(struct _iobuf  *stream, char *buf, int mode, size_t size);
extern int fprintf(struct _iobuf  *stream, const char *format, ...);
extern int fscanf(struct _iobuf  *stream, const char *format, ...);
extern int printf(const char *format, ...);
extern int scanf(const char *format, ...);
extern int sprintf(char *s, const char *format, ...);
extern int sscanf(const char *s, const char *format, ...);
extern int vfprintf(struct _iobuf  *stream, const char *format, va_list arg);
extern int vprintf(const char *format, va_list arg);
extern int vsprintf(char *s, const char *format, va_list arg);
extern int fgetc(struct _iobuf  *stream);
extern int fputc(int c, struct _iobuf  *stream);
extern int fputs(const char *s, struct _iobuf  *stream);
extern int getc(struct _iobuf  *stream);
extern int _flsbuf();
extern int _filbuf();
extern int getchar(void);
extern int putc(int c, struct _iobuf  *stream);
extern int putchar(int c);
extern int puts(const char *s);
extern int ungetc(int c, struct _iobuf  *stream);
extern size_t fread(void *ptr, size_t size, size_t nmemb, struct _iobuf  *stream);
extern size_t fwrite(const void *ptr, size_t size, size_t nmemb, struct _iobuf  *stream);
extern int fgetpos(struct _iobuf  *stream, fpos_t *pos);
extern int fseek(struct _iobuf  *stream, long int offset, int whence);
extern int fsetpos(struct _iobuf  *stream, const fpos_t *pos);
extern void rewind(struct _iobuf  *stream);
extern void clearerr(struct _iobuf  *stream);
extern int feof(struct _iobuf  *stream);
extern int ferror(struct _iobuf  *stream);
extern void perror(const char *s);
extern struct _iobuf  *fopen(const char *filename, const char *mode);
extern struct _iobuf  *freopen(const char *filename, const char *mode, struct _iobuf  *stream);
extern long int ftell(struct _iobuf  *stream);
extern char *fgets(char *s, int n, struct _iobuf  *stream);
extern char *gets(char *s);





















 
extern int fileno(struct _iobuf  *stream);







struct _iobuf 	*fdopen(int filedes, const char *mode);
struct _iobuf 	*popen(const char *command, const char *mode);
extern int pclose(struct _iobuf  *stream);



# 55 "server.c" 2

# 1 "/usr/include/errno.h" 1
# 1 "/usr/include/sys/errno.h" 1
 





 
 







 




 




































 



 




 

	 













	 













	 



 




 




 
 


 

 
 


 

 




 








extern void perror(const char *);
extern char *sys_errlist[];
extern int sys_nerr;



# 1 "/usr/include/errno.h" 2



extern int errno;

# 56 "server.c" 2


extern int errno;

main ()
{
  int s, infd, fromlen;
  struct sockaddr_un server, fromunix;
  char *homedir;
  char *str, string[1024 ], code[1024 ];
  struct _iobuf  *infile;
  struct _iobuf  **openfiles;
  int openfiles_size;

  char *getenv ();

  openfiles_size = 20;
  openfiles = (struct _iobuf  **) malloc (openfiles_size * sizeof (struct _iobuf  *));
  if (openfiles == 0)
    abort ();

   



  if ((s = socket (	1		, 1		, 0)) < 0)
    {
      perror ("socket");
      exit (1);
    }
  server.sun_family = 	1		;
  if ((homedir = getenv ("HOME")) == ((void *)0) )
    {
      fprintf ((&_iob[2]) ,"No home directory\n");
      exit (1);
    }
  strcpy (server.sun_path, homedir);
  strcat (server.sun_path, "/.emacs_server");
  if (bind (s, &server, strlen (server.sun_path) + 2) < 0)
    {
      perror ("bind");
      exit (1);
    }
   


  if (listen (s, 5) < 0)
    {
      perror ("listen");
      exit (1);
    }

   
  signal (13	, 	(void (*)())1 );
  for (;;)
    {
      int rmask = (1 << s) + 1;
      if (select (s + 1, &rmask, 0, 0, 0) < 0)
	perror ("select");
      if (rmask & (1 << s))	 
	{
	  fromlen = sizeof (fromunix);
	  fromunix.sun_family = 	1		;
	  infd = accept (s, &fromunix, &fromlen);  
	  if (infd < 0)
	    {
	      if (errno == 	24		 || errno == 	23		)
		printf ("Too many clients.\n");
	      else
		perror ("accept");
	      continue;
	    }

	  if (infd >= openfiles_size)
	    {
	      openfiles_size *= 2;
	      openfiles = (struct _iobuf  **) realloc (openfiles,
					     openfiles_size * sizeof (struct _iobuf  *));
	      if (openfiles == 0)
		abort ();
	    }

	  infile = fdopen (infd, "r+");  
	  if (infile == ((void *)0) )
	    {
	      printf ("Too many clients.\n");
	      write (infd, "Too many clients.\n", 18);
	      close (infd);		 
	      continue;
	    }
	  str = fgets (string, 1024 , infile);
	  if (str == ((void *)0) )
	    {
	      perror ("fgets");
	      close (infd);		 
	      continue;
	    }
	  openfiles[infd] = infile;
	  printf ("Client: %d %s", infd, string);
	   


	  while (string[strlen (string) - 1] != '\n')
	    {
	      if (fgets (string, 1024 , infile) == 0)
		break;
	      printf ("%s", string);
	    }
	  fflush ((&_iob[1]) );
	  fflush (infile);
	  continue;
	}
      else if (rmask & 1)  
	{
	   
	  scanf ("%s %d%*c", code, &infd);

	   
	  infile = openfiles[infd];
	  while (1)
	    {
	      if (fgets (string, 1024 , (&_iob[0]) ) == 0)
		break;
	      fprintf (infile, "%s", string);
	      if (string[strlen (string) - 1] == '\n')
		break;
	    }
	  fflush (infile);

	   
	  if (strncmp (code, "Close:", 6) == 0) 
	    if (infd > 2) 
	      {
		fclose (infile);
		close (infd);
	      }
	  continue;
	} 
    }
}

# 299 "server.c"






LIBDIR = /usr/lib/emacs
BINDIR = /usr/bin

installsrc:
	tar cf - . | (cd $(SRCROOT); tar xfBp - )

clean:
	(cd etc; make clean)
	(cd src; make clean)

install: all
	-rm -rf $(DSTROOT)$(LIBDIR)
	mkdirs $(DSTROOT)$(LIBDIR)
#	(cd $(DSTROOT)$(LIBDIR); mkdirs etc info lisp man)
	(cd $(DSTROOT)$(LIBDIR); mkdirs etc info lisp; mkdirs -m 777 lock)
# We don't have room for this.  Only snag the binaries (and strip them).
#	cp etc/* $(DSTROOT)$(LIBDIR)/etc
#	-rm -f $(DSTROOT)$(LIBDIR)/etc/*.c
	cp etc/DOC-* $(DSTROOT)$(LIBDIR)/etc
	install -c -s -m 755 etc/ctags $(DSTROOT)$(LIBDIR)/etc/ctags
	install -c -s -m 755 etc/cvtmail $(DSTROOT)$(LIBDIR)/etc/cvtmail
	install -c -s -m 755 etc/digest-doc $(DSTROOT)$(LIBDIR)/etc/digest-doc
	install -c -s -m 755 etc/emacsclient $(DSTROOT)$(LIBDIR)/etc/emacsclient
	install -c -s -m 755 etc/env $(DSTROOT)$(LIBDIR)/etc/env
	install -c -s -m 755 etc/fakemail $(DSTROOT)$(LIBDIR)/etc/fakemail
	install -c -s -m 755 etc/loadst $(DSTROOT)$(LIBDIR)/etc/loadst
	install -c -s -m 755 etc/make-docfile $(DSTROOT)$(LIBDIR)/etc/make-docfile
	install -c -s -m 755 etc/movemail $(DSTROOT)$(LIBDIR)/etc/movemail
	install -c -s -m 755 etc/server $(DSTROOT)$(LIBDIR)/etc/server
	install -c -s -m 755 etc/sorted-doc $(DSTROOT)$(LIBDIR)/etc/sorted-doc
	install -c -s -m 755 etc/test-distrib $(DSTROOT)$(LIBDIR)/etc/test-distrib
	install -c -s -m 755 etc/yow $(DSTROOT)$(LIBDIR)/etc/yow
	install -c -m 644 etc/TUTORIAL $(DSTROOT)$(LIBDIR)/etc/TUTORIAL
	install -c -m 644 etc/NEWS $(DSTROOT)$(LIBDIR)/etc/NEWS
	install -c -m 644 etc/COPYING $(DSTROOT)$(LIBDIR)/etc/COPYING
	install -c -m 644 etc/DISTRIB $(DSTROOT)$(LIBDIR)/etc/DISTRIB
	cp info/* $(DSTROOT)$(LIBDIR)/info
	tar cf - lisp | (cd $(DSTROOT)$(LIBDIR); tar xf -)
#	cp man/* $(DSTROOT)$(LIBDIR)/man
	-/etc/chown -R root $(DSTROOT)$(LIBDIR)
	chmod -R a+r $(DSTROOT)$(LIBDIR)
	mkdirs $(DSTROOT)$(BINDIR)
	install -c -s -m 755 etc/etags $(DSTROOT)$(BINDIR)/etags
	install -c -s -m 755 src/xemacs $(DSTROOT)$(BINDIR)/xemacs
	-rm -f $(DSTROOT)$(BINDIR)/emacs
	mv $(DSTROOT)$(BINDIR)/xemacs $(DSTROOT)$(BINDIR)/emacs
	

all:
	(cd etc; make all)
	(cd src; make all)	




INCLUDES = -I${top_srcdir}/include ${extra_includes}
LDADD = ${top_builddir}/ggi/libggi.la ${monitest_extralibs}

bin_PROGRAMS = monitest

monitest_SOURCES = drawlib.c flatpanel.c ggitext.c menu.c monitest.c \
	pattern.c resolution.c window.c

EXTRA_monitest_SOURCES = kgitune.c

EXTRA_DIST = drawlib.h ggicolors.h ggitext.h kgitune.h menu.h monitest.h \
	window.h

MAINTAINERCLEANFILES = Makefile.in


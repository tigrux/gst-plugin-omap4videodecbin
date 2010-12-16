AM_CPPFLAGS = $(GST_CFLAGS)

BUILT_SOURCES = vala.stamp

plugindir = $(libdir)/gstreamer-0.10

plugin_LTLIBRARIES = libgstomap4videodecbin.la

libgstomap4videodecbin_la_VALASOURCES = \
	gstomap4videodecbin.vala

libgstomap4videodecbin_la_SOURCES = \
	$(libgstomap4videodecbin_la_VALASOURCES:.vala=.c)

vala.stamp: $(libgstomap4videodecbin_la_VALASOURCES)
	$(VALAC) -C $(VALAFLAGS) $(libgstomap4videodecbin_la_VALASOURCES)
	touch $@

libgstomap4videodecbin_la_CFLAGS = $(GST_CFLAGS) $(GST_BASE_CFLAGS)
libgstomap4videodecbin_la_LIBADD = $(GST_LIBS) $(GST_BASE_LIBS)
libgstomap4videodecbin_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS) -module -avoid-version
libgstomap4videodecbin_la_LIBTOOLFLAGS = --tag=disable-static

EXTRA_DIST = \
	$(libgstomap4videodecbin_la_VALASOURCES) \
	vala.stamp


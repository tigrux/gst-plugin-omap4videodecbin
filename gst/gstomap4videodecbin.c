/* gstomap4videodecbin.c generated by valac 0.10.0, the Vala compiler
 * generated from gstomap4videodecbin.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gst/gst.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_OMAP4_VIDEO_DEC_BIN (omap4_video_dec_bin_get_type ())
#define OMAP4_VIDEO_DEC_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_OMAP4_VIDEO_DEC_BIN, Omap4VideoDecBin))
#define OMAP4_VIDEO_DEC_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_OMAP4_VIDEO_DEC_BIN, Omap4VideoDecBinClass))
#define IS_OMAP4_VIDEO_DEC_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_OMAP4_VIDEO_DEC_BIN))
#define IS_OMAP4_VIDEO_DEC_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_OMAP4_VIDEO_DEC_BIN))
#define OMAP4_VIDEO_DEC_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_OMAP4_VIDEO_DEC_BIN, Omap4VideoDecBinClass))

typedef struct _Omap4VideoDecBin Omap4VideoDecBin;
typedef struct _Omap4VideoDecBinClass Omap4VideoDecBinClass;
typedef struct _Omap4VideoDecBinPrivate Omap4VideoDecBinPrivate;
#define _gst_object_unref0(var) ((var == NULL) ? NULL : (var = (gst_object_unref (var), NULL)))
#define _gst_structure_free0(var) ((var == NULL) ? NULL : (var = (gst_structure_free (var), NULL)))
#define _gst_caps_unref0(var) ((var == NULL) ? NULL : (var = (gst_caps_unref (var), NULL)))

struct _Omap4VideoDecBin {
	GstBin parent_instance;
	Omap4VideoDecBinPrivate * priv;
};

struct _Omap4VideoDecBinClass {
	GstBinClass parent_class;
};

struct _Omap4VideoDecBinPrivate {
	GstGhostPad* sink_pad;
	GstGhostPad* src_pad;
};


static gpointer omap4_video_dec_bin_parent_class = NULL;

GType omap4_video_dec_bin_get_type (void) G_GNUC_CONST;
#define OMAP4_VIDEO_DEC_BIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_OMAP4_VIDEO_DEC_BIN, Omap4VideoDecBinPrivate))
enum  {
	OMAP4_VIDEO_DEC_BIN_DUMMY_PROPERTY
};
#define OMAP4_VIDEO_DEC_BIN_h264_name "video/x-h264"
#define OMAP4_VIDEO_DEC_BIN_mpeg4_name "video/mpeg"
static gboolean _omap4_video_dec_bin_sink_pad_setcaps (GstPad* pad, GstCaps* caps);
static gboolean omap4_video_dec_bin_sink_pad_setcaps (Omap4VideoDecBin* self, GstPad* pad, GstCaps* caps);
Omap4VideoDecBin* omap4_video_dec_bin_new (void);
Omap4VideoDecBin* omap4_video_dec_bin_construct (GType object_type);
static gboolean __omap4_video_dec_bin_sink_pad_setcaps_gst_pad_set_caps_function (GstPad* pad, GstCaps* caps);
static GObject * omap4_video_dec_bin_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void omap4_video_dec_bin_finalize (GObject* obj);
gboolean plugin_init (GstPlugin* plugin);
static gboolean _plugin_init_gst_plugin_init_func (GstPlugin* plugin);

const GstPluginDesc gst_plugin_desc = {GST_VERSION_MAJOR, GST_VERSION_MINOR, "omap4videodecbin", "Omap 4 video decoder bin", _plugin_init_gst_plugin_init_func, "0.0.1", "LGPL", "gstomap4videodecbin", "GstOmap4VideoDecBin", "<unknown>"};


static gboolean _omap4_video_dec_bin_sink_pad_setcaps (GstPad* pad, GstCaps* caps) {
	gboolean result = FALSE;
	GstObject* _tmp0_;
	g_return_val_if_fail (pad != NULL, FALSE);
	g_return_val_if_fail (caps != NULL, FALSE);
	result = omap4_video_dec_bin_sink_pad_setcaps ((_tmp0_ = ((GstObject*) pad)->parent, IS_OMAP4_VIDEO_DEC_BIN (_tmp0_) ? ((Omap4VideoDecBin*) _tmp0_) : NULL), pad, caps);
	return result;
}


static gpointer _gst_structure_copy0 (gpointer self) {
	return self ? gst_structure_copy (self) : NULL;
}


static gpointer _gst_object_ref0 (gpointer self) {
	return self ? gst_object_ref (self) : NULL;
}


static gboolean omap4_video_dec_bin_sink_pad_setcaps (Omap4VideoDecBin* self, GstPad* pad, GstCaps* caps) {
	gboolean result = FALSE;
	GstStructure* structure;
	gboolean full_caps = FALSE;
	const char* _tmp6_;
	GQuark _tmp7_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (pad != NULL, FALSE);
	g_return_val_if_fail (caps != NULL, FALSE);
	structure = _gst_structure_copy0 (gst_caps_get_structure (caps, (guint) 0));
	if (gst_structure_get_value (structure, "framerate") == NULL) {
		full_caps = FALSE;
	} else {
		if (gst_structure_get_value (structure, "width") == NULL) {
			full_caps = FALSE;
		} else {
			if (gst_structure_get_value (structure, "height") == NULL) {
				full_caps = FALSE;
			} else {
				full_caps = TRUE;
			}
		}
	}
	gst_element_set_state ((GstElement*) self, GST_STATE_READY);
	_tmp6_ = gst_structure_get_name (structure);
	_tmp7_ = (NULL == _tmp6_) ? 0 : g_quark_from_string (_tmp6_);
	if (_tmp7_ == g_quark_from_string (OMAP4_VIDEO_DEC_BIN_h264_name))
	switch (0) {
		default:
		{
			GstElement* videodec;
			GstPad* _tmp2_;
			videodec = gst_element_factory_make ("omx_h264dec", "videodec");
			gst_bin_add ((GstBin*) self, _gst_object_ref0 (videodec));
			if (full_caps) {
				GstElement* videoparse;
				GstPad* _tmp0_;
				videoparse = gst_element_factory_make ("nal2bytestream_h264", "videoparse");
				gst_bin_add ((GstBin*) self, _gst_object_ref0 (videoparse));
				gst_element_link (videoparse, videodec);
				gst_ghost_pad_set_target (self->priv->sink_pad, _tmp0_ = gst_element_get_static_pad (videoparse, "sink"));
				_gst_object_unref0 (_tmp0_);
				_gst_object_unref0 (videoparse);
			} else {
				GstElement* videoparse;
				GstPad* _tmp1_;
				videoparse = gst_element_factory_make ("h264parse", "videoparse");
				g_object_set ((GObject*) videoparse, "output-format", 1, "access-unit", TRUE, NULL);
				gst_bin_add ((GstBin*) self, _gst_object_ref0 (videoparse));
				gst_element_link (videoparse, videodec);
				gst_ghost_pad_set_target (self->priv->sink_pad, _tmp1_ = gst_element_get_static_pad (videoparse, "sink"));
				_gst_object_unref0 (_tmp1_);
				_gst_object_unref0 (videoparse);
			}
			gst_ghost_pad_set_target (self->priv->src_pad, _tmp2_ = gst_element_get_static_pad (videodec, "src"));
			_gst_object_unref0 (_tmp2_);
			_gst_object_unref0 (videodec);
			break;
		}
	} else if (_tmp7_ == g_quark_from_string (OMAP4_VIDEO_DEC_BIN_mpeg4_name))
	switch (0) {
		default:
		{
			GstElement* videodec;
			GstPad* _tmp5_;
			videodec = gst_element_factory_make ("omx_mpeg4dec", "videodec");
			gst_bin_add ((GstBin*) self, _gst_object_ref0 (videodec));
			if (full_caps) {
				GstPad* _tmp3_;
				gst_ghost_pad_set_target (self->priv->sink_pad, _tmp3_ = gst_element_get_static_pad (videodec, "sink"));
				_gst_object_unref0 (_tmp3_);
			} else {
				GstElement* videoparse;
				GstPad* _tmp4_;
				videoparse = gst_element_factory_make ("mpeg4videoparse", "videoparse");
				gst_bin_add ((GstBin*) self, _gst_object_ref0 (videoparse));
				gst_element_link (videoparse, videodec);
				gst_ghost_pad_set_target (self->priv->sink_pad, _tmp4_ = gst_element_get_static_pad (videoparse, "sink"));
				_gst_object_unref0 (_tmp4_);
				_gst_object_unref0 (videoparse);
			}
			gst_ghost_pad_set_target (self->priv->src_pad, _tmp5_ = gst_element_get_static_pad (videodec, "src"));
			_gst_object_unref0 (_tmp5_);
			_gst_object_unref0 (videodec);
			break;
		}
	}
	gst_element_set_state ((GstElement*) self, GST_STATE_PAUSED);
	result = gst_pad_set_caps (pad, caps);
	_gst_structure_free0 (structure);
	return result;
}


Omap4VideoDecBin* omap4_video_dec_bin_construct (GType object_type) {
	Omap4VideoDecBin * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


Omap4VideoDecBin* omap4_video_dec_bin_new (void) {
	return omap4_video_dec_bin_construct (TYPE_OMAP4_VIDEO_DEC_BIN);
}


static gboolean __omap4_video_dec_bin_sink_pad_setcaps_gst_pad_set_caps_function (GstPad* pad, GstCaps* caps) {
	gboolean result;
	result = _omap4_video_dec_bin_sink_pad_setcaps (pad, caps);
	return result;
}


static GObject * omap4_video_dec_bin_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	Omap4VideoDecBin * self;
	parent_class = G_OBJECT_CLASS (omap4_video_dec_bin_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = OMAP4_VIDEO_DEC_BIN (obj);
	{
		GstGhostPad* _tmp0_;
		GstGhostPad* _tmp1_;
		self->priv->sink_pad = (_tmp0_ = (GstGhostPad*) gst_ghost_pad_new_no_target_from_template ("sink", gst_element_class_get_pad_template (GST_ELEMENT_CLASS (G_OBJECT_GET_CLASS (self)), "sink")), _gst_object_unref0 (self->priv->sink_pad), _tmp0_);
		gst_pad_set_setcaps_function ((GstPad*) self->priv->sink_pad, __omap4_video_dec_bin_sink_pad_setcaps_gst_pad_set_caps_function);
		gst_element_add_pad ((GstElement*) self, _gst_object_ref0 ((GstPad*) self->priv->sink_pad));
		self->priv->src_pad = (_tmp1_ = (GstGhostPad*) gst_ghost_pad_new_no_target_from_template ("src", gst_element_class_get_pad_template (GST_ELEMENT_CLASS (G_OBJECT_GET_CLASS (self)), "src")), _gst_object_unref0 (self->priv->src_pad), _tmp1_);
		gst_element_add_pad ((GstElement*) self, _gst_object_ref0 ((GstPad*) self->priv->src_pad));
	}
	return obj;
}


static gpointer _gst_caps_ref0 (gpointer self) {
	return self ? gst_caps_ref (self) : NULL;
}


static void omap4_video_dec_bin_base_init (Omap4VideoDecBinClass * klass) {
	{
		GstCaps* caps;
		GstPadTemplate* _tmp2_;
		GstPadTemplate* _tmp3_;
		gst_element_class_set_details_simple (GST_ELEMENT_CLASS (klass), "Omap4DecBin", "Codec/Decoder/Video", "Bin to enable video decoding and parsing (on demand)", "Sandino Flores <sandino@ti.com>");
		caps = gst_caps_new_empty ();
		gst_caps_append_structure (caps, gst_structure_new (OMAP4_VIDEO_DEC_BIN_h264_name, NULL, NULL));
		gst_caps_append_structure (caps, gst_structure_new (OMAP4_VIDEO_DEC_BIN_mpeg4_name, "mpegversion", G_TYPE_INT, 4, NULL, NULL));
		gst_element_class_add_pad_template (GST_ELEMENT_CLASS (klass), _tmp2_ = gst_pad_template_new ("sink", GST_PAD_SINK, GST_PAD_ALWAYS, _gst_caps_ref0 (caps)));
		_gst_object_unref0 (_tmp2_);
		gst_element_class_add_pad_template (GST_ELEMENT_CLASS (klass), _tmp3_ = gst_pad_template_new ("src", GST_PAD_SRC, GST_PAD_ALWAYS, gst_caps_new_any ()));
		_gst_object_unref0 (_tmp3_);
		_gst_caps_unref0 (caps);
	}
}


static void omap4_video_dec_bin_class_init (Omap4VideoDecBinClass * klass) {
	omap4_video_dec_bin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (Omap4VideoDecBinPrivate));
	G_OBJECT_CLASS (klass)->constructor = omap4_video_dec_bin_constructor;
	G_OBJECT_CLASS (klass)->finalize = omap4_video_dec_bin_finalize;
}


static void omap4_video_dec_bin_instance_init (Omap4VideoDecBin * self) {
	self->priv = OMAP4_VIDEO_DEC_BIN_GET_PRIVATE (self);
}


static void omap4_video_dec_bin_finalize (GObject* obj) {
	Omap4VideoDecBin * self;
	self = OMAP4_VIDEO_DEC_BIN (obj);
	_gst_object_unref0 (self->priv->sink_pad);
	_gst_object_unref0 (self->priv->src_pad);
	G_OBJECT_CLASS (omap4_video_dec_bin_parent_class)->finalize (obj);
}


GType omap4_video_dec_bin_get_type (void) {
	static volatile gsize omap4_video_dec_bin_type_id__volatile = 0;
	if (g_once_init_enter (&omap4_video_dec_bin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (Omap4VideoDecBinClass), (GBaseInitFunc) omap4_video_dec_bin_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) omap4_video_dec_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Omap4VideoDecBin), 0, (GInstanceInitFunc) omap4_video_dec_bin_instance_init, NULL };
		GType omap4_video_dec_bin_type_id;
		omap4_video_dec_bin_type_id = g_type_register_static (GST_TYPE_BIN, "Omap4VideoDecBin", &g_define_type_info, 0);
		g_once_init_leave (&omap4_video_dec_bin_type_id__volatile, omap4_video_dec_bin_type_id);
	}
	return omap4_video_dec_bin_type_id__volatile;
}


gboolean plugin_init (GstPlugin* plugin) {
	gboolean result = FALSE;
	g_return_val_if_fail (plugin != NULL, FALSE);
	result = gst_element_register (plugin, "omap4videodecbin", (guint) (GST_RANK_PRIMARY + 2), TYPE_OMAP4_VIDEO_DEC_BIN);
	return result;
}


static gboolean _plugin_init_gst_plugin_init_func (GstPlugin* plugin) {
	gboolean result;
	result = plugin_init (plugin);
	return result;
}





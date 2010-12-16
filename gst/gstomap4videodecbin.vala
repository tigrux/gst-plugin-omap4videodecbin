private class Omap4VideoDecBin : Gst.Bin {
    Gst.GhostPad sink_pad;
    Gst.GhostPad src_pad;

    static const string h264_name = "video/x-h264";
    static const string mpeg4_name = "video/mpeg";

    class construct {
        set_details_simple(
            "Omap4VideoDecBin",
            "Codec/Decoder/Video",
            "Bin to enable video parsing and decoding  (on demand)",
            "Sandino Flores <sandino@ti.com>");

        Gst.Caps caps = new Gst.Caps.empty();
        caps.append_structure(
            new Gst.Structure(h264_name, null));
        caps.append_structure(
            new Gst.Structure(mpeg4_name, "mpegversion", typeof(int), 4, null));

        add_pad_template(
            new Gst.PadTemplate(
                "sink", Gst.PadDirection.SINK,
                Gst.PadPresence.ALWAYS, caps));

        add_pad_template(
            new Gst.PadTemplate(
                "src", Gst.PadDirection.SRC,
                Gst.PadPresence.ALWAYS,
                new Gst.Caps.any()));
    }

    construct {
        sink_pad = new Gst.GhostPad.no_target_from_template("sink", get_pad_template("sink"));
        sink_pad.set_setcaps_function(_sink_pad_setcaps);
        add_pad(sink_pad);

        src_pad = new Gst.GhostPad.no_target_from_template("src", get_pad_template("src"));
        add_pad(src_pad);
    }

    static bool _sink_pad_setcaps(Gst.Pad pad, Gst.Caps caps) {
        return (pad.parent as Omap4VideoDecBin).sink_pad_setcaps(pad, caps);
    }

    bool sink_pad_setcaps(Gst.Pad pad, Gst.Caps caps) {
        Gst.Structure structure = caps.get_structure(0);
        bool full_caps;
        if(structure.get_value ("framerate") == null)
            full_caps = false;
        else if(structure.get_value ("width") == null)
            full_caps = false;
        else if(structure.get_value ("height") == null)
            full_caps = false;
        else
            full_caps = true;

        set_state(Gst.State.READY);

        switch(structure.get_name()) {
            case h264_name:
                Gst.Element videodec = Gst.ElementFactory.make("omx_h264dec", "videodec");
                add(videodec);

                if(full_caps) {
                    Gst.Element videoparse = Gst.ElementFactory.make("nal2bytestream_h264", "videoparse");
                    add(videoparse);
                    videoparse.link(videodec);
                    sink_pad.set_target(videoparse.get_static_pad("sink"));
                }
                else {
                    Gst.Element videoparse = Gst.ElementFactory.make("h264parse", "videoparse");
                    videoparse.set("output-format", 1, "access-unit", true);
                    add(videoparse);
                    videoparse.link(videodec);
                    sink_pad.set_target(videoparse.get_static_pad("sink"));
                }
                
                src_pad.set_target(videodec.get_static_pad("src"));
                break;
            case mpeg4_name:
                Gst.Element videodec = Gst.ElementFactory.make("omx_mpeg4dec", "videodec");
                add(videodec);

                if(full_caps) {
                    sink_pad.set_target(videodec.get_static_pad("sink"));
                }
                else {
                    Gst.Element videoparse = Gst.ElementFactory.make("mpeg4videoparse", "videoparse");
                    add(videoparse);
                    videoparse.link(videodec);
                    sink_pad.set_target(videoparse.get_static_pad("sink"));
                }

                src_pad.set_target(videodec.get_static_pad("src"));
                break;

        }

        set_state(Gst.State.PAUSED);

        return pad.set_caps(caps);
    }
}


private bool plugin_init(Gst.Plugin plugin) {
    return Gst.Element.register(
        plugin, "omap4videodecbin", Gst.Rank.PRIMARY+2, typeof(Omap4VideoDecBin));
}

public const Gst.PluginDesc gst_plugin_desc = {
    Gst.VERSION_MAJOR, Gst.VERSION_MINOR,
    "omap4videodecbin",
    "Omap 4 video decoder bin",
    plugin_init,
    "0.0.1",
    "LGPL",
    "gstomap4videodecbin",
    "GstOmap4VideoDecBin",
    "https://github.com/tigrux/gst-plugin-omap4videodecbin"
};


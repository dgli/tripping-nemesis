#ifndef SCREENSNIPPER_SCREEN_DRAWING_AREA
#define SCREENSNIPPER_SCREEN_DRAWING_AREA

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class ScreenDrawingArea : public Gtk::DrawingArea
{
public:
    ScreenDrawingArea();
    virtual ~ScreenDrawingArea();

protected:

    // overrides the default drawing signal handler
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

    Glib::RefPtr<Gdk::Pixbuf> m_image;
};


#endif // SCREENSNIPPER_SCREEN_DRAWING_AREA

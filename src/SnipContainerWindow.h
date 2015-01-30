/*
 * SnipContainerWindow.h
 *
 *  Created on: Jan 30, 2015
 *      Author: dgli
 */

#ifndef SRC_SNIPCONTAINERWINDOW_H_
#define SRC_SNIPCONTAINERWINDOW_H_

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>

#include "ScreenDrawingArea.h"

class SnipContainerWindow : public Gtk::Window
{
public:
	SnipContainerWindow();
	virtual ~SnipContainerWindow();

protected:
	// handle signals
	void on_button_clicked();

	// Window contents
	Gtk::Button m_button;
	Gtk::Box m_box;
	ScreenDrawingArea * drawingArea;
};

#endif /* SRC_SNIPCONTAINERWINDOW_H_ */

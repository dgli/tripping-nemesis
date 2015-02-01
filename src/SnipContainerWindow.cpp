/*
 * SnipContainerWindow.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: dgli
 */

#include "SnipContainerWindow.h"

#include <iostream>

SnipContainerWindow::SnipContainerWindow()
	: m_button("Hello World")  // creates a new button with label "Hello World".
{
	  // Sets the border width of the window.
	  set_border_width(10);
	  set_decorated(false);

	  // When the button receives the "clicked" signal, it will call the
	  // on_button_clicked() method defined below.
	  m_button.signal_clicked().connect(sigc::mem_fun(*this,
	              &SnipContainerWindow::on_button_clicked));

	  m_button.show();

	  //box
	  m_box.add(m_button);
	  m_box.show();


	  add(m_box);

}

SnipContainerWindow::~SnipContainerWindow() {
	// TODO Auto-generated destructor stub
}

void SnipContainerWindow::on_button_clicked(){
	std::cout << "I was clicked!" << std::endl;

	drawingArea = new ScreenDrawingArea();
	((Gtk::DrawingArea*)drawingArea)->show();

	m_box.add(*drawingArea);

}

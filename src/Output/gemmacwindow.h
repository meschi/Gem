/*-----------------------------------------------------------------
  LOG
  GEM - Graphics Environment for Multimedia

  Interface for the window manager

  Copyright (c) 2009 IOhannes m zmoelnig. forum::für::umläute. IEM. zmoelnig@iem.kug.ac.at
  For information on usage and redistribution, and for a DISCLAIMER OF ALL
  WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

  -----------------------------------------------------------------*/

#ifndef INCLUDE_GEMMACWINDOW_H_
#define INCLUDE_GEMMACWINDOW_H_

#include "Base/GemContext.h"

/*-----------------------------------------------------------------
  -------------------------------------------------------------------
  CLASS
  gemmacwindow

  The window manager

  DESCRIPTION

  Access to GemMan.

  "bang"  - swap the buffers
  "render" - render a frame now

  "create" - create a graphics window
  "destroy" - destroy the graphics window


  "buffer" - single or double buffered
  "fsaa" - full screen anti-aliasing

  "title" - set a title for the graphics window
  "border" - whether we want a border as decoration or not

  "dimen" - the window dimensions
  "fullscreen" - fullscreen mode
  "offset" - the window offset
  "secondscreen" - render to the secondscreen (auto-offset)

  "cursor" - whether we want a cursor or not
  "menubar" - hide notorious menubars
  "topmost" - set the window to stay on top

  -----------------------------------------------------------------*/


class GEM_EXTERN gemmacwindow : public GemContext
{
  CPPEXTERN_HEADER(gemmacwindow, GemContext)

    public:

  //////////
  // Constructor
  gemmacwindow(void);

 private:

  //////////
  // Destructor
  virtual ~gemmacwindow(void);


  // create window
  virtual bool create(void);

  // destroy window
  virtual void destroy(void);

  // check whether we have a window and if so, make it current
  virtual bool makeCurrent(void);
  
  virtual void swapBuffers(void);

  /* dispatch window events */
  virtual void dispatch(void);

   /* window decoration (pre creation) */
   /* window position/dimension (pre creation) */
  virtual void    dimensionsMess(unsigned int width, unsigned int height);

  /* creation/destruction */
  void        createMess(std::string);
  void       destroyMess(void);

  /* post creation */
  void        cursorMess(bool on);

  //////////
  // Should the window be realized
#warning actuallyDisplay
  bool         m_actuallyDisplay;
  public:
  OSStatus eventHandler (EventRef event);

 private:

  class Info;
  Info*m_info;
  
  static bool     init(void);
};

#endif    // for header file

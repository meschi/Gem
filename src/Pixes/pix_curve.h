/*-----------------------------------------------------------------
  LOG
  GEM - Graphics Environment for Multimedia

  map colour values onto others (via tables)
  
  Copyright (c) 1997-1999 Mark Danks. mark@danks.org
  Copyright (c) G�nther Geiger. geiger@epy.co.at
  Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM. zmoelnig@iem.kug.ac.at
    Copyright (c) 2002 James Tittle & Chris Clepper
  For information on usage and redistribution, and for a DISCLAIMER OF ALL
  WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
	
  -----------------------------------------------------------------*/

/*-----------------------------------------------------------------
  pix_curve

  IOhannes m zmoelnig
  mailto:zmoelnig@iem.kug.ac.at
	
  this code is published under the Gnu GeneralPublicLicense that should be distributed with gem & pd
	  
  -----------------------------------------------------------------*/

#ifndef INCLUDE_PIX_CURVE_H_
#define INCLUDE_PIX_CURVE_H_

#include "Base/GemPixObj.h"

/*-----------------------------------------------------------------
  -------------------------------------------------------------------
  CLASS
  pix_curve

  KEYWORDS
  pix
  
  DESCRIPTION
	
  -----------------------------------------------------------------*/
class GEM_EXTERN pix_curve : public GemPixObj
{
  CPPEXTERN_HEADER(pix_curve, GemPixObj)
		
    public:
	
  //////////
  // Constructor
  pix_curve(int argc, t_atom *argv);
	
 protected:
	
  //////////
  // Destructor
  virtual ~pix_curve();
	
  //////////
  // Do the processing
  virtual void 	processRGBAImage(imageStruct &image);
  	
  //////////
  // tables to hold the curves
  t_symbol *name_R, *name_G, *name_B, *name_A;

  //////////
  // mode
  int m_mode;

  //////////
  // check for good arrays
  t_float* checkarray(t_symbol *s, int *length);


  //////////
  // Set new arrays
  void	    	setMess(int argc, t_atom *argv);

  //////////
  // the methods
  static void setMessCallback(void *data, t_symbol *s, int argc, t_atom* argv);

};

#endif	// for header file

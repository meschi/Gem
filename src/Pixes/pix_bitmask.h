/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    Apply a bit mask to each color

    Copyright (c) 1997-1998 Mark Danks. mark@danks.org
    Copyright (c) G�nther Geiger. geiger@epy.co.at
    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM. zmoelnig@iem.kug.ac.at
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef INCLUDE_PIX_BITMASK_H_
#define INCLUDE_PIX_BITMASK_H_

#include "Base/GemPixObj.h"

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    pix_bitmask
    
    Change the overall gain of a pix

KEYWORDS
    pix
    
DESCRIPTION

    Inlet for a list - "vec_gain"
    Inlet for a float - "ft1"

    "vec_gain" - The gain vector to set to
    "ft1" - Which bit to use as a mask (converted to an int)
   
-----------------------------------------------------------------*/
class GEM_EXTERN pix_bitmask : public GemPixObj
{
    CPPEXTERN_HEADER(pix_bitmask, GemPixObj)

    public:

	    //////////
	    // Constructor
    	pix_bitmask();
    	
    protected:
    	
    	//////////
    	// Destructor
    	virtual ~pix_bitmask();

    	//////////
    	// Do the processing
    	virtual void 	processRGBAImage(imageStruct &image);

    	//////////
    	// Do the processing
        virtual void	processGrayImage(imageStruct &image);

    	//////////
    	// Set the new gain
    	void	    	vecMaskMess(int argc, t_atom *argv);
    	
    	//////////
    	// Set the new mask
    	void	    	intMaskMess(int gain);
    	
    	//////////
    	// The new gain
    	unsigned char	m_mask[4];
    
    private:
    
    	//////////
    	// Static member functions
    	static void 	vecMaskMessCallback(void *data, t_symbol *, int argc, t_atom *argv);
    	static void 	floatMaskMessCallback(void *data, t_floatarg gain);
};

#endif	// for header file

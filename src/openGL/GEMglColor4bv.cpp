////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// Implementation file
//
// Copyright (c) 2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM
//	zmoelnig@iem.kug.ac.at
//  For information on usage and redistribution, and for a DISCLAIMER
//  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
//
//  this file has been generated...
////////////////////////////////////////////////////////

#include "GEMglColor4bv.h"

CPPEXTERN_NEW_WITH_FOUR_ARGS ( GEMglColor4bv , t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT)

/////////////////////////////////////////////////////////
//
// GEMglColor4bv
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglColor4bv :: GEMglColor4bv	(t_floatarg arg0=0, t_floatarg arg1=0, t_floatarg arg2=0, t_floatarg arg3=0) {
vMess(arg0, arg1, arg2, arg3);
	m_inlet = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("v"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglColor4bv :: ~GEMglColor4bv () {
	inlet_free(m_inlet);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglColor4bv :: render(GemState *state) {
	glColor4bv (v);
}

/////////////////////////////////////////////////////////
// variable
//
void GEMglColor4bv :: vMess (t_float arg0, t_float arg1, t_float arg2, t_float arg3) {	// FUN
	v[0]=(GLbyte)arg0;
	v[1]=(GLbyte)arg1;
	v[2]=(GLbyte)arg2;
	v[3]=(GLbyte)arg3;
	setModified();
}

/////////////////////////////////////////////////////////
// static member functions
//

void GEMglColor4bv :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglColor4bv::vMessCallback),  	gensym("v"), A_DEFFLOAT, A_DEFFLOAT, A_DEFFLOAT, A_DEFFLOAT, A_NULL);
}

void GEMglColor4bv :: vMessCallback (void* data, t_floatarg arg0, t_floatarg arg1, t_floatarg arg2, t_floatarg arg3) {
	GetMyClass(data)->vMess ( arg0, arg1, arg2, arg3);
}

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

#include "GEMglNormal3fv.h"

CPPEXTERN_NEW_WITH_THREE_ARGS ( GEMglNormal3fv , t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT)

/////////////////////////////////////////////////////////
//
// GEMglNormal3fv
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglNormal3fv :: GEMglNormal3fv	(t_floatarg arg0=0, t_floatarg arg1=0, t_floatarg arg2=0) {
vMess(arg0, arg1, arg2);
	m_inlet = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("v"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglNormal3fv :: ~GEMglNormal3fv () {
	inlet_free(m_inlet);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglNormal3fv :: render(GemState *state) {
	glNormal3fv (v);
}

/////////////////////////////////////////////////////////
// variable
//
void GEMglNormal3fv :: vMess (t_float arg0, t_float arg1, t_float arg2) {	// FUN
	v[0]=(GLfloat)arg0;
	v[1]=(GLfloat)arg1;
	v[2]=(GLfloat)arg2;
	setModified();
}

/////////////////////////////////////////////////////////
// static member functions
//

void GEMglNormal3fv :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglNormal3fv::vMessCallback),  	gensym("v"), A_DEFFLOAT, A_DEFFLOAT, A_DEFFLOAT, A_NULL);
}

void GEMglNormal3fv :: vMessCallback (void* data, t_floatarg arg0, t_floatarg arg1, t_floatarg arg2) {
	GetMyClass(data)->vMess ( arg0, arg1, arg2);
}

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

#include "GEMglRasterPos4d.h"

CPPEXTERN_NEW_WITH_FOUR_ARGS ( GEMglRasterPos4d , t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT)

/////////////////////////////////////////////////////////
//
// GEMglViewport
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglRasterPos4d :: GEMglRasterPos4d	(t_floatarg arg0=0, t_floatarg arg1=0, t_floatarg arg2=0, t_floatarg arg3=0) :
		x((GLdouble)arg0), 
		y((GLdouble)arg1), 
		z((GLdouble)arg2), 
		w((GLdouble)arg3)
{
	m_inlet[0] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("x"));
	m_inlet[1] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("y"));
	m_inlet[2] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("z"));
	m_inlet[3] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("w"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglRasterPos4d :: ~GEMglRasterPos4d () {
inlet_free(m_inlet[0]);
inlet_free(m_inlet[1]);
inlet_free(m_inlet[2]);
inlet_free(m_inlet[3]);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglRasterPos4d :: render(GemState *state) {
	glRasterPos4d (x, y, z, w);
}

/////////////////////////////////////////////////////////
// Variables
//
void GEMglRasterPos4d :: xMess (t_float arg1) {	// FUN
	x = (GLdouble)arg1;
	setModified();
}

void GEMglRasterPos4d :: yMess (t_float arg1) {	// FUN
	y = (GLdouble)arg1;
	setModified();
}

void GEMglRasterPos4d :: zMess (t_float arg1) {	// FUN
	z = (GLdouble)arg1;
	setModified();
}

void GEMglRasterPos4d :: wMess (t_float arg1) {	// FUN
	w = (GLdouble)arg1;
	setModified();
}


/////////////////////////////////////////////////////////
// static member functions
//

void GEMglRasterPos4d :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglRasterPos4d::xMessCallback),  	gensym("x"), A_DEFFLOAT, A_NULL);
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglRasterPos4d::yMessCallback),  	gensym("y"), A_DEFFLOAT, A_NULL);
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglRasterPos4d::zMessCallback),  	gensym("z"), A_DEFFLOAT, A_NULL);
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglRasterPos4d::wMessCallback),  	gensym("w"), A_DEFFLOAT, A_NULL);
};

void GEMglRasterPos4d :: xMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->xMess ( (t_float)    arg0);
}
void GEMglRasterPos4d :: yMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->yMess ( (t_float)    arg0);
}
void GEMglRasterPos4d :: zMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->zMess ( (t_float)    arg0);
}
void GEMglRasterPos4d :: wMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->wMess ( (t_float)    arg0);
}

////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// Created by tigital on 10/04/2005.
// Copyright 2005 James Tittle
//
// Implementation file
//
//    Copyright (c) 1997-1999 Mark Danks.
//    Copyright (c) Günther Geiger.
//    Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

#include "glsl_tesscontrol.h"

CPPEXTERN_NEW_WITH_ONE_ARG(glsl_tesscontrol, t_symbol *, A_DEFSYM);

/////////////////////////////////////////////////////////
//
// glsl_tesscontrol
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
glsl_tesscontrol :: glsl_tesscontrol(t_symbol *filename)
  : glsl_vertex()
{
  openMess(filename);
}

////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
glsl_tesscontrol :: ~glsl_tesscontrol()
{
  closeMess();
}

////////////////////////////////////////////////////////
// extension check
//
/////////////////////////////////////////////////////////
bool glsl_tesscontrol :: isRunnable()
{
  if(GLEW_VERSION_4_0) {
    m_shaderTarget = GL_TESS_CONTROL_SHADER;
    m_shaderType = GL2;
    return true;
  }

  error("need OpenGL-4.0 to run GLSL tesselation");
  return false;
}

////////////////////////////////////////////////////////
// printInfo
//
/////////////////////////////////////////////////////////
void glsl_tesscontrol :: printInfo()
{
  if(getState()==INIT) {
    verbose(0, "not initialized yet with a valid context");
    return;
  }
  if(GLEW_VERSION_4_0) {
    GLint bitnum = 0;
    post("glsl_tesselation_evaluation Hardware Info");
    post("=========================================");
#if 0
    glGetIntegerv( GL_MAX_TESSCONTROL_UNIFORM_COMPONENTS_EXT, &bitnum );
    post("MAX_TESSCONTROL_UNIFORM_COMPONENTS_EXT: %d", bitnum);
    glGetIntegerv( GL_MAX_VARYING_FLOATS, &bitnum );
    post("MAX_VARYING_FLOATS: %d", bitnum);
    glGetIntegerv( GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &bitnum );
    post("MAX_COMBINED_TEXTURE_IMAGE_UNITS: %d", bitnum);
    glGetIntegerv( GL_MAX_TESSCONTROL_TEXTURE_IMAGE_UNITS_EXT, &bitnum );
    post("MAX_TESSCONTROL_TEXTURE_IMAGE_UNITS_EXT: %d", bitnum);
    glGetIntegerv( GL_MAX_TEXTURE_IMAGE_UNITS, &bitnum );
    post("MAX_TEXTURE_IMAGE_UNITS: %d", bitnum);
    glGetIntegerv( GL_MAX_TEXTURE_COORDS, &bitnum );
    post("MAX_TEXTURE_COORDS: %d", bitnum);
#endif
    if(m_shader) {
      GLint shader = m_shader;
      post("compiled last shader to ID: %d", shader);
    }
  } else {
    post("no GLSL support");
  }
}

////////////////////////////////////////////////////////
// static member function
//
/////////////////////////////////////////////////////////
void glsl_tesscontrol :: obj_setupCallback(t_class *classPtr)
{
}

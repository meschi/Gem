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

#include "glsl_tesseval.h"

CPPEXTERN_NEW_WITH_ONE_ARG(glsl_tesseval, t_symbol *, A_DEFSYM);

/////////////////////////////////////////////////////////
//
// glsl_tesseval
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
glsl_tesseval :: glsl_tesseval(t_symbol *filename)
  : glsl_vertex()
{
  openMess(filename);
}

////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
glsl_tesseval :: ~glsl_tesseval()
{
  closeMess();
}

////////////////////////////////////////////////////////
// extension check
//
/////////////////////////////////////////////////////////
bool glsl_tesseval :: isRunnable()
{
  if(GLEW_VERSION_4_0) {
    m_shaderTarget = GL_TESS_EVALUATION_SHADER;
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
void glsl_tesseval :: printInfo()
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
    glGetIntegerv( GL_MAX_TESSEVAL_UNIFORM_COMPONENTS_EXT, &bitnum );
    post("MAX_TESSEVAL_UNIFORM_COMPONENTS_EXT: %d", bitnum);
    glGetIntegerv( GL_MAX_VARYING_FLOATS, &bitnum );
    post("MAX_VARYING_FLOATS: %d", bitnum);
    glGetIntegerv( GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &bitnum );
    post("MAX_COMBINED_TEXTURE_IMAGE_UNITS: %d", bitnum);
    glGetIntegerv( GL_MAX_TESSEVAL_TEXTURE_IMAGE_UNITS_EXT, &bitnum );
    post("MAX_TESSEVAL_TEXTURE_IMAGE_UNITS_EXT: %d", bitnum);
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
void glsl_tesseval :: obj_setupCallback(t_class *classPtr)
{
  CPPEXTERN_MSG1(classPtr, "open", openMess, t_symbol*);
  CPPEXTERN_MSG0(classPtr, "print", printInfo);
}

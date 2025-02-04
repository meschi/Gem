////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.at
//
// Implementation file
//
//    Copyright (c) 1997-2000 Mark Danks.
//    Copyright (c) Günther Geiger.
//    Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

#include "part_head.h"


#include "papi/papi.h"

CPPEXTERN_NEW_WITH_ONE_ARG(part_head, t_floatarg, A_DEFFLOAT);

/////////////////////////////////////////////////////////
//
// part_head
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
part_head :: part_head(t_floatarg numParts)
  : m_speed(1.f)
{
  if (numParts <= 0) {
    numParts = 1000.f;
  }
  m_particleGroup = pGenParticleGroups(1, (int)numParts);
}

/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
part_head :: ~part_head(void)
{
  if (m_particleGroup < 0) {
    pDeleteParticleGroups(m_particleGroup, 1);
  }
}

/////////////////////////////////////////////////////////
// renderParticles
//
/////////////////////////////////////////////////////////
void part_head :: renderParticles(GemState *state)
{
  if (m_particleGroup < 0) {
    return;
  }

  // reset local data saved to the global particle state struct
  pResetGlobalToDefault();

  // The original default was 50.f milliseconds (20 fps)
  pTimeStep((m_tickTime / 50.f) * m_speed);

  pCurrentGroup(m_particleGroup);
}

/////////////////////////////////////////////////////////
// speedMess
//
/////////////////////////////////////////////////////////
void part_head :: speedMess(float speed)
{
  m_speed = (speed < 0.001f) ? 0.0001f : speed;
}

/////////////////////////////////////////////////////////
// static member functions
//
/////////////////////////////////////////////////////////
void part_head :: obj_setupCallback(t_class *classPtr)
{
  CPPEXTERN_MSG1(classPtr, "speed", speedMess, float);
}

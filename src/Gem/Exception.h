
/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    The base class for exceptions thrown by Gem

    Copyright (c) 2009-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/


/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    GemException

    an exception class...

DESCRIPTION

    this is a class, we can throw on creation,
    to make sure that the pd-object can not be created



-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_GEM_EXCEPTION_H_
#define _INCLUDE__GEM_GEM_EXCEPTION_H_

#include "Gem/ExportDef.h"
#include <string>

typedef struct _text t_object;

class GEM_EXTERN GemException
{
 public:
  GemException(void);
  GemException(const char*error);
  GemException(const std::string&error);
  virtual ~GemException(void);

  virtual const char *what(void) const;
  virtual void report(const char*origin=0) const;
 private:
  const std::string&ErrorString;
};

namespace gem {
  GEM_EXTERN void catchGemException(const char*name=NULL, const t_object*obj=NULL);
};


#endif /* _INCLUDE__GEM_GEM_EXCEPTION_H_ */

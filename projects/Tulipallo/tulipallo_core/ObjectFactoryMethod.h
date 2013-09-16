/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#ifndef OBJECTFACTORYPAIR_H
#define	OBJECTFACTORYPAIR_H

#include <link.h>
#include <stdlib.h>
#include "Context.h"
#include "ObjectFactoryException.h"

class ObjectFactoryMethod {
public:
    ObjectFactoryMethod(std::string library, void* handle, 
                        void* (*factory)(Context*));
    
    virtual void*       newInstance(Context* context) 
                throw (ObjectFactoryException);
    
    virtual std::string getLibrary();
    
    virtual ~ObjectFactoryMethod();
    
private:
    std::string lib;
    void*       handle;
    void*       (*factory)(Context*);
};

#endif	/* OBJECTFACTORYPAIR_H */


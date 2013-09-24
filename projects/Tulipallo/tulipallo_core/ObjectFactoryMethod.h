/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 */

#ifndef OBJECTFACTORYPAIR_H
#define	OBJECTFACTORYPAIR_H

#include <link.h>
#include <stdlib.h>
#include "Context.h"
#include "ObjectFactoryException.h"

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 * 
 * @author Robert R Murrell
 * @version 1.0 beta
 */
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


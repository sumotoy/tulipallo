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

#ifndef JETGEN_H
#define	JETGEN_H

#include <jni.h>
#include "tetgen.h"

/**
 * This class is a wrapper around the Native tetgen libraries created by 
 * Dr. Hang Si. For more information <a href="http://tetgen.berlios.de/">tetgen.berlios.de</a>
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
class JetGen {
public:
    JetGen();
    
    JNIEXPORT jobject JNICALL Java_org_tulipallo_tools_cfd_fvm_mesh_tetrahedral_JetGen_create(JNIEnv* env, 
                jobject caller, jobject subject);
    
    virtual ~JetGen();

protected:
    virtual void    createInput(tetgenio* in, jobject* subject);
    virtual jobject createMesh(tetgenio* out);
};

#endif	/* JETGEN_H */


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

#include "JetGen.h"

JetGen::JetGen() {
}

/**
 * 
 * @param env
 * @param caller
 * @param subject
 * 
 * @return 
 */
jobject JetGen::Java_org_tulipallo_tools_cfd_fvm_mesh_tetrahedral_JetGen_create(JNIEnv* env, 
        jobject caller, jobject subject) {
    
    tetgenbehavior* b   = new tetgenbehavior();
    tetgenio*       in  = new tetgenio();
    tetgenio*       out = new tetgenio();
    
    this->createInput(in, &subject);
    
    tetrahedralize(b, in, out, NULL, NULL);
    
    // TODO: Populate the Mesh and return
    jobject mesh = this->createMesh(out);
    
    delete b;
    delete in;
    delete out;
    
    return mesh;
}

/**
 * 
 * @param out
 * 
 * @return 
 */
jobject JetGen::createMesh(tetgenio* out) {
    //
}

/**
 * 
 * @param in
 * @param subject
 */
void JetGen::createInput(tetgenio* in, jobject* subject) {
    //
}

JetGen::~JetGen() {
}


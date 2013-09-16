/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "JetGen.h"

JetGen::JetGen() {
}

/**
 * 
 * @param env
 * @param o
 */
jobject JetGen::Java_org_tulipallo_tools_cfd_fvm_mesh_tetrahedral_JetGen_create(JNIEnv* env, 
        jobject caller, jobject subject) {
    tetgenbehavior b     = new tetgenbehavior();
    tetgenio       in    = new tetgenio();
    tetgenio       out   = new tetgenio();
    
    tetrahedralize(&b, &in, &out, NULL, NULL);
    
    return NULL;
}

JetGen::~JetGen() {
}


#ifndef JETGEN_H
#define	JETGEN_H

#include <jni.h>
#include "tetgen.h"

class JetGen {
public:
    JetGen();
    
    /*
     * Class:     org_tulipallo_tools_cfd_fvm_mesh_tetrahedral_JetGen
     * Method:    create
     * Signature: (Lorg/tulipallo/tools/cfd/Subject;)Lorg/tulipallo/tools/cfd/fvm/mesh/Mesh;
     */
    JNIEXPORT jobject JNICALL Java_org_tulipallo_tools_cfd_fvm_mesh_tetrahedral_JetGen_create(JNIEnv* env, 
                jobject caller, jobject subject);
    
    virtual ~JetGen();
private:

};

#endif	/* JETGEN_H */


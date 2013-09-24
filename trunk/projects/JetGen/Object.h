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

#ifndef OBJECT_H
#define	OBJECT_H

#include <jni.h>
#include <string>

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
class Object {
public:
    Object(jclass c, jobject o, JNIEnv* e);
    
    virtual jclass  getClass();
    virtual jobject getReference();
    virtual JNIEnv*  getEnvironment();
    
    virtual ~Object();
    
protected:
    jclass  aClass;
    jobject aReference;
    JNIEnv* e;
    
    /**
     * Returns the java class specified by <tt>name</tt>.
     * 
     * @param env  The JNI environment specified in the exported method.
     * @param name The fully qualified name of the java class as described in 
     *             FindClass.
     * 
     * @return The Java Class specified by <tt>name</tt> or <tt>NULL</tt> if 
     *         no class can be found.
     */
    jclass findClass(JNIEnv* env, char* name) {
        jclass clazz = env->FindClass(name);
    }
    
    /**
     * 
     * @param env
     * @param name
     * @param signiture
     * 
     * @return 
     */
    jmethodID getMethod(JNIEnv* env, jclass& clazz, char* name, char* signiture){
        jmethodID mid = env->GetMethodID(clazz, name, signiture);
    }
    
    jobject invokeObjectMethod(JNIEnv* env, jobject& o, jmethodID& id) {
        jobject obj = env->CallObjectMethod(o, id, NULL);
    }
    
    void invokeVoidMethod(JNIEnv* env, jobject& o, jmethodID& id) {
        env->CallVoidMethod(o, id, NULL);
    }
    
    std::string getString(JNIEnv* env, jclass& clazz, std::string name, 
                          std::string signiture) {
        //
    }
    
    long long getString(JNIEnv* env, jclass& clazz, std::string name, 
                        std::string signiture) {
        //
    }
    
    jobject newInstance(JNIEnv* env, jclass& clazz) {
        jobject obj = env->AllocObject(clazz);
    }
};

#endif	/* OBJECT_H */


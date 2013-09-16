/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2013 M2 Astronautics
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

package org.tulipallo.tools.cfd.fvm.mesh;

import java.util.List;
import org.tulipallo.tools.cfd.ExceptionEvent;
import org.tulipallo.tools.cfd.Subject;

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
 * @since Java 6
 * @version 1.0 beta
 */
public abstract class MeshGenerator {
    protected Subject            subject;
    protected List<MeshListener> listeners;
    
    protected final Object listenerMutex = new Object();
    protected final Object subjectMutex = new Object();
    
    public void addListener(final MeshListener listener) {
        if(listener == null)
            throw new IllegalArgumentException(
                    "Argument \"listener\" cannot be null.");
        synchronized(this.listenerMutex) {
            this.listeners.add(listener);
        }
    }
    
    public void removeListener(final MeshListener listener) {
        synchronized(this.listenerMutex) {
            this.listeners.remove(listener);
        }
    }

    public Subject getSubject() {
        synchronized(this.subjectMutex) {
            return this.subject;
        }
    }

    public void setSubject(final Subject subject) {
        if(subject == null)
            throw new IllegalArgumentException(
                    "Argument \"subject\" cannot be null.");
        synchronized(this.subjectMutex) {
            this.subject = subject;
        }
    }
    
    public void generate(final Subject subject) throws MeshException {
        this.setSubject(subject);
        this.generate();
    }
    
    public abstract void generate() throws MeshException;
    
    protected final void fireExceptionEvent(final Throwable cause) {
        if(cause == null)
            throw new IllegalArgumentException(
                    "Argument \"cause\" cannot be null.");
        
        ExceptionEvent event = new ExceptionEvent(cause, this);
        synchronized(this.listenerMutex) {
            for(MeshListener listener : this.listeners) {
                listener.handleException(event);
            }
        }
    }
    
    protected final void fireMeshCompletedEvent(final Mesh mesh) {
        if(mesh == null)
            throw new IllegalArgumentException(
                    "Argument \"mesh\" cannot be null.");
        
        MeshEvent event = new MeshEvent(mesh, this);
        synchronized(this.listenerMutex) {
            for(MeshListener listener : this.listeners) {
                listener.handleMeshCompleted(event);
            }
        }
    }
}

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
package org.tulipallo.tools.cfd;

/**
 *
 * @author murrellrr
 */
public class ExceptionEvent extends Event {
    private final Throwable exception;

    public ExceptionEvent(final Throwable exception, final long time, 
                          final Object source) {
        super(time, source);
        this.exception = exception;
    }

    public ExceptionEvent(final Throwable exception, final Object source) {
        super(source);
        this.exception = exception;
    }

    public Throwable getException() {
        return this.exception;
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final ExceptionEvent other = (ExceptionEvent) obj;
        if (this.exception != other.exception && (this.exception == null || 
                !this.exception.equals(other.exception))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 29 * hash + (this.exception != null ? this.exception.hashCode() 
                : 0);
        return hash;
    }
}

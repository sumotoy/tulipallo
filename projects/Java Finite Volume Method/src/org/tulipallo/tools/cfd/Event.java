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
 * An event is an outcome in the Java Finite Volume Method Simulation that has a 
 * time axis with an immediate concern.
 * <p/>
 * This class is the base class for all events in the JFVM simulation.
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics</tt>
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
public class Event {
    private final long   time;
    private final Object source;

    /**
     * Creates a new <tt>Event</tt> who's source is indicated by attribute 
     * <tt>source</tt>.
     * <p/>
     * The current time in milliseconds is used by this constructor. See 
     * {@link System.currentTimeMillis()} for more information.
     * 
     * @param source The object that threw this <tt>Event</tt>.
     * 
     * @see System#currentTimeMillis()
     */
    public Event(final Object source) {
        if(source == null)
            throw new IllegalArgumentException(
                    "Argument \"source\" cannot be null.");
        this.source = source;
        this.time   = System.currentTimeMillis();
    }

    /**
     * Creates a new <tt>Event</tt> who's source is indicated by attribute 
     * <tt>source</tt> with an event time of attribute <tt>time</tt>.
     * 
     * @param time   The time this <tt>Event</tt> was fired.
     * @param source The object that threw this <tt>Event</tt>.
     */
    public Event(final long time, final Object source) {
        if(source == null)
            throw new IllegalArgumentException(
                    "Argument \"source\" cannot be null.");
        this.source = source;
        this.time   = time;
    }

    /**
     * Returns the object that threw this <tt>Event</tt>.
     * 
     * @return The object that threw this <tt>Event</tt>.
     */
    public Object getSource() {
        return this.source;
    }

    /**
     * Returns the time this <tt>Event</tt> was fired.
     * 
     * @return The time this <tt>Event</tt> was fired.
     */
    public long getTime() {
        return this.time;
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Event other = (Event) obj;
        if (this.time != other.time) {
            return false;
        }
        if (this.source != other.source && (this.source == null ||
                !this.source.equals(other.source))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + (int) (this.time ^ (this.time >>> 32));
        hash = 67 * hash + (this.source != null ? this.source.hashCode() : 0);
        return hash;
    }
}

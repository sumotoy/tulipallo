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

package org.tulipallo.tools.cfd.entity;

/**
 * This class allows a listener to filter out attributes changed of no interest.
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
public abstract class FilterableAttributeChangedListener
                                implements AttributeChangedListener {
    private String name;

    /**
     * Creates a new instance of <tt>FilterableAttributeChangedListener</tt>
     * that filters out all bean attribute changed events except for those
     * specified by argument <tt>attribute</tt>.
     *
     * @param attribute The bean attribute to filter for this listener.
     *
     * @throws IllegalArgumentException if argument <tt>attribute</tt> is
     *                                  <tt>null</tt>.
     */
    public FilterableAttributeChangedListener(final Attribute attribute) {
        if(attribute == null)
            throw new IllegalArgumentException(
                    "Argument \"attribute\" cannot be null.");
        this.setName(attribute.getName());
    }

    /**
     * Creates a new instance of <tt>FilterableAttributeChangedListener</tt>
     * that filters out all bean attribute changed events except for those
     * named argument <tt>name</tt>.
     *
     * @param name The name of the bean attribute to filter for this
     *             listener.
     *
     * @throws IllegalArgumentException if argument <tt>name</tt> is
     *                                  <tt>null</tt>.
     */
    public FilterableAttributeChangedListener(final String name) {
        this.setName(name);
    }

    final void setName(final String name) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"attribute\" cannot be null.");
        this.name = name;
    }

    /**
     * Method invoked by an entity when an attribute has changed.
     * <p/>
     * This method compares the beanattribute specified in argument
     * <tt>event</tt> to the bean attribute defined in this class.  If the
     * attributes are equal the
     * {@link #handleFilteredAttributeChanged(org.jfvm.entity.AttributeChangedEvent)}
     * method is invoked.
     *
     * @param event The event representing the attribute changed for a bean.
     */
    @Override
    public void handleAttributeChanged(final AttributeChangedEvent event) {
        if(this.name.equals(event.getAttribute().getName()))
            this.handleFilteredAttributeChanged(event);
    }

    /**
     * Method invoked by {@link #handleAttributeChanged(org.jfvm.entity.AttributeChangedEvent)}
     * when an attribute matching the attribute this listener is filtering for
     * has changed.
     *
     * @param event The event representing the attribute changed for a bean.
     */
    protected abstract void handleFilteredAttributeChanged(
                                    AttributeChangedEvent event);

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final FilterableAttributeChangedListener other =
                (FilterableAttributeChangedListener) obj;
        if ((this.name == null) ? (other.name != null) :
            !this.name.equals(other.name)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 73 * hash + (this.name != null ? this.name.hashCode() : 0);
        return hash;
    }
}

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

import junit.framework.TestCase;
import org.junit.Test;

/**
 * Test case for {@link Event}.
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
public class EventTest {
    @Test
    public void testConstructorNullSource() {
        try {
            new Event(null);
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected result
        }
    }
    
    @Test
    public void testConstructorSource() {
        Event event = new Event(this);
        TestCase.assertEquals("Expected source to be an instance of "
                + "this test case.", 
                this, event.getSource());
    }
    
    @Test
    public void testConstructorTimeNullSource() {
        try {
            new Event(1, null);
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected result
        }
    }
    
    @Test
    public void testConstructor() {
        Event event = new Event(1, this);
        TestCase.assertEquals("Expected source to be an instance of "
                + "this test case.", 
                     this, event.getSource());
        TestCase.assertTrue("Expected time to be 1.", 
                   1 == event.getTime());
    }
    
    @Test
    public void testEqualsNotEqual() {
        Event event1 = new Event(1, this);
        Event event2 = new Event(2, this);
        
        TestCase.assertFalse("Epected event1 to not equal event2.", 
                    event1.equals(event2));
    }
    
    @Test
    public void testEqualsEqual() {
        Event event1 = new Event(1, this);
        Event event2 = new Event(1, this);
        
        TestCase.assertEquals("Epected event1 to equal event2.", 
                    event1, event2);
    }
    
    @Test
    public void testHashcodeNotEqual() {
        Event event1 = new Event(1, this);
        Event event2 = new Event(2, this);
        
        TestCase.assertFalse("Epected event1 hash code to not equal "
                + "event2 hash code.", 
                    event1.hashCode() == event2.hashCode());
    }
    
    @Test
    public void testHashcodeEqual() {
        Event event1 = new Event(1, this);
        Event event2 = new Event(1, this);
        
        TestCase.assertTrue("Epected event1 hash code to equal "
                + "event2 hash code.", 
                    event1.hashCode() == event2.hashCode());
    }
}

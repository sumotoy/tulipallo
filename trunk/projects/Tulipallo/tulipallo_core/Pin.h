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

#ifndef PIN_H
#define	PIN_H

enum IO_MODE {
    IO_INPUT, IO_OUTPUT
};

enum IO_PULL {
    IO_PULL_OFF, IO_PULL_DOWN, IO_PULL_UP
};

/**
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
class Pin {
public:
    Pin(const Pin& orig);
    Pin(unsigned int number, IO_MODE mode);
    Pin(unsigned int number, IO_MODE mode, IO_PULL pull);
    
    virtual unsigned int getNumber();
    virtual IO_MODE      getMode();
    virtual IO_PULL      getPull();
    
    virtual bool operator < (const Pin& b) const;
    
    virtual ~Pin();

private:
    unsigned int number;
    IO_MODE      mode;
    IO_PULL      pull;
};

#endif	/* PIN_H */


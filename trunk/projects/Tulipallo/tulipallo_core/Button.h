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

#ifndef BUTTON_H
#define	BUTTON_H

#include <list>
#include "IButtonListener.h"
#include "IButtonCommand.h"
#include "Thread.h"

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
class Button {
public:
    Button();
    Button(bool toggable);
    Button(IButtonCommand* command);
    Button(bool toggable, IButtonCommand* command);
    
    virtual void setCommand(IButtonCommand* command);
    virtual bool isTogglable();
    virtual void setTogglable(bool togglable);
    virtual bool isToggled();
    virtual void setToggled(bool toggled);
    virtual void push();
    virtual void addButtonListener(IButtonListener* listener);
    virtual void removeButtonListener(IButtonListener* listener);
    
    virtual ~Button();
    
protected:    
    virtual void fireButtonDownEvent();
    virtual void fireButtonUpEvent();
    virtual void fireButtonPressEvent();
    virtual void fireButtonToggledEvent();
    
private:
    bool                         togglable;
    bool                         toggled;
    std::list<IButtonListener*>* listeners;
    pthread_mutex_t*             buttonMutex;
    IButtonCommand*              command;
};

#endif	/* BUTTON_H */


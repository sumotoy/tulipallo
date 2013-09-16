/* 
 * File:   Button.h
 * Author: Robert
 *
 * Created on June 15, 2013, 12:07 AM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include <list>
#include "IButtonListener.h"
#include "IButtonCommand.h"
#include "Thread.h"

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


/* 
 * File:   IButtonListener.h
 * Author: Robert
 *
 * Created on June 15, 2013, 9:48 AM
 */

#ifndef IBUTTONLISTENER_H
#define	IBUTTONLISTENER_H

#include "ButtonDownEvent.h"
#include "ButtonUpEvent.h"
#include "ButtonPressEvent.h"
#include "ButtonToggledEvent.h"

class IButtonListener {
public:
    IButtonListener();
    
    virtual void handleButtonDown(ButtonDownEvent event)       = 0;
    virtual void handleButtonUp(ButtonDownEvent event)         = 0;
    virtual void handleButtonPress(ButtonDownEvent event)      = 0;
    virtual void handleButtonToggled(ButtonToggledEvent event) = 0;
    
    virtual ~IButtonListener();
private:

};

#endif	/* IBUTTONLISTENER_H */


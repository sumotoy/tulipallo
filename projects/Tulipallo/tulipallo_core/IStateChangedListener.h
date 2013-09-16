/* 
 * File:   IStateChangedListener.h
 * Author: Robert
 *
 * Created on June 16, 2013, 6:32 PM
 */

#ifndef ISTATECHANGEDLISTENER_H
#define	ISTATECHANGEDLISTENER_H

#include "StateChangedEvent.h"

class IStateChangedListener {
public:
    IStateChangedListener();
    
    virtual void handleStateChanged(StateChangedEvent event) = 0;
    
    virtual ~IStateChangedListener();
private:

};

#endif	/* ISTATECHANGEDLISTENER_H */


/* 
 * File:   ControlSurfaceFactory.h
 * Author: Robert
 *
 * Created on June 10, 2013, 10:16 PM
 */

#ifndef CONTROLSURFACEFACTORY_H
#define	CONTROLSURFACEFACTORY_H

#include "ControlSurfaceSentence.h"
#include "SentenceFactory.h"

class ControlSurfaceFactory : public SentenceFactory {
public:
    ControlSurfaceFactory();
    
    virtual ~ControlSurfaceFactory();
    
protected:
    virtual XPlaneSentence* newInstance() throw (MarshallingException);
    virtual bool            isFactory(int command);
    
private:

};

#endif	/* CONTROLSURFACEFACTORY_H */


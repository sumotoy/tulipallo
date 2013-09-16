/* 
 * File:   LocationSentenceFactory.h
 * Author: Robert
 *
 * Created on June 6, 2013, 6:28 PM
 */

#ifndef LOCATIONFACTORY_H
#define	LOCATIONFACTORY_H

#include "SentenceFactory.h"
#include "LocationSentence.h"

class LocationFactory : public SentenceFactory {
public:
    LocationFactory();
    
    virtual ~LocationFactory();
    
protected:
    virtual XPlaneSentence* newInstance() throw (MarshallingException);
    virtual bool            isFactory(int command);
    
private:

};

#endif	/* LOCATIONFACTORY_H */


/* 
 * File:   SpeedSentenceFactory.h
 * Author: Robert
 *
 * Created on June 5, 2013, 8:59 PM
 */

#ifndef SPEEDFACTORY_H
#define	SPEEDFACTORY_H

#include "SentenceFactory.h"
#include "SpeedSentence.h"

class SpeedFactory : public SentenceFactory {
public:
    SpeedFactory();
    
    virtual ~SpeedFactory();
    
protected:
    virtual XPlaneSentence* newInstance() throw (MarshallingException);
    virtual bool            isFactory(int command);
    
private:

};

#endif	/* SPEEDFACTORY_H */


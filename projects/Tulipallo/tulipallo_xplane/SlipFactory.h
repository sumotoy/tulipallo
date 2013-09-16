/* 
 * File:   SlipFactory.h
 * Author: Robert
 *
 * Created on June 26, 2013, 10:41 PM
 */

#ifndef SLIPFACTORY_H
#define	SLIPFACTORY_H

#include "SentenceFactory.h"
#include "SlipSentence.h"

class SlipFactory : public SentenceFactory {
public:
    SlipFactory();
    
    virtual ~SlipFactory();
    
protected:
    virtual XPlaneSentence* newInstance() throw (MarshallingException);
    virtual bool            isFactory(int command);
    
private:

};

#endif	/* SLIPFACTORY_H */


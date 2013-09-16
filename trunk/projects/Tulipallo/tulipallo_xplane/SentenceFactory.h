/* 
 * File:   XPlaneSentanceFactory.h
 * Author: Robert
 *
 * Created on June 4, 2013, 9:30 PM
 */

#ifndef SENTENCEFACTORY_H
#define	SENTENCEFACTORY_H

#include "../tulipallo_core/DataStream.h"
#include "XPlaneSentence.h"
#include "MarshallingException.h"

class SentenceFactory {
public:
    SentenceFactory();
    
    virtual void            addLink(SentenceFactory* newLink);
    virtual XPlaneSentence* create(int command) throw (MarshallingException);
    
    virtual ~SentenceFactory();
    
protected:
    virtual XPlaneSentence* newInstance() throw (MarshallingException) = 0;
    virtual bool            isFactory(int command)                     = 0;
    
private:
    SentenceFactory* link;
};

#endif	/* SENTENCEFACTORY_H */


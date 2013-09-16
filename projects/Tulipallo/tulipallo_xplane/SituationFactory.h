/* 
 * File:   SituationSentenceFactory.h
 * Author: Robert
 *
 * Created on June 6, 2013, 10:44 PM
 */

#ifndef SITUATIONFACTORY_H
#define	SITUATIONFACTORY_H

#include "SentenceFactory.h"
#include "SituationSentence.h"

class SituationFactory : public SentenceFactory {
public:
    SituationFactory();
    
    virtual ~SituationFactory();
    
protected:
    virtual XPlaneSentence* newInstance() throw (MarshallingException);
    virtual bool            isFactory(int command);
    
private:

};

#endif	/* SITUATIONFACTORY_H */


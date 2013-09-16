/* 
 * File:   ITulipalloCommand.h
 * Author: Robert
 *
 * Created on June 11, 2013, 10:09 PM
 */

#ifndef RULE_H
#define	RULE_H

#include "../tulipallo_control/ISituation.h"
#include "../tulipallo_core/Thread.h"

class Rule {
public:
    Rule();
    
    virtual bool isEnabled();
    virtual void setEnabled(bool enabled);
    virtual void execute(ISituation* situation);
    virtual void addLink(Rule* link);
    
    virtual ~Rule();
    
protected:
    virtual void doCommand(ISituation* situation) = 0;
    
private:
    Rule*            link;
    pthread_mutex_t* mutex;
    bool             enabled;
    
};

#endif	/* RULE_H */


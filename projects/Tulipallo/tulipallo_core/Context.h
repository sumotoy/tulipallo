/* 
 * File:   Context.h
 * Author: Robert
 *
 * Created on June 28, 2013, 10:54 PM
 */

#ifndef CONTEXT_H
#define	CONTEXT_H

#include <map>
#include "Properties.h"

class Context {
public:
    Context();
    Context(const Context& orig);
    
    virtual void* getProperty(std::string key);
    virtual void  setProperty(std::string key, void* value);
    virtual void  setProperties(Properties* properties);
    virtual void  setProperties(std::map<std::string, void*>* properties);
    virtual bool  contains(std::string key);
    
    virtual ~Context();
    
private:
    std::map<std::string, void*>* properties;
    
};

#endif	/* CONTEXT_H */


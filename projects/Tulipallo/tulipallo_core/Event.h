/*
 * Copyright (c) Robert R Murrell, 2013. All rights reserved.
 */

#ifndef EVENT_H
#define	EVENT_H

class Event {
public:
    Event();
    Event(void* source);
    Event(unsigned long long time, void* source);
    Event(const Event& source);
    
    virtual unsigned long long getTime();
    virtual void* getSource();
    
    virtual ~Event();
private:
    unsigned long long time;
    void*              source;
};

#endif	/* EVENT_H */


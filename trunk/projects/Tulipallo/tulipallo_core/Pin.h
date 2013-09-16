/* 
 * File:   Pin.h
 * Author: Robert
 *
 * Created on June 15, 2013, 2:35 PM
 */

#ifndef PIN_H
#define	PIN_H

enum IO_MODE {
    IO_INPUT, IO_OUTPUT
};

enum IO_PULL {
    IO_PULL_OFF, IO_PULL_DOWN, IO_PULL_UP
};

class Pin {
public:
    Pin(const Pin& orig);
    Pin(unsigned int number, IO_MODE mode);
    Pin(unsigned int number, IO_MODE mode, IO_PULL pull);
    
    virtual unsigned int getNumber();
    virtual IO_MODE      getMode();
    virtual IO_PULL      getPull();
    
    virtual bool operator < (const Pin& b) const;
    
    virtual ~Pin();

private:
    unsigned int number;
    IO_MODE      mode;
    IO_PULL      pull;
};

#endif	/* PIN_H */


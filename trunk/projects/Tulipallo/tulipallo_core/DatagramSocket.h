/* 
 * File:   DatagramSocket.h
 * Author: Robert
 *
 * Created on May 20, 2013, 5:45 PM
 */

#ifndef DATAGRAMSOCKET_H
#define	DATAGRAMSOCKET_H

#include <errno.h>
#include <cerrno>
#include <string>
#include <sys/socket.h> 
#include "SocketException.h"
#include "InternetAddress.h"

const int SOCK_SUCCESS = 0;

class DatagramSocket {
public:
    DatagramSocket(std::string address, unsigned short port) 
            throw (SocketException);
    DatagramSocket(InternetAddress address) 
            throw (SocketException);
    
    virtual InternetAddress getAddress() 
            throw (SocketException);
    virtual void            setAddress(InternetAddress address) 
            throw (SocketException);
    virtual int             getSocketDescriptor();
    virtual void            bind()
            throw (SocketException);
    virtual void            close() 
            throw (SocketException);
    
    virtual ~DatagramSocket() 
            throw (SocketException);
    
protected:
    InternetAddress address;
    int             socketDescriptor;
};

#endif	/* DATAGRAMSOCKET_H */


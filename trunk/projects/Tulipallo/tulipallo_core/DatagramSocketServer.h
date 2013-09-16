/* 
 * File:   DatagramSocketServer.h
 * Author: Robert
 *
 * Created on May 20, 2013, 5:54 PM
 */

#ifndef DATAGRAMSOCKETSERVER_H
#define	DATAGRAMSOCKETSERVER_H

#include "DatagramSocket.h"
#include "DatagramPacket.h"
#include "InternetAddress.h"
#include "IllegalArgumentException.h"

class DatagramSocketServer : public DatagramSocket {
public:
    DatagramSocketServer(std::string address, unsigned short port)
            throw (SocketException);
    DatagramSocketServer(InternetAddress address)
            throw (SocketException);
    
    virtual void receive(DatagramPacket* packet) 
            throw (SocketException);
    
    virtual ~DatagramSocketServer()
            throw (SocketException);
    
private:

};

#endif	/* DATAGRAMSOCKETSERVER_H */


/* 
 * File:   DatagramSocketClient.h
 * Author: Robert
 *
 * Created on June 7, 2013, 6:08 PM
 */

#ifndef DATAGRAMSOCKETCLIENT_H
#define	DATAGRAMSOCKETCLIENT_H

#include "DatagramSocket.h"
#include "DatagramPacket.h"

class DatagramSocketClient : public DatagramSocket {
public:
    DatagramSocketClient(std::string address, std::string remote, unsigned short port) 
            throw (SocketException);
    DatagramSocketClient(InternetAddress address, InternetAddress remote) 
            throw (SocketException);
    
    virtual InternetAddress getRemoteAddress() 
            throw (SocketException);
    virtual void            setRemoteAddress(InternetAddress remote) 
            throw (SocketException);
    virtual void send(DatagramPacket* packet) 
            throw (SocketException);
    
    virtual ~DatagramSocketClient() 
            throw (SocketException);
    
private:
    InternetAddress remote;
};

#endif	/* DATAGRAMSOCKETCLIENT_H */


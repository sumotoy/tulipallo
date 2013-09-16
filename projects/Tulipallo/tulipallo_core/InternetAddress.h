/* 
 * File:   INetAddress.h
 * Author: Robert
 *
 * Created on May 25, 2013, 2:26 PM
 */

#ifndef INTERNETADDRESS_H
#define	INTERNETADDRESS_H

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "INetworkAddress.h"
#include "SocketException.h"

class InternetAddress : public INetworkAddress {
public:
    InternetAddress(std::string address, unsigned short port);
    InternetAddress(sockaddr_in address);
    InternetAddress();
    
    virtual std::string    getAddress();
    virtual void           setAddress(std::string address);
    virtual unsigned short getPort();
    virtual void           setPort(unsigned short port);
    virtual sockaddr_in    toSocketAddress();
    
    sockaddr_in createSocketAddress(const std::string &address, 
                                    unsigned short port) {
        sockaddr_in socketAddress;
        socketAddress.sin_family = AF_INET;

        hostent *host;
        if((host = gethostbyname(address.c_str())) == NULL) {
                throw SocketException("Failed to resolve name.");
        }
        
        socketAddress.sin_addr.s_addr = *((unsigned long*)host->h_addr_list[0]);
        socketAddress.sin_port = htons(port);
        
        return socketAddress;
    }
    
    virtual ~InternetAddress();

private:
    std::string    address;
    unsigned short port;
};

#endif	/* INETADDRESS_H */


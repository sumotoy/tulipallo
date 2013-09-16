/* 
 * File:   INetworkAddress.h
 * Author: Robert
 *
 * Created on May 25, 2013, 2:53 PM
 */

#ifndef INETWORKADDRESS_H
#define	INETWORKADDRESS_H

#include <string>
#include <netinet/in.h>

class INetworkAddress {
public:
    INetworkAddress();
    
    virtual std::string    getAddress()      = 0;
    virtual unsigned short getPort()         = 0;
    virtual sockaddr_in    toSocketAddress() = 0;
    
    virtual ~INetworkAddress();
private:

};

#endif	/* INETWORKADDRESS_H */


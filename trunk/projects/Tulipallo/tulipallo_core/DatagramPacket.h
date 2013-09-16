/* 
 * File:   DatagramPacket.h
 * Author: Robert
 *
 * Created on May 25, 2013, 10:31 AM
 */

#ifndef DATAGRAMPACKET_H
#define	DATAGRAMPACKET_H

#include <string>
#include <vector>
#include "InternetAddress.h"
#include "Epsilon.h"
#include "DataStream.h"

class DatagramPacket : public DataStream {
public:
    DatagramPacket();
    DatagramPacket(int packetSize);
    
    virtual InternetAddress   getSourceAddress();
    virtual void              setSourceAddress(InternetAddress address);
    virtual int               getPacketSize();
    virtual void              setPacketSize(int packetSize);
    virtual std::vector<char> getData();
    virtual void              setData(std::vector<char>* data);
    virtual void              clear();
    
    virtual char        getByte();
    virtual void        setByte(int value);
    virtual float       getFloat();
    virtual float       setFloat(float value);
    virtual float       getEpsilonFloat();
    virtual std::string getString(int numberOfBytes);
    virtual void        setString(std::string value);
    virtual void        skip();
    virtual void        skip(int numberOfBytes);
    
    virtual ~DatagramPacket();
    
private:
    std::vector<char> buffer;
    int               packetSize;
    InternetAddress   source;
    Epsilon           epsilon;
};

#endif	/* DATAGRAMPACKET_H */


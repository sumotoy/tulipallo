/*
 * Copyright (c) Robert R. Murrell, 2013. All rights reserved.
 */

#include "SpeedSentence.h"

SpeedSentence::SpeedSentence() : XPlaneSentence() {
    //
}

SpeedSentence::SpeedSentence(float indKias, float indKeas, float trueKtas, 
                             float trueKtgs, float indMph,float trueMphas, 
                             float trueMphgs) : 
                XPlaneSentence() {
    this->indKeas   = indKeas;
    this->indKias   = indKias;
    this->indMph    = indMph;
    this->trueKtas  = trueKtas;
    this->trueKtgs  = trueKtgs;
    this->trueMphas = trueMphas;
    this->trueMphgs = trueMphgs;
}

SpeedSentence::SpeedSentence(const SpeedSentence& orig) : 
                XPlaneSentence(orig) {
    this->indKeas   = orig.indKeas;
    this->indKias   = orig.indKias;
    this->indMph    = orig.indMph;
    this->trueKtas  = orig.trueKtas;
    this->trueKtgs  = orig.trueKtgs;
    this->trueMphas = orig.trueMphas;
    this->trueMphgs = orig.trueMphgs;
}

float SpeedSentence::getVindKias() {
    return this->indKias;
}

float SpeedSentence::getVindKeas() {
    return this->indKeas;
}

float SpeedSentence::getVtrueKtas() {
    return this->trueKtas;
}

float SpeedSentence::getVtrueKtgs() {
    return this->trueKtgs;
}

float SpeedSentence::getVindMph() {
    return this->indMph;
}

float SpeedSentence::getVtrueMphas() {
    return this->trueMphas;
}

float SpeedSentence::getVtrueMphgs() {
    return this->trueMphgs;
}

int SpeedSentence::getCommand() {
    return SPEED_COMMAND;
}

void SpeedSentence::unmarshall(DataStream* stream) 
                throw (MarshallingException) {
    this->indKias   = stream->getEpsilonFloat();
    this->indKeas   = stream->getEpsilonFloat();
    this->trueKtas  = stream->getEpsilonFloat();
    this->trueKtgs  = stream->getEpsilonFloat();
    stream->skip(4);
    this->indMph    = stream->getEpsilonFloat();
    this->trueMphas = stream->getEpsilonFloat();
    this->trueMphgs = stream->getEpsilonFloat();
}

void SpeedSentence::marshall(DataStream* stream) 
                throw (MarshallingException) {
    XPlaneSentence::marshall(stream);
    
    stream->setFloat(this->indKias);
    stream->setFloat(this->indKeas);
    stream->setFloat(this->trueKtas);
    stream->setFloat(this->trueKtgs);
    stream->setFloat(0.0f);
    stream->setFloat(this->indMph);
    stream->setFloat(this->trueMphas);
    stream->setFloat(this->trueMphgs);
}

std::string SpeedSentence::toString() {
    std::stringstream output;
    
    output << "SpeedSentence: Vind-Keas=" << this->indKeas 
           << ", Vind-Kias="              << this->indKias
           << ", Vtrue-Ktas="             << this->trueKtas 
           << ", Vtrue-Ktgs="             << this->trueKtgs 
           << ", Vind-Mph="               << this->indMph 
           << ", Vtrue-Mphas="            << this->trueMphas 
           << ", Vtrue-Mphgs="            << this->trueMphgs << "\r\n";
    
    return output.str();
}

SpeedSentence::~SpeedSentence() {
}


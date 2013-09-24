/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 */

#ifndef XPLANESLIPINDICATOR_H
#define	XPLANESLIPINDICATOR_H

#include "../tulipallo_control/ISlipIndicator.h"
#include "../tulipallo_core/Thread.h"
#include "../tulipallo_xplane/ISentenceListener.h"
#include "../tulipallo_xplane/SlipSentence.h"
#include "../tulipallo_core/Context.h"
#include "../tulipallo_xplane/MessageHandler.h"

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics<br />
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 * 
 * @author Robert R Murrell
 * @version 1.0 beta
 */
class XPlaneSlipIndicator : public ISlipIndicator, public ISentenceListener {
public:
    XPlaneSlipIndicator();
    
    virtual Slip getSlip();
    virtual void handleSentenceReceived(SentenceReceivedEvent event);
    
    virtual ~XPlaneSlipIndicator();
    
private:
    Slip*            slip;
    pthread_mutex_t* mutex;
};

#endif	/* XPLANESLIPINDICATOR_H */


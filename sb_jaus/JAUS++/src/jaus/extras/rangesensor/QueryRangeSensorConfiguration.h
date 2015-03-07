////////////////////////////////////////////////////////////////////////////////////
///
///  \file QueryRangeSensorConfiguration.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Daniel Barber
///  Created: 8 March 2010
///  Copyright (c) 2010
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: dbarber@ist.ucf.edu
///  <br>Web:  http://active.ist.ucf.edu
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///      * Redistributions of source code must retain the above copyright
///        notice, this list of conditions and the following disclaimer.
///      * Redistributions in binary form must reproduce the above copyright
///        notice, this list of conditions and the following disclaimer in the
///        documentation and/or other materials provided with the distribution.
///      * Neither the name of the ACTIVE LAB, IST, UCF, nor the
///        names of its contributors may be used to endorse or promote products
///        derived from this software without specific prior written permission.
/// 
///  THIS SOFTWARE IS PROVIDED BY THE ACTIVE LAB''AS IS'' AND ANY
///  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL UCF BE LIABLE FOR ANY
///  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
///  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
///  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
///  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
///  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
///  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
////////////////////////////////////////////////////////////////////////////////////
#ifndef __JAUS_EXTRAS_RANGE_SENSOR_QUERY_RANGE_SENSOR_CONFIGURATION__H
#define __JAUS_EXTRAS_RANGE_SENSOR_QUERY_RANGE_SENSOR_CONFIGURATION__H

#ifndef JPP_IGNORE_DEPRECATED
#pragma message("JAUS++ EXTRAS DEPRECATED - Use New Range Sensor in Environment Library")
#endif

#include "jaus/extras/ExtrasCodes.h"
#include "jaus/core/Message.h"
#include "jaus/extras/rangesensor/ReportRangeSensorConfiguration.h"

namespace JAUS
{
    const UShort QUERY_RANGE_SENSOR_CONFIGURATION_EXTRAS                 =   0xD30A; ///<  Message code.
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class QueryRangeSensorConfiguration
    ///   \brief This message allows a component to query the configuration of
    ///          range sensors.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_EXTRAS_DLL QueryRangeSensorConfiguration : public Message
    {
    public:
        QueryRangeSensorConfiguration(const Address& dest = Address(), 
                                      const Address& src = Address()) : Message(QUERY_RANGE_SENSOR_CONFIGURATION_EXTRAS, dest, src)
        {
        }
        QueryRangeSensorConfiguration(const QueryRangeSensorConfiguration& message) : Message(QUERY_RANGE_SENSOR_CONFIGURATION_EXTRAS)
        {
            *this = message;
        }
        ~QueryRangeSensorConfiguration() {}  
        virtual bool IsCommand() const { return false; }
        virtual int WriteMessageBody(Packet& packet) const { return 0; }
        virtual int ReadMessageBody(const Packet& packet) { return 0; }
        virtual Message* Clone() const { return new QueryRangeSensorConfiguration(*this); }
        virtual UInt GetPresenceVector() const { return 0; }
        virtual UInt GetPresenceVectorSize() const { return 0; }
        virtual UInt GetPresenceVectorMask() const { return 0; }
        virtual UShort GetMessageCodeOfResponse() const { return REPORT_RANGE_SENSOR_CONFIGURATION_EXTRAS; }
        virtual std::string GetMessageName() const { return "Query Range Sensor Configuration"; }
        virtual void ClearMessageBody() {}
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize) const { return false; }
        QueryRangeSensorConfiguration& operator=(const QueryRangeSensorConfiguration& message)
        {
            CopyHeaderData(&message);
            return *this;
        }
    };
}

#endif
/*  End of File */
////////////////////////////////////////////////////////////////////////////////////
///
///  \file SetLocalVector.h
///  \brief This file contains the implementation of a JAUS message.
///
///  <br>Author(s): Bo Sun
///  <br>Created: 25 November 2009
///  <br>Copyright (c) 2009
///  <br>Applied Cognition and Training in Immersive Virtual Environments
///  <br>(ACTIVE) Laboratory
///  <br>Institute for Simulation and Training (IST)
///  <br>University of Central Florida (UCF)
///  <br>All rights reserved.
///  <br>Email: bsun@ist.ucf.edu
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
#ifndef __JAUS_MOBILITY_SET_LOCAL_VECTOR__H
#define __JAUS_MOBILITY_SET_LOCAL_VECTOR__H

#include "jaus/core/Message.h"
#include "jaus/mobility/MobilityCodes.h"

namespace JAUS
{
    ////////////////////////////////////////////////////////////////////////////////////
    ///
    ///   \class SetLocalVector
    ///   \brief This message is used to set the driving vector based on the local
    ///          coordinate system.  Field #2 sets the desired speed of the platform.
    ///          The desired heading angel is set in field #4 and is defined in a right
    ///          hand sense about the Z axis of the local coordinate system (the Z axis
    ///          points downward) where zero degrees defines a heading that is parallel
    ///          to the X aaxis of the local coordinate system.
    ///
    ////////////////////////////////////////////////////////////////////////////////////
    class JAUS_MOBILITY_DLL SetLocalVector : public Message
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////////
        ///
        ///   \class PresenceVector
        ///   \brief This class contains bit masks for bitwise operations on the
        ///          presence vector for this message.
        ///
        ////////////////////////////////////////////////////////////////////////////////////
        class JAUS_MOBILITY_DLL PresenceVector : public JAUS::PresenceVector
        {
        public:
            const static Byte Speed = 0x01;
            const static Byte Z = 0x02;
            const static Byte Heading = 0x04;
            const static Byte Roll = 0x08;
            const static Byte Pitch = 0x10;
        };
        ////////////////////////////////////////////////////////////////////////////////////
        ///
        ///   \class Limits
        ///   \brief Contains constants for limit values of data members of class.
        ///
        ////////////////////////////////////////////////////////////////////////////////////
        class JAUS_MOBILITY_DLL Limits : public JAUS::Limits
        {
        public:
            const static double MinSpeed;       ///<  Minimum speed. (0)
            const static double MaxSpeed;       ///<  Maximum speed. (327.67)
            const static double MinElevation;   ///<  Minimum altitude. (-10000)
            const static double MaxElevation;   ///<  Maximum altitude. (35000)
            const static double MinAngle;       ///<  Minimum angle value in radians. (-PI)
            const static double MaxAngle;       ///<  Maximum angle value in radians. (PI)
        };
        SetLocalVector(const Address& dest = Address(), const Address& src = Address());
        SetLocalVector(const SetLocalVector& message);
        ~SetLocalVector();
        bool SetSpeed(const double value);
        bool SetZ(const double value);
        bool SetHeading(const double radians);
        bool SetRoll(const double radians);
        bool SetPitch(const double radians);
        inline double GetSpeed() const { return mSpeed; }
        inline double GetZ() const { return mZ; }
        inline double GetHeading() const { return mHeading; }
        inline double GetRoll() const { return mRoll; }
        inline double GetPitch() const { return mPitch; }
        virtual bool IsCommand() const { return true; }
        virtual int WriteMessageBody(Packet& packet) const;
        virtual int ReadMessageBody(const Packet& packet);
        virtual Message* Clone() const { return new SetLocalVector(*this); }
        virtual UInt GetPresenceVector() const { return mPresenceVector; }
        virtual UInt GetPresenceVectorSize() const { return BYTE_SIZE; }
        virtual UInt GetPresenceVectorMask() const { return 0x1F; }
        virtual UShort GetMessageCodeOfResponse() const { return 0; }
        virtual std::string GetMessageName() const { return "Set Local Vector"; }        
        virtual void ClearMessageBody();
        virtual bool IsLargeDataSet(const unsigned int maxPayloadSize = 1437) const { return false; }
        virtual int RunTestCase() const;
        SetLocalVector& operator=(const SetLocalVector& message);
    protected:
        Byte mPresenceVector;                   ///<  Bit vector for fields present.
        double mSpeed;                          ///<  Speed in m/s [0, 327.67].
        double mZ;                              ///<  Z Axis in m [-10000, 35000].
        double mHeading;                        ///<  Heading in radians [-PI, PI].
        double mRoll;                           ///<  Roll in radians [-PI, PI].
        double mPitch;                          ///<  Pitch in radians [-PI, PI].

    };
}

#endif
/*  End of File */

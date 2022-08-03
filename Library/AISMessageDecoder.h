/*
    Copyright(c) 2021-2022 jvde.github@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <iomanip>

#include "Stream.h"
#include "Property.h"
#include "AIS.h"
#include "Signals.h"

namespace AIS
{
    class AISMessageDecoder : public StreamIn<Message>, public PropertyStreamOut
    {
	void ProcessMsg8Data(const AIS::Message &msg, int len);

    protected:

        void U(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
            unsigned u = msg.getUint(start, len);
            if (u != undefined)
                Submit(p, u);
        }

        void S(const AIS::Message& msg, int p, int start, int len, int undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, u);
        }

        void E(const AIS::Message& msg, int p, int start, int len, int pmap = 0, const std::vector<std::string> *map = NULL)
        {
            unsigned u = msg.getUint(start, len);
	    Submit(p,u);
            if(map)
	    {
		if(u < map->size()) 
			Submit(pmap, (*map)[u]);
		else
			Submit(pmap, std::string("Undefined") );
	    }
        }

        void TURN(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
            int u = msg.getInt(start, len);

            if (u == -128) Submit(p, std::string("nan") );
            else if (u == -127) Submit(p, std::string("fastleft") );
            else if (u == 127) Submit(p, std::string("fastright") );
            else
            {
		double rot = u / 4.733;
		rot = (u<0) ? -rot * rot : rot * rot;
            	Submit(p,(int)(rot+0.5));
            }
        }

        void TIMESTAMP(const AIS::Message& msg, int p, int start, int len)
	{
		if(len != 40) return;

		std::stringstream s;
		s << std::setfill('0') << std::setw(4) << msg.getUint(start,14) << "-" << std::setw(2) << msg.getUint(start+14,4) << "-" << std::setw(2) << msg.getUint(start+18,5) << "T"
		  << std::setw(2) <<  msg.getUint(start+23,5) << ":" << std::setw(2) << msg.getUint(start+28,6) << ":" << std::setw(2) << msg.getUint(start+34,6) << "Z";
		Submit(p, std::string(s.str())) ;
	}

        void ETA(const AIS::Message& msg, int p, int start, int len)
	{
		if(len != 20) return;

		std::stringstream s;
		s << std::setfill('0') << std::setw(2) << msg.getUint(start,4) << "-" << std::setw(2) << msg.getUint(start+4,5) << "T"
		  << std::setw(2) <<  msg.getUint(start+9,5) << ":" << std::setw(2) << msg.getUint(start+14,6) << "Z";
		Submit(p, std::string(s.str())) ;
	}

        void U1(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
            unsigned u = msg.getUint(start, len);
            if (u != undefined)
                Submit(p, (float) (u / 10.0) );
        }

        void S1(const AIS::Message& msg, int p, int start, int len, int undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, (float) (u / 10.0) );
        }


        void S2(const AIS::Message& msg, int p, int start, int len, int undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, (float) (u / 100.0) );
        }

        void I1(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, (float) (u / 10.0) );
        }

        void POS(const AIS::Message& msg, int p, int start, int len, int undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, (float)(u / 600000.0) );
        }

        void POS1(const AIS::Message& msg, int p, int start, int len, int undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, (float)(u / 600.0) );
        }

        void POS2(const AIS::Message& msg, int p, int start, int len, int undefined = ~0)
        {
            int u = msg.getInt(start, len);
            if (u != undefined)
                Submit(p, (float)(u / 60000.0) );
        }

        void W(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
            int u = msg.getUint(start, len);
            if (u != undefined)
                Submit(p, (float)(u / 100.0 - 10.0) );
        }

        void P(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
            int u = msg.getUint(start, len);
            if (u != undefined)
                Submit(p, u+799);
        }

        void B(const AIS::Message& msg, int p, int start, int len)
        {
            unsigned u = msg.getUint(start, len);
            Submit(p, (bool)u);
        }

        void X(const AIS::Message& msg, int p, int start, int len, unsigned undefined = ~0)
        {
        }

        void T(const AIS::Message& msg, int p, int start, int len)
        {
            std::string text = msg.getText(start, len);
            while(text[text.length()-1]==' ') text.resize(text.length()-1);
            Submit(p, text);
        }

        void D(const AIS::Message& msg, int p, int start, int len)
        {
            std::string text = msg.getText(start, len);
            while(text[text.length()-1]==' ') text.resize(text.length()-1);
            Submit(p, text);
        }

    public:

        void Receive(const AIS::Message* data, int len, TAG& tag);
    };

    extern const std::vector<std::string> PROPERTY_MAP_STATUS;
    extern const std::vector<std::string> PROPERTY_MAP_EPFD;
    extern const std::vector<std::string> PROPERTY_MAP_SHIPTYPE;
    extern const std::vector<std::string> PROPERTY_MAP_AID_TYPE;
}
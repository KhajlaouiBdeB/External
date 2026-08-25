#ifndef REGULATOR
#define REGULATOR
//------------------------------------------------------------------------
//
//  Name:   Regulator.h
//
//  Desc:   Use this class to regulate code flow (for an update function say)
//          Instantiate the class with the frequency you would like your code
//          section to flow (like 10 times per second) and then only allow
//          the program flow to continue if Ready() returns true
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "misc/utils.h"

namespace Common
{
    class Regulator
    {
      private:
        // the time period between updates
        double m_dUpdatePeriod;

        // the next time (in ms, raylib clock) the regulator allows code flow
        double m_dwNextUpdateTime;

      public:
        Regulator(double NumUpdatesPerSecondRqd);

        // returns true if the current time exceeds m_dwNextUpdateTime
        bool isReady();
    };

} // namespace Common

#endif

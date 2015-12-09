/*
 * zaplist.h: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#ifndef __ZAPLIST_H
#define __ZAPLIST_H

#include <vdr/channels.h>
#include <vdr/status.h>

#include "setup-zaphistory.h"
#include "zaphistorychannel.h"

class cZapHistory;

extern cZapHistory ZapHistory;

class cZapHistory : public cConfig<cZapHistoryChannel> {
    private:
	    cZapHistoryChannel *currentChannel;	
	    time_t lastSwitch;

#if APIVERSNUM >= 20301
	    cZapHistoryChannel* FindChannel( const cChannel *channel );
#else
	    cZapHistoryChannel* FindChannel( cChannel *channel );
#endif
	    cZapHistorySortMode sortMode;

	    void UpdateHistory( cZapHistoryChannel *zapChan);
    public:
	    cZapHistory();
#if APIVERSNUM >= 20301
        void ChannelSwitch( const cChannel *channel );
#else
        void ChannelSwitch( cChannel *channel );
#endif
	    void ViewInterrupted();
	    void ViewContinue();
	    void UpdateWatchTime();
	    cZapHistorySortMode GetSortMode();
	    void SetSortMode( cZapHistorySortMode mode );
	    void Reset(cZapHistoryChannel *zapChan = NULL, bool statisticOnly = true);
};

#endif

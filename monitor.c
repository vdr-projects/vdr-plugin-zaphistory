/*
 * monitor.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/eitscan.h>
#include <vdr/channels.h>

#include "monitor.h"
#include "setup-zaphistory.h"
#include "zaphistory.h"

void cZapHistoryMonitor::ChannelSwitch(const cDevice *Device, int ChannelNumber, bool LiveView)
{
    // Inform history, that channel has been switched
    if (ChannelNumber > 0 && Device->IsPrimaryDevice() && LiveView )
    {
#if APIVERSNUM >= 20301
        LOCK_CHANNELS_READ;
        ZapHistory.ChannelSwitch( Channels->GetByNumber (ChannelNumber) );
#else
        ZapHistory.ChannelSwitch( Channels.GetByNumber (ChannelNumber) );
#endif
    }
}

void cZapHistoryMonitor::Replaying(const cControl *Control, const char *Name, const char *FileName, bool On) {
    // Inform history, that live viewing has been started/stopped
    if (On)
	    ZapHistory.ViewInterrupted();
    else
	    ZapHistory.ViewContinue();
}

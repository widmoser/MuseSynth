//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2008-2011 Werner Schweer
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENCE.GPL
//=============================================================================

#include "event.h"
#include <QString>

namespace Ms {

//---------------------------------------------------------
//   isChannelEvent
//---------------------------------------------------------

bool MidiCoreEvent::isChannelEvent() const
      {
      switch(_type) {
            case ME_NOTEOFF:
            case ME_NOTEON:
            case ME_POLYAFTER:
            case ME_CONTROLLER:
            case ME_PROGRAM:
            case ME_AFTERTOUCH:
            case ME_PITCHBEND:
            case ME_NOTE:
            case ME_CHORD:
                  return true;
            default:
                  return false;
            }

      // Prevent "unreachable code" warning.
      // return false;
      }

//---------------------------------------------------------
//    midi_meta_name
//---------------------------------------------------------

QString midiMetaName(int meta)
      {
      const char* s = "";
      switch (meta) {
            case 0:     s = "Sequence Number"; break;
            case 1:     s = "Text Event"; break;
            case 2:     s = "Copyright"; break;
            case 3:     s = "Sequence/Track Name"; break;
            case 4:     s = "Instrument Name"; break;
            case 5:     s = "Lyric"; break;
            case 6:     s = "Marker"; break;
            case 7:     s = "Cue Point"; break;
            case 8:
            case 9:
            case 0x0a:
            case 0x0b:
            case 0x0c:
            case 0x0d:
            case 0x0e:
            case 0x0f:  s = "Text"; break;
            case 0x20:  s = "Channel Prefix"; break;
            case 0x21:  s = "Port Change"; break;
            case 0x2f:  s = "End of Track"; break;
            case META_TEMPO:  s = "Tempo"; break;
            case 0x54:  s = "SMPTE Offset"; break;
            case META_TIME_SIGNATURE:  s = "Time Signature"; break;
            case META_KEY_SIGNATURE:   s = "Key Signature"; break;
            case 0x74:                 s = "Sequencer-Specific1"; break;
            case 0x7f:                 s = "Sequencer-Specific2"; break;
            default:
                  break;
            }
      return QString(s);
      }

}

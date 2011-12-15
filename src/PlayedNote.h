#ifndef PLAYED_NOTE
#define PLAYED_NOTE

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <jack/jack.h>
#include <jack/transport.h>

#include "Note.h"

class PlayedNote {
private:
	Note note;
	jack_nframes_t noteLength;
	jack_default_audio_sample_t * wave;
	static const unsigned int noteSeconds = 4;
	static const double PI = 3.14159265359;
	static const double MaxAmp = 1;

public:
	PlayedNote(const Note& note, unsigned long sampleRate, double maxAmp);
	~PlayedNote();
	Note getNote();
	jack_nframes_t getNoteLength();
	jack_default_audio_sample_t * getWave();
};
#endif

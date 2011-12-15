#ifndef JACK_BY_THE_NOTES
#define JACK_BY_THE_NOTES
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
//#include <queue>
#include <deque>

#include "PlayedNote.h"

class JackByTheNotes {
private:
	static const double PI = 3.14159265359;
	static const double MaxAmp = 0.5;
	static const int noteSeconds = 4;

	jack_client_t * client;
	jack_port_t * outputPort;
	unsigned long sampleRate;
	int bpm;
	jack_nframes_t waveLength;
	jack_default_audio_sample_t *wave;
	long offset;
	jack_transport_state_t transport_state;
	time_t seconds;
	int newNote;
	pthread_t messenger;
	std::deque<PlayedNote> currentNotes;

	// std::priority_queue<Note> currentNotes;

public:
	JackByTheNotes();

	void activate();
	void play(jack_nframes_t nframes);
	void playNote(Note note);
	void connect();
	static void * startConnection(void * instance);
};

int processAll(jack_nframes_t nframes, void * arg);
#endif

#include "JackByTheNotes.h"
#include <iostream>

JackByTheNotes::JackByTheNotes() {
	const char * client_name = "Piano";
	if ((client = jack_client_new(client_name)) == 0) {
		fprintf(stderr, "jack server unavailable\n");
		return;
	}
	jack_set_process_callback(client, ::processAll, this);
	outputPort = jack_port_register(client, "Rubinstein", JACK_DEFAULT_AUDIO_TYPE,
			JackPortIsOutput, 0);

	sampleRate = jack_get_sample_rate(client);
	waveLength = noteSeconds * sampleRate;
	wave = (jack_default_audio_sample_t *) malloc(
			waveLength * sizeof(jack_default_audio_sample_t));
	for (int i = 0; i < (int) waveLength; i++) {
		wave[i] = 0;
	}

	offset = 0;
}

int processAll(jack_nframes_t nframes, void * arg) {
	JackByTheNotes * jackByTheNotes = static_cast<JackByTheNotes *>(arg);
	jackByTheNotes->play(nframes);
	return 0;
}

void JackByTheNotes::play(jack_nframes_t nframes) {
	jack_default_audio_sample_t * buffer =
			(jack_default_audio_sample_t *) jack_port_get_buffer(outputPort,
					nframes);
	jack_nframes_t framesLeft = nframes;

	while (waveLength - offset < framesLeft) {
		memcpy(buffer + (nframes - framesLeft), wave + offset,
				sizeof(jack_default_audio_sample_t) * (waveLength - offset));
		memset(wave + offset, 0,
				sizeof(jack_default_audio_sample_t) * (waveLength - offset));
		framesLeft -= waveLength - offset;
		offset = 0;
	}
	if (framesLeft > 0) {
		memcpy(buffer + (nframes - framesLeft), wave + offset,
				sizeof(jack_default_audio_sample_t) * framesLeft);
		memset(wave + offset, 0,
				sizeof(jack_default_audio_sample_t) * framesLeft);
		offset += framesLeft;
	}
}

void JackByTheNotes::playNote(Note note) {
	PlayedNote playedNote(note, sampleRate, MaxAmp);

	//std::cout<<(long)waveLength<<" "<<offset<<std::endl;
	for (long i = 0; i < (int) waveLength; i++) {
		//if (wave[(offset + i) % (long)waveLength] != 0) {
		//  std::cout<<wave[(offset + i) % (long)waveLength]<<std::endl;
		//}
		wave[(offset + i) % (int) waveLength] += playedNote.getWave()[i];
		//    if (i % 100 == 0) std::cout<<playedNote.getWave()[i]<<std::endl;
	}
}

void JackByTheNotes::activate() {
	if (jack_activate(client)) {
		fprintf(stderr, "Activate failure\n");
	}
	while (1) {
		sleep(1);
	}
}

void JackByTheNotes::connect() {
	pthread_create(&messenger, 0, &startConnection, this);
}

void * JackByTheNotes::startConnection(void * instance) {
	reinterpret_cast<JackByTheNotes *>(instance)->activate();
}

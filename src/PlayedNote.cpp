#include "PlayedNote.h"
#include <iostream>

PlayedNote::PlayedNote(const Note& note, unsigned long sampleRate,
		double maxAmp) :
		note(note) {
	double * amp;
	noteLength = noteSeconds * sampleRate;
	wave = (jack_default_audio_sample_t *) malloc(
			noteLength * sizeof(jack_default_audio_sample_t));
	for (int i = 0; i < (int) noteLength; i++) {
		wave[i] = 0;
	}
	jack_nframes_t attackLength = noteLength * note.getAttackPercent() / 100;
	jack_nframes_t decayLength = noteLength * note.getDecayPercent() / 100;
	jack_default_audio_sample_t scale = 2 * PI * note.getFrequency()
			/ sampleRate;
	jack_default_audio_sample_t scaleLow = PI * note.getFrequency()
			/ sampleRate;
	jack_default_audio_sample_t scaleHigh = 4 * PI * note.getFrequency()
			/ sampleRate;
	jack_default_audio_sample_t scaleSharp = 8 * PI * note.getFrequency()
			/ sampleRate;
	amp = (double *) malloc(noteLength * sizeof(double));
	std::cout << attackLength << " " << decayLength << " " << scale
			<< std::endl;

	for (int i = 0; i < (int) attackLength; i++) {
		amp[i] = maxAmp * i / ((double) attackLength);
	}

	for (int i = (int) attackLength; i < (int) noteLength - decayLength; i++) {
		amp[i] = maxAmp;
	}

	for (int i = (int) noteLength - decayLength; i < (int) noteLength; i++) {
		amp[i] = (-1) * maxAmp
				* ((i - (double) noteLength) / ((double) decayLength))
				* (i - (double) noteLength) / ((double) decayLength);
	}

	for (int i = 0; i < (int) noteLength; i++) {
		wave[i] += amp[i] * sin(scale * i);
		wave[i] += amp[i] * sin(scaleLow * i) * 0.7;
		wave[i] += amp[i] * sin(scaleHigh * i) * 0.7;
		wave[i] += amp[i] * sin(scaleSharp * i) * 0.5;
		//std::cout<<amp[i]<<" ";
	}

	free(amp);

}

PlayedNote::~PlayedNote() {
	free(wave);
}

Note PlayedNote::getNote() {
	return note;
}

jack_nframes_t PlayedNote::getNoteLength() {
	return noteLength;
}

jack_default_audio_sample_t * PlayedNote::getWave() {
	return wave;
}

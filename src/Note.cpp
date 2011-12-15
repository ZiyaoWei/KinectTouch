#include "Note.h"

Note::Note(unsigned int frequency, double volume = 100, unsigned int duration =
		300) :
		frequency(frequency), volume(volume), duration(duration), attackPercent(
				4), decayPercent(95) {
}

bool Note::setFrequency(unsigned int frequency) {
	if ((frequency < 20) || (frequency > 20000)) {
		return false;
	} else {
		this->frequency = frequency;
		return true;
	}
}

bool Note::setVolume(double volume) {
	if ((volume < 0) || (volume > 1)) {
		return false;
	} else {
		this->volume = volume;
		return true;
	}
}

bool Note::setDuration(unsigned int duration) {
	if (duration < 0) {
		return false;
	} else {
		this->duration = duration;
		return true;
	}
}

bool Note::setAttackPercent(unsigned int attackPercent) {
	if ((attackPercent < 0) || (attackPercent > 100)) {
		return false;
	} else {
		this->attackPercent = attackPercent;
		return true;
	}
}

bool Note::setDecayPercent(unsigned int decayPercent) {
	if ((decayPercent < 0) || (decayPercent > 100)) {
		return false;
	} else {
		this->decayPercent = decayPercent;
		return true;
	}
}

unsigned int Note::getFrequency() const {
	return frequency;
}

double Note::getVolume() const {
	return volume;
}

unsigned int Note::getDuration() const {
	return duration;
}

unsigned int Note::getAttackPercent() const {
	return attackPercent;
}

unsigned int Note::getDecayPercent() const {
	return decayPercent;
}

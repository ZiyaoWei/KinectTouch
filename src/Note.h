/**
 * Basic Note class, the attack/decay could be set on a note-by-note basis.
 * Terminologies:
 * 	Attack: The time period in which the note becomes louder
 * 	Decay: The opposite time period of attack
 */
#ifndef NOTES
#define NOTES
class Note {
private:

	// Between 20 and 20000
	unsigned int frequency;

	// Between 0 and 1
	double volume;

	// In milliseconds
	unsigned int duration;

	// Between 0 and 100
	unsigned int attackPercent;

	// Between 0 and 100
	unsigned int decayPercent;

public:
	Note(unsigned int frequency, double volume, unsigned int duration);

	// Bool return value indicates if the value is legal
	bool setFrequency(unsigned int frequency);
	bool setVolume(double volume);
	bool setDuration(unsigned int duration);
	bool setAttackPercent(unsigned int attackPercent);
	bool setDecayPercent(unsigned int decayPercent);

	unsigned int getFrequency() const;
	double getVolume() const;
	unsigned int getDuration() const;
	unsigned int getAttackPercent() const;
	unsigned int getDecayPercent() const;

};
#endif

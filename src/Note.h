#ifndef NOTES
#define NOTES
class Note {
 private:
  unsigned int frequency;
  double volume;
  unsigned int duration;
  unsigned int attackPercent;
  unsigned int decayPercent;

 public:
  Note(unsigned int frequency, double volume, unsigned int duration);

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

#include <iostream>
#include "Node.h"
#include <vector>

using namespace std;

class Keyboard {

public:

	Node*** mapping;

	/* need to subtract boundary on the screen,
	 i.e. matrix boundary starts at 0, but keyboard boundary starts at 50
	 */
// the stride is the width of a white key
	void preProcess(vector<float> &sharp, vector<float> &plain, Node ***mapping,
			int stride, int height) {
		int black_count = 0;
		int i = 1; // calculate position
		// deal with black first
		while (i < 10) {
			if (i == 3 || i == 7) {
				i++;
				continue;
			}
			int left = i * stride - stride / 3;
			int right = i * stride + stride / 3;
			int lower = height / 2;
			for (int j = 0; j < height / 2; j++) {
				for (int k = left; k < right; k++) {
					mapping[j][k]->freq = sharp[black_count];
					//cout << "x: " << k << ", y: " << j << "freq: " << mapping[j][k]->freq << endl;
				}
			}
			black_count++;
			i++;
		}

		int lBound = 0;
		int rBound = stride;
		// deal with white keys
		for (int w = 0; w <= 10; w++) {
			for (int x = 0; x < height; x++) {
				//cout << "w is: " << w << " x is: " << x << endl;
				for (int y = lBound; y < rBound; y++) {
					if (mapping[x][y]->freq == -1) {
						mapping[x][y]->freq = plain[w];
					}
				}
			}
			lBound += stride;
			rBound += stride;
		}
	}

	double keyFrequency(int x, int y) {
		return mapping[x][y]->freq;
	}

	void initKeyMap() {
		int rows = 250;
		int cols = 550;

		// notes mapping
		mapping = new Node **[rows];
		for (int i = 0; i < rows; i++) {
			mapping[i] = new Node *[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				mapping[i][j] = new Node(i, j, -1);
			}
		}

		// vector stores key frequencies in Hz
		// sample keys start from (C0 ~ E1)
		vector<float> plain_tunes;
		vector<float> sharp_tunes;
		plain_tunes.push_back(261.63); // C4
		sharp_tunes.push_back(277.18); // C#4
		plain_tunes.push_back(293.66); // D4
		sharp_tunes.push_back(311.13); // D#4
		plain_tunes.push_back(329.63); // E4
		plain_tunes.push_back(349.23); // F4
		sharp_tunes.push_back(369.99); // F#4
		plain_tunes.push_back(392.00); // G4
		sharp_tunes.push_back(415.30); // G#4
		plain_tunes.push_back(440.00); // A4
		sharp_tunes.push_back(466.16); // A#4
		plain_tunes.push_back(493.88); // B4
		plain_tunes.push_back(523.25); // C5
		sharp_tunes.push_back(554.37); // C#5
		plain_tunes.push_back(587.33); // D5
		sharp_tunes.push_back(622.25); // D#5
		plain_tunes.push_back(659.26); // E5

		int stride = 50;
		int height = 250;
		preProcess(sharp_tunes, plain_tunes, mapping, stride, height);
	}
};

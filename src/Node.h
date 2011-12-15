#ifndef PointStructure_h
#define PointStructure_h

// openCV
#include <opencv/cv.h>
using namespace cv;

struct Node {
	Point2i pos; // position
	float freq; // sound frequency

	// Constructors
	Node(int x, int y) :
			pos(x, y), freq(-1) {
	}

	Node(Point2i position, float frequency) :
			pos(position), freq(frequency) {
	}

	Node(int x, int y, float frequency) :
			pos(x, y), freq(frequency) {
	}
};

#endif

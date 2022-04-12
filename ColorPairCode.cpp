#include "ColorPairCode.hpp"
#include <string>

#define MAXIMUMCOLORPAIR 25
namespace TelCoColorCoder
{
	int numberOfMajorColors =
		sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

	int numberOfMinorColors =
		sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

	ColorPair GetColorFromPairNumber(int pairNumber) {
		int zeroBasedPairNumber = pairNumber - 1;
		MajorColor majorColor =
			(MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
		MinorColor minorColor =
			(MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
		return ColorPair(majorColor, minorColor);
	}
	int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
		return major * numberOfMinorColors + minor + 1;
	}

	void displayReferenceManual() {
		std::cout << " pair number to  color code  \n" << std::endl;
		for (int pairNumber = 0 ; pairNumber < MAXIMUMCOLORPAIR; pairNumber++)
		{
			MajorColor majorColor = (MajorColor)(pairNumber / numberOfMinorColors);
			MinorColor minorColor = (MinorColor)(pairNumber % numberOfMinorColors);

			std::cout << pairNumber+1 << " = " <<"majorColor is " << MajorColorNames[majorColor] << " and "<< "minorColor is " << MinorColorNames[minorColor] << std::endl;
		}
	}
}

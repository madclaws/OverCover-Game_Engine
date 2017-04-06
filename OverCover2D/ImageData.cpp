#include "ImageData.h"

namespace OverCover2D {
	void ImageData::FillData(unsigned char* loc, GLint width, GLint height)
	{
		FILELOC = loc;
		WIDTH = width;
		HEIGHT = height;
	}
}

/**
 * @file ImageCLR.h
 * @author LinhengXilan
 * @version 0.0.0.2
 * @date 2026-1-8
 */

#ifndef IMAGECLR_H
#define IMAGECLR_H

using namespace System;
using namespace System::Collections::Generic;

#include <Image/Image.h>

namespace ImageCLR
{
	public ref class Image
	{
	public:
		Image();

	public:
		property int Height
		{
			int get();
		}
		property int Width
		{
			int get();
		}
		property int Stride
		{
			int get();
		}
		property array<Byte>^ Data
		{
			array<Byte>^ get();
		}

	private:
		// Backing fields for properties to avoid recursive calls
		int m_Height;
		int m_Width;
		int m_Stride;
		array<Byte>^ m_Data;
		ImageHandle::Image* m_Image;

	public:
		void LoadImage(System::String^ imagePath);
	};
}

#endif
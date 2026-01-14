/**
 * @file ImageCLR.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#ifndef IMAGECLR_H
#define IMAGECLR_H

using namespace System;
using namespace System::Collections::Generic;

#include <Image/Processor.h>

namespace ImageCLR
{
	public ref class Processor
	{
	public:
		Processor();

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
		property bool IsProcessed
		{
			bool get();
		}
		property array<Byte>^ OriginalData
		{
			array<Byte>^ get();
		}
		property array<Byte>^ ProcessedData
		{
			array<Byte>^ get();
		}

	public:
		void LoadImage(String^ filepath);
		void Start();

	private:
		ImageHandle::Processor* m_Processor;
		array<Byte>^ m_OriginalData;
		array<Byte>^ m_ProcessedData;
	};
}

#endif
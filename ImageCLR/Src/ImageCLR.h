#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace ImageCLR
{
	public ref class Point
	{
	public:
		Point();
		Point(int x, int y);

	public:
		String^ ToString() override;

	public:
		int X;
		int Y;
	};

	public ref class ContourFinder
	{
	public:
		property int Rows
		{
			int get();
		}
		property int Cols
		{
			int get();
		}

	public:
		ContourFinder();
		void LoadImage(System::String^ imagePath);
		List<List<Point^>^>^ FindContours(int thershold);	
	};
}
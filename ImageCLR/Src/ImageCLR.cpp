/**
 * @file ImageCLR.cpp
 * @author LinhengXilan
 * @version 0.0.1
 * @date 2026-1-5
 */

#include <pch.h>
using namespace System::Runtime::InteropServices;
#include <ImageCLR.h>

cv::Mat mat;

ImageCLR::Point::Point()
	: X(0), Y(0)
{

}

ImageCLR::Point::Point(int x, int y)
	: X(x), Y(y)
{

}

String^ ImageCLR::Point::ToString()
{
	return "(" + X + "," + Y + ")";
}


ImageCLR::ContourFinder::ContourFinder()
{
	
}

void ImageCLR::ContourFinder::LoadImage(String^ imagePath)
{
	IntPtr ptr = Marshal::StringToHGlobalAnsi(imagePath);
	try
	{
		const char* cstr = (const char*)ptr.ToPointer();
		mat = cv::imread(cstr, 1);
		if (mat.data == nullptr)
		{
			throw gcnew System::Exception("Failed to load image.");
		}
	}
	finally
	{
		Marshal::FreeHGlobal(ptr);
	}
}

List<List<ImageCLR::Point^>^>^ ImageCLR::ContourFinder::FindContours(int thershold)
{
	cv::Mat cannyOutput;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Canny(mat, cannyOutput, thershold, thershold * 2, 3);
	cv::findContours(cannyOutput, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	// Convert to CLR List
	List<List<Point^>^>^ clrContours = gcnew List<List<Point^>^>(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		List<Point^>^ points = gcnew List<Point^>(contours[i].size());
		for (int j = 0; j < contours[i].size(); j++)
		{
			Point^ point = gcnew Point();
			point->X = contours[i][j].x;
			point->Y = contours[i][j].y;
			points->Add(point);
		}
		clrContours->Add(points);
	}
	return clrContours;
}

int ImageCLR::ContourFinder::Cols::get()
{
	return mat.cols;
}

int ImageCLR::ContourFinder::Rows::get()
{
	return mat.rows;
}
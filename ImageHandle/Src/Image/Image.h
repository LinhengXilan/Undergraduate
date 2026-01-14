/**
 * @file Image/Image.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#ifndef IMAGE_IMAGE_H
#define IMAGE_IMAGE_H

#include <OpenCV/opencv.hpp>

#include <Core/Core.h>

namespace ImageHandle
{
	class DLL Image
	{
	public:
		Image();
		~Image() = default;

	public:
		[[nodiscard]] ObjectRef<cv::Mat> GetImage() const;
		[[nodiscard]] int32_t GetWidth() const;
		[[nodiscard]] int32_t GetHeight() const;
		[[nodiscard]] int32_t GetStride() const;
		[[nodiscard]] int32_t GetSize() const;

	public:
		void LoadImage(const std::string& imagePath);

	private:
		ObjectRef<cv::Mat>m_Image;
	};
}

#endif
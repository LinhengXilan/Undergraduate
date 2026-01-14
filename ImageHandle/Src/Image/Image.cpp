/**
 * @file Image/Image.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#include <pch.h>
#include <Image/Image.h>

namespace ImageHandle
{
	Image::Image()
	{
		m_Image = CreateObjectRef<cv::Mat>();
	}

	void Image::LoadImage(const std::string& imagePath)
	{
		*m_Image = cv::imread(imagePath, cv::IMREAD_COLOR_BGR);
	}

	[[nodiscard]] ObjectRef<cv::Mat> Image::GetImage() const
	{
		return m_Image;
	}

	[[nodiscard]] int32_t Image::GetWidth() const
	{
		return m_Image->cols;
	}

	[[nodiscard]] int32_t Image::GetHeight() const
	{
		return m_Image->rows;
	}

	[[nodiscard]] int32_t Image::GetStride() const
	{
		return m_Image->step;
	}

	[[nodiscard]] int32_t Image::GetSize() const
	{
		return m_Image->rows * m_Image->cols * m_Image->channels();
	}
}
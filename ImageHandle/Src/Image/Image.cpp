/**
 * @file Image/Image.cpp
 * @author LinhengXilan
 * @version 0.0.0.3
 * @date 2026-1-8
 */

#include <pch.h>
#include <Image/Image.h>

namespace ImageHandle
{
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

	[[nodiscard]] int32_t Image::Size() const
	{
		return m_Image->rows * m_Image->cols * m_Image->channels();
	}
}
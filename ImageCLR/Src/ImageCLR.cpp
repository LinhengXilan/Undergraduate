/**
 * @file ImageCLR.cpp
 * @author LinhengXilan
 * @version 0.0.0.2
 * @date 2026-1-8
 */

#include <pch.h>
using namespace System::Runtime::InteropServices;
#include <ImageCLR.h>

namespace ImageCLR
{
	Image::Image()
	{
		m_Image = new ImageHandle::Image();
	}

	void Image::LoadImage(String^ imagePath)
	{
		IntPtr ptr = Marshal::StringToHGlobalAnsi(imagePath);
		try
		{
			const char* cstr = (const char*)ptr.ToPointer();
			m_Image->LoadImage(cstr);
			int dataSize = m_Image->Size();
			m_Data = gcnew array<Byte>(dataSize);
			Marshal::Copy(IntPtr(m_Image->GetImage()->data), m_Data, 0, dataSize);
			m_Width = m_Image->GetWidth();
			m_Height = m_Image->GetHeight();
			m_Stride = m_Image->GetStride();
		}
		finally
		{
			Marshal::FreeHGlobal(ptr);
		}
	}

	int Image::Width::get()
	{
		return m_Width;
	}

	int Image::Height::get()
	{
		return m_Height;
	}

	int Image::Stride::get()
	{
		return m_Stride;
	}

	array<Byte>^ Image::Data::get()
	{
		return m_Data;
	}
}
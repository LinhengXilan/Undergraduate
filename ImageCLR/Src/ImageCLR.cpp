/**
 * @file ImageCLR.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#include <pch.h>
using namespace System::Runtime::InteropServices;
#include <ImageCLR.h>

namespace ImageCLR
{
	Processor::Processor()
	{
		m_Processor = new ImageHandle::Processor();
	}

	void Processor::LoadImage(String^ filepath)
	{
		IntPtr ptr = Marshal::StringToHGlobalAnsi(filepath);
		try
		{
			const char* cstr = (const char*)ptr.ToPointer();
			m_Processor->GetOriginalImage()->LoadImage(cstr);
			int dataSize = m_Processor->GetOriginalImage()->GetSize();
			m_OriginalData = gcnew array<Byte>(dataSize);
			Marshal::Copy(IntPtr(m_Processor->GetOriginalImage()->GetImage()->data), m_OriginalData, 0, dataSize);
		}
		finally
		{
			Marshal::FreeHGlobal(ptr);
		}
	}

	int Processor::Width::get()
	{
		return m_Processor->GetOriginalImage()->GetWidth();
	}

	int Processor::Height::get()
	{
		return m_Processor->GetOriginalImage()->GetHeight();
	}

	int Processor::Stride::get()
	{
		return m_Processor->GetOriginalImage()->GetStride();
	}

	bool Processor::IsProcessed::get()
	{
		return m_Processor->IsProcessed();
	}

	array<Byte>^ Processor::OriginalData::get()
	{
		return m_OriginalData;
	}
	
	array<Byte>^ Processor::ProcessedData::get()
	{
		int dataSize = m_Processor->GetProcessedImage()->GetSize();
		m_ProcessedData = gcnew array<Byte>(dataSize);
		Marshal::Copy(IntPtr(m_Processor->GetProcessedImage()->GetImage()->data), m_ProcessedData, 0, dataSize);
		return m_ProcessedData;
	}

	void Processor::Start()
	{
		m_Processor->Start();
	}
}
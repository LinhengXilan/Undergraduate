/**
 * @file Image/Processor.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#include <pch.h>
#include <Image/Processor.h>

namespace ImageHandle
{
	Processor::Processor()
	{
		m_OriginalImage = CreateObjectRef<Image>();
		m_ProcessedImage = CreateObjectRef<Image>();
	}

	ObjectRef<Image> Processor::GetOriginalImage() const
	{
		return m_OriginalImage;
	}

	ObjectRef<Image> Processor::GetProcessedImage() const
	{
		return m_ProcessedImage;
	}

	bool Processor::IsProcessed() const
	{
		return o_IsProcessed;
	}

	void Processor::Start()
	{
		cv::cvtColor(*m_OriginalImage->GetImage(), *m_ProcessedImage->GetImage(), cv::COLOR_BGR2GRAY);
		o_IsProcessed = true;
	}

	void Processor::Stop()
	{
		
	}
}
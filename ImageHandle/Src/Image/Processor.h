/**
 * @file Image/Processor.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <Core/Core.h>
#include <Image/Image.h>

namespace ImageHandle
{
	class DLL Processor
	{
	public:
		Processor();
		~Processor() = default;

	public:
		ObjectRef<Image> GetOriginalImage() const;
		ObjectRef<Image> GetProcessedImage() const;
		bool IsProcessed() const;

	public:
		void Start();
		void Stop();

	private:
		bool o_IsProcessed = false;
		ObjectRef<Image> m_OriginalImage;
		ObjectRef<Image> m_ProcessedImage;
	};
}

#endif
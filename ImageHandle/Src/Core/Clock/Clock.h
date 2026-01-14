/**
 * @file Core/Clock/Clock.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#ifndef CORE_CLOCK_CLOCK_H
#define CORE_CLOCK_CLOCK_H

#include <Core/Core.h>

namespace ImageHandle
{
	struct Time
	{
		int64_t current = 0;
		int64_t last = 0;

		Time() = default;
		Time(int64_t time);
	};

	class DLL Clock
	{
	public:
		Clock();
		~Clock() = default;

	public:
		[[nodiscard]] int64_t GetCurrentTime() const;
		[[nodiscard]] static Clock GetClock();

	public:
		void Tick();

	private:
		static Clock s_Clock;
		Time m_Time;
	};
}

#endif
/**
 * @file Core/Clock/Clock.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#include <pch.h>

#include <Core/Clock/Clock.h>

namespace ImageHandle
{
	Clock Clock::s_Clock;

	Time::Time(int64_t time)
	{
		current = time;
		last = time;
	}

	Clock::Clock()
		: m_Time(std::chrono::high_resolution_clock::now().time_since_epoch().count())
	{
		s_Clock = *this;
	}

	[[nodiscard]] int64_t Clock::GetCurrentTime() const
	{
		return m_Time.current;
	}

	[[nodiscard]] Clock Clock::GetClock()
	{
		return s_Clock;
	}

	void Clock::Tick()
	{
		m_Time.last = m_Time.current;
		m_Time.current = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	}
}
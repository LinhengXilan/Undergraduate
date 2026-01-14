/**
 * @file Core/Clock/Timer.cpp
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#include <pch.h>
#include <Core/Clock/Timer.h>

namespace ImageHandle
{
	Duration::operator int64_t() const
	{
		return duration;
	}

	Duration& Duration::operator=(int64_t value)
	{
		duration = value;
		return *this;
	}

	Timer::Timer(const std::string& name)
		: m_Name(name), m_Time(Clock::GetClock().GetCurrentTime())
	{
		
	}

	Timer::Timer(const std::function<void(std::string, int64_t)>& callback)
		: m_Name(" "), m_Time(Clock::GetClock().GetCurrentTime()), m_Callback(callback)
	{

	}
	
	Timer::Timer(const std::string& name, const std::function<void(std::string, int64_t)>& callback)
		: m_Name(name), m_Time(Clock::GetClock().GetCurrentTime()), m_Callback(callback)
	{

	}

	Timer::~Timer()
	{
		Stop();
		m_Callback(m_Name, m_Duration);
	}

	[[nodiscard]] Time Timer::GetTime() const
	{
		return m_Time;
	}

	[[nodiscard]] Duration Timer::GetDuration() const
	{
		return m_Duration;
	}

	void Timer::Stop()
	{
		m_Duration = Clock::GetClock().GetCurrentTime() - m_Time.current;
	}
}
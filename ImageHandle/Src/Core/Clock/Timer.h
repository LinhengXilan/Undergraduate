/**
 * @file Core/Clock/Timer.h
 * @author LinhengXilan
 * @version 0.0.0.5
 * @date 2026-1-14
 */

#ifndef CORE_CLOCK_TIMER_H
#define CORE_CLOCK_TIMER_H

#include <Core/Core.h>
#include <Core/Clock/Clock.h>

namespace ImageHandle
{
	struct Duration
	{
		int64_t duration = 0;

		operator int64_t() const;
		Duration& operator=(int64_t value);
	};

	class DLL Timer
	{
	public:
		Timer(const std::string& name);
		Timer(const std::function<void(std::string, int64_t)>& callback);
		Timer(const std::string& name, const std::function<void(std::string, int64_t)>& callback);
		~Timer();

	public:
		[[nodiscard]] Time GetTime() const;
		[[nodiscard]] Duration GetDuration() const;

	public:
		void Stop();

	private:
		std::string m_Name;
		Time m_Time;
		std::function<void(std::string, int64_t)> m_Callback;
		Duration m_Duration;
	};
}

#endif
/*
===========================================================================================
<< ID INFORMATION >>
===========================================================================================
Programmer                    : Eddie
Assignment #                  : Final Project
ASsignment Name				  : Snake Alive
Course # and Title            : CISC 205 OOPS C++ Object Oriented Programming
Class Meeting Time            : 9:35- 12:45 T, TH
Instructor                    : Professor Forman
Hours Spent                   : 15h
Degree of Difficulty          : 8
Date Completed                : 12/14/2014
File Name                     : Eddie Meza Final Project
===========================================================================================
<< PROGRAM DESCRIPTION >>
===========================================================================================
This purpose of the program create and play a snake game. The user signs in to a
predetermined account and chooses a option on the menu. Logo, play snake, instruction,
game history, high score, save score, and exit program.
===========================================================================================
<< CUSTOM DEFINED FUNCTIONS (alphabetical order) >>
===========================================================================================

NChrono(void) :
m_tp0(Clock::now()) {}

~NChrono(void) {}

inline void reset(void);

inline bool check(void);

inline float getThrottle(void);

inline void setThrottle(float _throttle);

inline float getDelta(void);

===========================================================================================
<< CREDITS >>
Nil for his Delta Time code.
===========================================================================================
*/

#ifndef DELTATIME_H
#define DELTATIME_H

#include <chrono>
using namespace std;
using namespace chrono;

typedef high_resolution_clock Clock;
typedef high_resolution_clock::time_point TimePoint;
namespace NUtil
{
	class NChrono
	{
	public:
		NChrono(void) :
			m_tp0(Clock::now()) {}
		~NChrono(void) {}
		inline void reset(void);
		inline bool check(void);
		inline float getThrottle(void);
		inline void setThrottle(float _throttle);
		inline float getDelta(void);
	private:
		TimePoint m_tp0, m_tp1;
		microseconds m_throttle, m_delta;
		seconds throttle, delta;
	};
}
using namespace NUtil;
void NChrono::reset(void)
{
	m_tp0 = Clock::now();
}
bool NChrono::check(void)
{
	bool dt = true;

	m_tp1 = Clock::now();
	m_delta = duration_cast<microseconds>(m_tp1 - m_tp0);
	if (m_delta < m_throttle)
		dt = false;

	return dt;
}
float NChrono::getThrottle(void)
{
	return duration_cast<duration<float>>(m_throttle).count();
}
void NChrono::setThrottle(float _throttle)
{
	m_throttle = duration_cast<microseconds>(duration<float>(_throttle));
}
float NChrono::getDelta(void)
{
	return duration_cast<duration<float>>(m_delta).count();
}

#endif
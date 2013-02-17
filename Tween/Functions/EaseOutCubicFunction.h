#pragma once

/*
	Cubic easing out.
	Acceleration until halfway, then deceleration.
*/
template <typename data_type>
static data_type EaseOutCubic(float current_time, data_type begin, data_type change, float duration) 
{
	current_time /= duration;
	current_time--;
	return change * (current_time * current_time * current_time + 1.0f) + begin;
}

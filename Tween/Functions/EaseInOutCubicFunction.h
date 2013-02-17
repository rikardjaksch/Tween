#pragma once

/*
	Cubic easing in/out.
	Accelerating from zero velocity.
*/
template <typename data_type>
static data_type EaseInOutCubic(float current_time, data_type begin, data_type change, float duration) 
{
	current_time /= duration / 2.0f;

	if ( current_time < 1.0f )
		return change / 2.0f * current_time * current_time * current_time + begin;
			
	current_time -= 2.0f;
			
	return change / 2.0f * (current_time * current_time * current_time + 2.0f) + begin;
}
#pragma once

/*
	Quadratic easing in.
	Accelerating from zero velocity.
*/
template <typename data_type>
static data_type EaseInQuad(float current_time, data_type begin, data_type change, float duration) 
{
	current_time /= duration;
	return (data_type)(change * current_time * current_time + begin);
}

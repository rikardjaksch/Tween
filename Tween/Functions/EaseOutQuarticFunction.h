#pragma once

/*
	Quartic easing out.
	Decelerating to zero velocity.
*/
template <typename data_type>
static data_type EaseOutQuart(float current_time, data_type begin, data_type change, float duration) 
{
	current_time /= duration;
	current_time--;
	return (data_type)(-change * (current_time * current_time * current_time * current_time - 1.0f) + begin);
}

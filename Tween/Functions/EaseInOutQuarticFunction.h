#pragma once

/*
	Quartic easing in/out.
	Acceleration until halfway, then deceleration.
*/
template <typename data_type>
static data_type EaseInOutQuart(float current_time, data_type begin, data_type change, float duration) 
{
	current_time /= duration / 2.0f;
			
	if ( current_time < 1.0f ) 
		return (data_type)(change / 2.0f * current_time * current_time * current_time * current_time + begin);

	current_time -= 2.0f;

	return (data_type)(-change / 2.0f * (current_time * current_time * current_time * current_time - 2.0f) + begin);
}

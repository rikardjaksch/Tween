#pragma once

/*
	Simple linear tweening.
	No easing, no accerleration.
*/
template <typename data_type>
static data_type Lerp(float current_time, data_type begin, data_type change, float duration) 
{
	return (data_type)(change * current_time / duration + begin);
}

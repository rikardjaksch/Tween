#pragma once

namespace rju
{
	namespace easing_func
	{
		// All types of functions that can be used to interpolate/tween
		#include "./Functions/LerpFunction.h"
		#include "./Functions/EaseInQuadFunction.h"
		#include "./Functions/EaseOutQuadFunction.h"
		#include "./Functions/EaseInOutQuadFunction.h"
		#include "./Functions/EaseInCubicFunction.h"
		#include "./Functions/EaseOutCubicFunction.h"
		#include "./Functions/EaseInOutCubicFunction.h"
		#include "./Functions/EaseInQuarticFunction.h"
		#include "./Functions/EaseOutQuarticFunction.h"
		#include "./Functions/EaseInOutQuarticFunction.h"
	}

	/*
		Templated class for managing tweening of values.

		Example:

			int my_value;

			rju::Tween<int> tween_obj(&my_value, 0, 10, 2.0f, rju::tween_func::Lerp);

			while ( ... )
			{
				tween_obj.update(delta_time);
				std::cout << my_value << std::endl;

				if ( tween_obj.is_done() )
					break;
			}
	*/
	template <typename data>
	class Tween
	{
	public:
		// Easing-function-pointer
		typedef data (*function_t)(float, data, data, float);

	public:
		Tween();
		Tween(data* value, data begin, data end, float duration, function_t func);
		Tween(const Tween<data>& other);
		~Tween();
	
		Tween<data>& operator = (const Tween<data>& other);

		/*
			Deferred initialization.
				value		- memory address of the variabled to be interpolated.
				begin		- value to start from (usualy the current value of the first parameter)
				end			- target goal of the interpolation
				duration	- total duration of the interpolation (can be of any unit).
		*/
		void init(data* value, data begin, data end, float duration, function_t func);

		/*
			Updates the specified value with the selected interpolation function.
			Note that delta_time can be expressed in frames/milliseconds/seconds etc.
			As long as the deltatime is using the same unit as the duration and it
			is expressed as the amount of units that has passed since the last time update was called.
		*/
		void update(float delta_time);

		/*
			Returns true if either the current time (that this instance has been updated in) has gone past the
			set duration or if the end is equal to the start.
		*/
		bool is_done() const;

		// Returns true if the interpolation is currently paused
		bool is_paused() const;

		// Marks the interpolation as done, sets the interpolated value to be equal to the target end-value.
		void goto_end();

		// Pause the current interpolation.
		void pause();

		// Resumes the interpolation if it has been paused.
		void resume();

	private:
		data*		_value;			// Value to interpolate
		data		_begin;			// Starting point
		data		_end;			// Target end-point (to interpolate to)

		float		_duration;		// Amount of time for the entire interpolation (from start to finish)
		float		_current_time;	// Holds the time that has passed since we started to update this interpolation
		bool		_done;			// Is the interpolation finished (_start == _end)
		bool		_paused;		// True if the interpolation is paused

		function_t	_function;		// Function to used when interpolating
	};

	// Implementation of the Interpolation class
	#include "./Tween.inl"
}
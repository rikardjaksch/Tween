template <typename data>
Tween<data>::Tween():
_function(nullptr), 
_current_time(0.0f),
_done(true),
_paused(false)
{
}

template <typename data>
Tween<data>::Tween(data* value, data begin, data end, float duration, function_t func)
{
	init(value, begin, end, duration, func);
}

template <typename data>
Tween<data>::Tween(const Tween<data>& other):
_value(other._value),
_begin(other._begin),
_end(other._end),
_duration(other._duration),
_current_time(other._current_time),
_done(other._done),
_paused(other._paused),
_function(other._function)
{
}

template <typename data>
Tween<data>::~Tween() 
{ 
}

template <typename data>
Tween<data>& Tween<data>::operator = (const Tween<data>& other)
{
	_value			= other._value;
	_begin			= other._begin;
	_end			= other._end;
	_duration		= other._duration;
	_current_time	= other._current_time;
	_done			= other._done;
	_paused			= other._paused;
	_function		= other._function;

	return *this;
}

template <typename data>
void Tween<data>::init(data* value, data begin, data end, float duration, function_t func)
{
	_current_time	= 0.0f;
	_value			= value;
	_begin			= begin;
	_end			= end;
	_paused			= false;
	_duration		= duration;
	_function		= func;
	
	if ( _begin == _end || duration <= 0.0f )
		_done = true;
	else
		_done = false;
}

template <typename data>
void Tween<data>::update(float delta_time)
{
	if ( _done )
	{
		return;
	}
	
	if ( !_paused )
		_current_time += delta_time;

	*_value = _function(_current_time, _begin, _end - _begin, _duration);

	if ( _current_time >= _duration )
		_done = true;

	if ( _begin == _end )
		_done = true;

	if ( _done == true )
	{
		*_value = _end;
	}
}

template <typename data>
bool Tween<data>::is_done() const
{
	return _done;
}

template <typename data>
bool Tween<data>::is_paused() const
{
	return _paused;
}

template <typename data>
void Tween<data>::goto_end()
{
	_done = true;
	_current_time = _duration;
	*_value = _end;
}

template <typename data>
void Tween<data>::pause()
{
	_paused = true;
}

template <typename data>
void Tween<data>::resume()
{
	_paused = false;
}
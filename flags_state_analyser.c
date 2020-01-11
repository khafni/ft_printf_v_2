int flags_s_a (char *format)
{
	int flags_state;

	flags_state = 0;
	while (*format)
	{
		if (*format == '-')
			flags_state |= LEFT;
		else if (*format == '+')
			flags_state |= PLUS;
		else if (*format == ' ')
			flags_state |= SPACE;
		else if (*format == '#')
			flags_state |= SPECIAL;
		else if (*format == '0')
			flags_state |= ZEROPAD;
		format++;
	}
	return (flags_state);
}

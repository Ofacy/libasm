
int ft_atoi_base(char *str, char *base);

int test_invalid_base() {
	if (ft_atoi_base("10", " 0123456789") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789 ") != 0)
		return 1;
	if (ft_atoi_base("10", "0123 456789") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789+") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789-") != 0)
		return 1;
	if (ft_atoi_base("10", "\t0123456789") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789\n") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789\r") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789\f") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789\v") != 0)
		return 1;
	if (ft_atoi_base("10", "0123456789\t") != 0)
		return 1;
	if (ft_atoi_base("10", "01923456789") != 0)
		return 1;
	if (ft_atoi_base("10", "01234567890") != 0)
		return 1;
	if (ft_atoi_base("10", "90123456789") != 0)
		return 1;
	if (ft_atoi_base("0", "0") != 0)
		return 1;
	return 0;
}

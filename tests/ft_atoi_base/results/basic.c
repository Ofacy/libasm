
int ft_atoi_base(char *str, char *base);

int test_basic() {
	if (ft_atoi_base("10", "0123456789") != 10)
		return 1;
	if (ft_atoi_base("1010", "01") != 10)
		return 1;
	if (ft_atoi_base("A", "0123456789ABCDEF") != 10)
		return 1;
	if (ft_atoi_base("10", "0123456789ABCDEF") != 16)
		return 1;
	if (ft_atoi_base("-10", "0123456789ABCDEF") != -16)
		return 1;
	if (ft_atoi_base("DROLE", "0123456789ABCDEFGHIJKLMNOPQRSTUV") != 14541486)
		return 1;
	if (ft_atoi_base("-DROLE", "0123456789ABCDEFGHIJKLMNOPQRSTUV") != -14541486)
		return 1;
	if (ft_atoi_base("   +10", "0123456789") != 10)
		return 1;
	if (ft_atoi_base("   -10", "0123456789") != -10)
		return 1;
	if (ft_atoi_base("   -+10", "0123456789") != 0)
		return 1;
	return 0;
}

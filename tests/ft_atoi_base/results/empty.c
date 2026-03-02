
int ft_atoi_base(char *str, char *base);

int test_empty() {
	if (ft_atoi_base("", "") != 0)
		return 1;
	if (ft_atoi_base("", "0123456789") != 0)
		return 1;
	if (ft_atoi_base("10", "") != 0)
		return 1;
	if (ft_atoi_base(" ", "01") != 0)
		return 1;
	return 0;
}

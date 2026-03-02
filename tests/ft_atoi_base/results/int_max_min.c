
int ft_atoi_base(char *str, char *base);

int test_int_max_min() {
	if (ft_atoi_base("2147483647", "0123456789") != 2147483647)
		return 1;
	if (ft_atoi_base("-2147483648", "0123456789") != -2147483648)
		return 1;
	return 0;
}

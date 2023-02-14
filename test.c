int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("%d %d %dend\n", 123, 456, 789);
	ft_printf("%c1%3c2%5c\n", 'a', 'b', 'c');
	ft_printf("%d %u\n", 2147483648, 2147483648);
	ft_printf("%x %X\n", -1, -1);
	ft_printf("%% %% %%\n");
	ft_printf("Test String:%s\n", "This is the test string.");
	return (0);
}

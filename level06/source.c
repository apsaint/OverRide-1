int auth(char buff[32], unsigned int uns)
{
	int i2;
	int i;
	int len;

	*strcspn(buff, "\n") = '\0';
	len = strnlen(buff, 32);
	if (len <= 5)
		return (1);
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		puts("\033[32m.---------------------------.")
		puts ("\033[31m| !! TAMPERING DETECTED !!  |")
		puts("\033[32m'---------------------------'")
		return (1)
	}
	i = ((int)buff[3] ^ 0x1337) + 0x5eeded;
	i2 = 0;
	while (i2 < len)
	{
		if (buff[2] <= 0x1f)
			return (1);
		i += (((int)buff[i2] ^ i) * 0x88233b2b >> 0x20) - ((((int)buff[i2] ^ i - (((int)buff[i2] ^ i) * 0x88233b2b >> 0x20)) >> 1 + (((int)buff[i2] ^ i) * 0x88233b2b >> 0x20))) >> 0xa * 0x539
	}
	if (uns == i)
		return (0);
	return (1);
}

int main() {
	void *ptr;
	unsigned int uns;
	char buff[32];

	puts("***********************************")
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************")	

	printf("-> Enter Login: ");
	fgets(buff, 32, stdin);

	puts("***********************************")
	puts("***** NEW ACCOUNT DETECTED ********")
	puts("***********************************")

	printf("-> Enter Serial: ");
	scanf("%u", &uns);
	if (auth(buff, uns) == 0) {
		system("/bin/sh");
		return (0);
	}
	return (1);
}
for a in range(0, 100):
	for b in range(0, 100):
		for c in range(0, 100):
			if ((a + b) ^ c) != ((a ^ c) + (b ^ c)):
				print(a, b, c)
				exit()
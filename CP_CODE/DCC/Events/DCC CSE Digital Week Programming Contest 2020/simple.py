x = int(input())

try:
	cnt = 0
	while x > 0:
		if (x % 2) == 0:
			cnt = cnt + 1
	x = x // 2
	print(cnt)

except EOFError as e:
	print(e)
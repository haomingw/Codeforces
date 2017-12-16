n, q = map(int, raw_input().split())

def solve(a): # TLE
	global ans
	global dic
	global apps	
	if a[0] == 1:
		apps.append([a[1],1])		
		ans += 1
		if a[1] in dic:
			dic[a[1]] += 1
		else:
			dic[a[1]] = 1
	elif a[0] == 2:
		if a[1] in dic:
			for app in apps:
				if app[0] == a[1]:
					app[1] = 0
			ans -= dic[a[1]]
			dic[a[1]] = 0
	else:		
		for i in xrange(a[1]):			
			if apps[i][1] > 0:
				ans -= 1
				apps[i][1] = 0
				dic[apps[i][0]] -= 1

	return ans


def opt_solve(a):
	pass

dic = {}
ans = 0
apps = []
for i in xrange(q):
	a = map(int, raw_input().split())	
	print solve(a)	
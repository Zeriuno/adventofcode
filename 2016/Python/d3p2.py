import sys

def check_file(param):
	"""
	Opens the input file, count the valid triangls
	"""
	instructions = open(param, "r")
	triangles = 0
	check = 0
	t = [0,0,0]
	r = [0,0,0]
	i = [0,0,0]

	for line in instructions:

		t[check], r[check], i[check] = line.split()
		t[check] = int(t[check])
		r[check] = int(r[check])
		i[check] = int(i[check])
		check += 1

		if(check == 3):
			triangles += tri_test(t,r,i)
			check = 0
	print("Valid triangles =", triangles)
	instructions.close()

def triangle_test(t):
	"""
	Tests if the given parameters can make a valid triangle
	"""
	if((t[0] + t[1]) <= t[2]):
		return False
	elif((t[1] + t[2]) <= t[0]):
		return False
	elif((t[2] + t[0]) <= t[1]):
		return False
	else:
		return True

def tri_test(a, n, g):
	"""
	Tests three possible triangles
	"""
	add = 0
	if(triangle_test(a)):
		add += 1
	if(triangle_test(n)):
		add += 1
	if(triangle_test(g)):
		add += 1
	return add
import sys

def check_file(param):
	"""
	Opens the input file, count the valid triangls
	"""
	instructions = open(param, "r")
	triangles = 0
	for line in instructions:
		t1, t2, t3 = line.split()
		if(triangle_test(t1, t2, t3)):
			print("TRIANGLE!\n")
			triangles += 1
		else:
			print(t1, t2 , t3)
	print(triangles)
	instructions.close()

def triangle_test(s1, s2, s3):
	"""
	Tests if the given parameters can make a valid triangle
	"""
	if((s1 + s2) <= s3):
		print ( (s1 + s2 ), " <= ", s3)
		return False
	elif((s2 + s3) <= s1):
		return False
	elif((s3 + s1) <= s2):
		return False
	else:
		return True
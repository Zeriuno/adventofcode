def press(param):
	'''
	Translates from coordinates to digits
	'''
	return {
		(0,0): 7,
		(0,1): 4,
		(0,2): 1,
		(1,0): 8,
		(1,1): 5,
		(1,2): 2,
		(2,0): 9,
		(2,1): 6,
		(2,2): 3
		}[param]

def get_code(param):
	'''
	Grabs a file, gets the code from the instructions
	'''
	code = ''
	finger = (1,1) # coordinates on the keypad, starting at 2,2 (i.e. 5)
	instructions = open(param, "r")
	for instruction in instructions:
		for move in instruction:
			if(move == 'U'):
				going = finger[1] + 1
				if(going <= 2):
					finger = (finger[0], going)
			elif(move == 'D'):
				going = finger[1] - 1
				if(going >= 0 ):
					finger = (finger[0], going)
			elif(move == 'L'):
				going = finger[0] - 1
				if(going >= 0):
					finger = (going, finger[1])
			elif(move =='R'):
				going = finger[0] + 1
				if(going <= 2):
					finger = (going, finger[1])
		code += str(press(finger))
	print(code)
	instructions.close()

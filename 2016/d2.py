def press(param):
	'''
	Translates from coordinates to digits
	'''
	return {
		(1,1): 7,
		(1,2): 4,
		(1,3): 1,
		(2,1): 8,
		(2,2): 5,
		(2,3): 2,
		(3,1): 9,
		(3,2): 6,
		(3,3): 3
		}[param]

def get_code(param):
	'''
	Grabs a file, gets the code from the instructions
	'''
	code = ''
	finger = (2,2) # coordinates on the keypad, starting at 2,2 (i.e. 5)
	instructions = open(param, "r")
	for instruction in instructions:
		for move in instruction:
			if(move == 'U'):
				going = finger[1] + 1
				if(going < 4):
					finger = (finger[0], going)
			elif(move == 'D'):
				going = finger[1] - 1
				if(going > 0):
					finger = (finger[0], going)
			elif(move == 'L'):
				going = finger[0] - 1
				if(going > 0):
					finger = (going, finger[1])
			elif(move =='R'):
				going = finger[0] + 1
				if(going < 4):
					finger = (going, finger[0])
		code += str(press(finger))
	print(code)
	instructions.close()
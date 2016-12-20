def press(param):
	'''
	Translates from coordinates to digits
	'''
	return {
		(0,0): 5,
		(1,0): 6,
		(2,0): 7,
		(3,0): 8,
		(4,0): 9,
		(1,1): 2,
		(2,1): 3,
		(3,1): 4,
		(2,2): 1,
		(1,-1): "A",
		(2,-1): "B",
		(3,-1): "C",
		(2,-2): "D",
		}[param]

def get_code(param):
	'''
	Grabs a file, gets the code from the instructions
	'''
	code = ''
	finger = (0,0) # coordinates on the keypad, starting at 0,0 (i.e. 5)
	instructions = open(param, "r")
	for instruction in instructions:
		for move in instruction:
			if(move == 'U'):
				if((0 < finger[0] < 4) and (finger[1] < 2)):
					if((finger[1] == 1) and ((finger[0] == 1) or (finger[0] == 3))):
						pass
					else:
						finger = (finger[0],finger[1] + 1)
				else:
					pass
			elif(move == 'D'):
				if ((0 < finger[0] < 4) and (-2 < finger[1])):
					if((finger[1] == -1) and ((finger[0] == 1) or (finger[0] == 3))):
						pass
					else:
						finger = (finger[0], finger[1] - 1)
				else:
					pass
			elif(move == 'L'):
				if ((-2 < finger[1] < 2) and (0 < finger[0])):
					if((finger[0] == 1) and ((finger[1] == -1) or (finger[1] == 1))):
						pass
					else:
						finger = (finger[0] - 1, finger[1])
				else:
					pass
			elif(move =='R'):
				if ((-2 < finger[1] < 2) and (finger[0] < 4)):
					if((finger[0] == 3) and ((finger[1] == -1) or (finger[1] == 1))):
						pass
					else:
						finger = (finger[0] + 1, finger[1])
				else:
					pass
		#print(finger)
		code += str(press(finger))
	print(code)
	instructions.close()

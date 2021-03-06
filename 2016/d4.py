def get_ID_tot(param):
	"""
	Opens the param file, looks for the real rooms and returns the sum of their sector IDs
	"""
	tot_ID = 0
	list = open(param, "r")
	for r in list:
		r = Room(r)
		if (r.is_real):
			tot_ID += room.ID
	return tot_ID


class Room:
	"""
	Room object.
	"""

	def __init__(self):
		"""
		Creation of a Room.
		room1 = Room(aaaaa-bbb-z-y-x-123[abxyz])
		self.checksum contains only the checksum, without the brackets: "abxyz"
		self.ID contains only the ID number: 123
		self.string contains only the letters of the room, without dashes: "aaaaabbbzyx"
		self.is_real is set to True if the name follows the rules of a real room
		"""
		self.checksum = self.split('[')[-1][:-1]
		self.ID = int(self.split('-')[-1].split('[')[0])
		self.string = ''
		for bit in self.split('-')[:-1]:
			self.string += bit
		occurrencesletters = []
		occurrences = []
		for letter in self.string:
			if(letter in occurrencesletters):
				occurrences[occurrencesletters.index(letter)] += 1
			else:
				occurrencesletters.append(letter)
				occurrences.append(1)
		# now occurrences is an unordered list of the occurrences
		self.occurrences = collection.Counter(self.string)

		if():
			self.is_real = True
		else:
			self.is_real = False



2.b Order the ties alphabetically
3. Check the 5 most frequent letters appear in alphabetical order: self.is_real

1. Take a room name.



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
		
		"""
		self.checksum = self.split('[')[-1][:-1]
		self.ID = int(self.split('-')[-1].split('[')[0])
		self.string = ''
		for bit in self.split('-')[:-1]:
			self.string += bit
		self.occurrences = collection.Counter(self.string)



2.b Order the ties alphabetically
3. Check the 5 most frequent letters appear in alphabetical order: self.is_real

1. Take a room name.


4. If that's a real room, add the sector ID to the total.

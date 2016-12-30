def get_ID_tot(param):
	"""
	Opens the param file, looks for the real rooms and returns the sum of their sector IDs
	"""
	tot_ID = 0
	list = open(param, "r")
	for room in list:
		if (room.is_real):
			tot_ID += room.ID
	return tot_ID


1. Take a room name.
2. Find the 5 most frequent letters of the name
2.b Order the ties alphabetically
3. Check the 5 most frequent letters appear in alphabetical order
4. If that's a real room, add the sector ID to the total.

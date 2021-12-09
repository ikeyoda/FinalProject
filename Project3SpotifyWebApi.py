import csv
import codecs
#Spotipy library used to interact with Spotify API
import spotipy
from spotipy.oauth2 import SpotifyClientCredentials
#Login information unique to the program registered on Spotify.
CLIENT_ID = "40811ba1856241e7a0aebee70d488db3"
CLIENT_SECRET = "1fbff1a872c641fa9316fa6bfeece967"
#Regex of characters to be ignored. This is used to go from data set to outputfile.
disallowedChars = ",[]'"
finalList = []
albums = []
#Initalizes "spotify" obbject that allows searching database
sp = spotipy.Spotify(client_credentials_manager=SpotifyClientCredentials(client_id=CLIENT_ID, client_secret=CLIENT_SECRET), requests_timeout=10, retries=10)
#ArtistIds.csv is the list of unique ids from the original data set.
with open('ArtistIds.csv', newline='') as csvfile:
	reader = csv.reader(csvfile,dialect='excel')
	#Goes through the csv file and splits by row. Here commas between lines are deleted
	for row in reader:
		strings = row[0].split()
		for x in strings:
			for character in disallowedChars:
				x = x.replace(character,"")
			finalList.append(x)
#A dict is used to remove duplicates, then transformed back into a list
finalList = list(dict.fromkeys(finalList))
set = set()
#Now a new file is opened to be written to.
masterList = codecs.open('newfile.txt', 'w', encoding="utf-8")
count = len(finalList)
#Iterate through each id generated from the csv
for id in finalList:
	#albums is a set of albums that the artist has appeared in by id
	albums = sp.artist_albums(id, limit=50, album_type='album')['items']
	#Next, get every artist included in that album and add them to a set. This set maps an artist to every other artist on the album
	for album in albums:
		artists = album['artists']
		for artist in artists:
			set.add(artist['name'])
	#Now, the output file is written to, with each line representing an arist and everyone they are adjacent to.
	for finalId in set:
		masterList.write(finalId + '^')
	#Empty the list and create a new line
	set.clear()
	masterList.write("\n")
	#Count is used to count down to track the program's progress. Because of Spotify API's rate limiting, it takes ~3 hours.
	print(count)
	count = count-1 

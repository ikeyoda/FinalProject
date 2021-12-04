import csv
import codecs
import spotipy
from spotipy.oauth2 import SpotifyClientCredentials
CLIENT_ID = "40811ba1856241e7a0aebee70d488db3"
CLIENT_SECRET = "1fbff1a872c641fa9316fa6bfeece967"
disallowedChars = ",[]'"
finalList = []
albums = []
sp = spotipy.Spotify(client_credentials_manager=SpotifyClientCredentials(client_id=CLIENT_ID, client_secret=CLIENT_SECRET), requests_timeout=10, retries=10)
with open('ArtistIds.csv', newline='') as csvfile:
	reader = csv.reader(csvfile,dialect='excel')
	for row in reader:
		strings = row[0].split()
		for x in strings:
			for character in disallowedChars:
				x = x.replace(character,"")
			finalList.append(x)
finalList = list(dict.fromkeys(finalList))
set = set()
masterList = codecs.open('newfile.txt', 'w', encoding="utf-8")
count = len(finalList)
for id in finalList:
	albums = sp.artist_albums(id, limit=50, album_type='album')['items']
	for album in albums:
		artists = album['artists']
		for artist in artists:
			set.add(artist['name'])
	for finalId in set:
		masterList.write(finalId + '^')
	set.clear()
	masterList.write("\n")
	print(count)
	count = count-1 
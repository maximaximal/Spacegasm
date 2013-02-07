-- This defines the tracks that are played as background music
-- They are in the path "Data/Music/XXXXXXX"
-- You have to write the count of background music tracks to the trackCount variable!

-- The playlist defines, which tracks should be played in which order.
-- You have to provide the count variable too!
-- Playlists are desabled by default, the songs are played randomly.

trackCount = 5;
tracks = {
	"Data/Music/Cephelopod.ogg";
	"Data/Music/Electrodoodle.ogg";
	"Data/Music/Latin Industries.ogg";
	"Data/Music/Rocket.ogg";
	"Data/Music/Zap Beat.ogg";
};

usePlaylist = false;
playlistCount = 10;
playlist = {3, 5, 3, 1, 2, 3, 4, 1, 5, 3};

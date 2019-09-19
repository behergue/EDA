#ifndef ipud_h
#define ipud_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

using song = string;
using artist = string;
using duration = int;

class ipud: private unordered_map<song, duration> {

private:
	//mapa de cada cancion a su iterador dentro de la lista de reproducion
	unordered_map<song, list<song>::iterator> playlistMap;
	//mapa de cada cancion a su iterador dentro de la lista de reproducidas
	unordered_map<song, list<song>::iterator> playedMap;
	//lista de reproduccion
	list<song> playlist;
	//lista de reproducidas
	list<song> played;
	//tiempo total
	int time = 0;

public:

	void addSong(song s, artist a, duration d) {
		auto it = find(s);

		if (it == end())
			insert({ s, d });

		else
			throw domain_error("ERROR");
	}

	void addToPlaylist(song s) {
		auto it = find(s);

		if (it == end())
			throw domain_error("ERROR");

		auto it2 = playlistMap.find(s);

		if (it2 == playlistMap.end()) {
			time += at(s);
			playlistMap[s] = playlist.insert(playlist.end(), s);
		}
	}

	song current() {
		if (playlist.empty())
			throw domain_error("ERROR");

		return playlist.front();
	}

	song play() {
		if (!playlist.empty()) {
			song sonando = playlist.front();
			auto it = playedMap.find(sonando);

			if (it != playedMap.end()) 
				played.erase(playedMap[sonando]);

			playedMap[sonando] = played.insert(played.begin(), sonando);

			playlistMap.erase(sonando);
			playlist.pop_front();

			time -= at(sonando); 

			return sonando; 
		}

		return "";
	}

	int totalTime() {
		return time;
	}

	list<song> recent(int n) {
		list<song> lista;

		auto it = played.begin(); 

		for (int i = 0; i < n && it != played.end(); i++) {
			lista.push_back(*it); 
			it++;
		}
		return lista;
	}

	void deleteSong(song s) {

		if (count(s) == 0)
			return;

		if (playlistMap.count(s) > 0) {
			time -= at(s);
			playlist.erase(playlistMap[s]);
			playlistMap.erase(s);
		}

		if (playedMap.count(s) > 0) {
			played.erase(playedMap[s]);
			playedMap.erase(s);
		}
		erase(s);
	}
};

#endif
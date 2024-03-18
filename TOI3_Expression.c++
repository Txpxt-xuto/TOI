/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <string>

class Song {
public:
    std::string title;
    Song *next;
    Song *prev;

    Song(std::string title) : title(title), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song *head;
    Song *tail;

public:
    Playlist() : head(nullptr), tail(nullptr) {}

  // Add a new song to the end of the playlist
    void addSong(std::string title) {
    Song *newSong = new Song(title);
    if (!head) {
        head = newSong;
        tail = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    }

  // Remove a song from the playlist
    bool removeSong(std::string title) {
    Song *temp = head;
    while (temp != nullptr) {
        if (temp->title == title) {
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp == head)
                head = temp->next;
            if (temp == tail)
                tail = temp->prev;
        delete temp;
        return true;
        }
        temp = temp->next;
    }
    return false; // Song not found
    }

  // Display all songs in the playlist
    void display() {
    Song *temp = head;
    while (temp != nullptr) {
        std::cout << temp->title << std::endl;
        temp = temp->next;
    }
    }
};

int main() {
    Playlist myPlaylist;
    myPlaylist.addSong("Song 1");
    myPlaylist.addSong("Song 2");
    myPlaylist.addSong("Song 3");

    std::cout << "Current Playlist:" << std::endl;
    myPlaylist.display();

    myPlaylist.removeSong("Song 2");
    std::cout << "\nPlaylist after removing a song:" << std::endl;
    myPlaylist.display();

    return 0;
}
#include <string>
#include <iostream>

using namespace std;

class Person {
private:
  string first_name;
  string last_name;
public:
  Person(const string& first_name, const string& last_name) : 
    first_name(first_name), 
    last_name(last_name) {}
  
  string get_first_name() const {
    return first_name;
  }

  string get_last_name() const {
    return last_name;
  }

  bool operator==(const Person& person) const {
    return first_name == person.first_name && last_name == person.last_name;
  }

  bool operator!=(const Person& person) const {
    return !(*this == person);
  }

  bool operator>(const Person& person) const {
    return first_name > person.first_name || 
           (first_name == person.first_name && last_name == person.last_name);
  }

  bool operator>=(const Person& person) const {
    return (*this > person) || (*this == person);
  }

  bool operator<=(const Person& person) const {
    return !(*this > person);
  }

  bool operator<(const Person& person) const {
    return (*this <= person) && (*this != person);
  }
};

class Song {
private:
  string artist;
  Person music_author;
  Person lyrics_author;
  string lyrics;
public:
  Song(): artist("Неизвестно"), 
      music_author(Person("Неизвестно", "Неизвестно")), 
      lyrics_author(Person("Неизвестно", "Неизвестно")), 
      lyrics("unknown") {}

  Song(
    const string& artist, 
    const Person& music_author, 
    const Person& lyrics_author, 
    const string& lyrics
  ) : artist(artist), 
      music_author(music_author), 
      lyrics_author(lyrics_author), 
      lyrics(lyrics) {}

  string get_artist() const {
    return artist;
  }

  Person get_music_author() const {
    return music_author;
  }

  Person get_lyrics_author() const {
    return lyrics_author;
  }

  string get_lyrics() const {
    return lyrics;
  }

  void set_artist(const string& artist) {
    this->artist = artist;
  }
  
  void set_music_author(const Person& song_author) {
    this->music_author = song_author;
  }

  void set_lyrics_author(const Person& lyrics_author) {
    this->lyrics_author = lyrics_author;
  }

  void set_lyrics(const string& lyrics) {
    this->lyrics = lyrics;
  }

  bool operator==(const Song& song) const {
    return artist == song.artist;
  }

  bool operator!=(const Song& song) const {
    return artist != song.artist;
  }

  bool operator>(const Song& song) const {
    return artist > song.artist;
  }

  bool operator>=(const Song& song) const {
    return artist >= song.artist;
  }

  bool operator<=(const Song& song) const {
    return artist <= song.artist;
  }

  bool operator<(const Song& song) const {
    return artist < song.artist;
  }
};

int main() {
  Song smells_like_teen_spirit("Nirvana", Person("Kurt", "Cobain"), Person("Kurt", "Cobain"), 
  "With the ligths out, it's less dangerous");
  Song song_without_words("Кино", Person("Юрий", "Каспарян"), Person("Виктор","Цой"),
  "Песня без слов, ночь без сна. Все в свое время - зима и весна." );
  Song feeling_of_guity("Электромания", Person("Арсений", "Перцов"), Person("Владислав","Беляев"),
  "Делать от сердца, сгорая внутри. Это чувство моей вины, чувство моей вины!" );

  return 0;
}

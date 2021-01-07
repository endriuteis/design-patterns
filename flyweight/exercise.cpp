#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct Sentence
{
  struct WordToken
  {
    bool capitalize;
  };

  Sentence(const string& text)
  {
    istringstream iss(text);
    words = std::vector<std::string>(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{});
    word_tokens.resize(words.size());
    fill(word_tokens.begin(), word_tokens.end(), WordToken{false});
  }

  WordToken& operator[](size_t index)
  {
    if(index >= 0 && index < word_tokens.size())
      return word_tokens.at(index);
    else
      throw std::runtime_error("Index of out bounds");
  }

  string str() const
  {
    std::ostringstream oss;
    for(int i=0; i< words.size(); i++)
    {
      string word{words[i]};
      if(word_tokens[i].capitalize)  
        transform(word.begin(), word.end(), word.begin(), ::toupper);
      oss << word;
      if(i < words.size() -1)
        oss << " ";
    }
    oss << endl;
    return oss.str();
  }

  vector<WordToken> word_tokens{};
  vector<string> words{};
};

int main(int ac, char* av[])
{
  Sentence sentence {"hello world"};
  sentence[1].capitalize = true;
  cout << sentence.str(); // prints "hello WORLD"
}
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "StdAfx.h"
#include "TextBuffer.h"
#include "Window.h"
using namespace std;

class Console
{
 public:
  static Console& instance()
  {
    static Console console;
    return console;
  }

  vector<shared_ptr<Window>> windows;

  // cannot make this static
  shared_ptr<Window> single(const string& title, uint8_t charsWide, uint8_t charsHigh)
  {
    auto w = make_shared<Window>(title, charsWide * charWidth, charsHigh * charHeight);
    auto buffer = make_shared<TextBuffer>(charsWide, charsHigh);
    w->buffers.push_back(buffer);
    auto viewport = make_shared<Viewport>(buffer);
    w->viewports.push_back(viewport);
    windows.push_back(w);
    return w;
  }

  shared_ptr<Window> multicolumn(const string& title, uint8_t columnCount, uint8_t columnWidth, uint8_t charsHigh)
  {
    auto w = make_shared<Window>(title, columnCount * columnWidth * charWidth, charsHigh * charHeight);
    for (uint8_t c = 0; c < columnCount; ++c)
    {
      auto buffer = make_shared<TextBuffer>(columnWidth, charsHigh);
      w->buffers.push_back(buffer);
      auto viewport = make_shared<Viewport>(buffer, buffer->get_size(), Point{}, Point{columnWidth * c, 0});
      w->viewports.push_back(viewport);
      windows.push_back(w);
    }
    return w;
  }

 private:
  const int charWidth = 10, charHeight = 14;
  Console() {}
  Console(Console const&) = delete;
  void operator=(Console const&) = delete;
};

int main(int ac, char* av[])
{
  // create a single window and show it
  // Window window("Test", 2560, 1440);
  // Window window("Test", 1280, 720);

  //// let's try to create a viewport + buffer
  // auto buffer = make_shared<TextBuffer>(40, 40);
  // buffer->add_string("One");
  // buffer->add_string(string("Two"));
  // buffer->add_string(string("Three"));
  // buffer->add_string(string("Four"));
  // buffer->add_string(string("Five"));
  // window.buffers.push_back(buffer);
  // auto viewport = make_shared<Viewport>(buffer);
  // window.viewports.emplace_back(viewport);

  // auto viewport2 = make_shared<Viewport>(buffer, Size{ 40,40 }, Point{}, Point{ 45, 0 });
  // window.viewports.emplace_back(viewport2);
  //
  // auto viewport3 = make_shared<Viewport>(buffer, Size{ 40,40 }, Point{}, Point{ 90, 0 });
  // window.viewports.emplace_back(viewport3);

  // auto window = Console::instance().single("Test", 50, 30);
  auto window = Console::instance().multicolumn("Test", 2, 40, 40);

  for (size_t i = 0; i < 40; i++)
  {
    window->buffers[1]->add_string(string("This is line ") + boost::lexical_cast<string>(i), (i % 2 == 0));
  }

  window->Show();
  return 0;
}
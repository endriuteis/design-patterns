#include <iostream>
#include <string>

struct Pingable
{
  virtual std::wstring Ping(const std::wstring& message) = 0;
};

struct Pong : public Pingable
{
  std::wstring Ping(const std::wstring& message) override { return message + L" pong"; }
};

void TryIt(Pingable& pp) { std::wcout << pp.Ping(L"ping") << "\n"; }

struct RemotePong : public Pingable
{
  std::wstring result;
  std::wstring Ping(const std::wstring& message) override
  {
    // communicating with a remote web server
    return message + L" remote pong";
  }
};

int main()
{
  // Pong pp;
  RemotePong pp;
  for (size_t i = 0; i < 3; i++)
  {
    TryIt(pp);
  }
  return 0;
}
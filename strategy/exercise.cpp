#include <complex>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct DiscriminantStrategy
{
  virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
  double calculate_discriminant(double a, double b, double c) override { return b * b - 4 * a * c; }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
  double calculate_discriminant(double a, double b, double c) override
  {
    double result = b * b - 4 * a * c;
    return result >= 0 ? result : NAN;
  }
};

class QuadraticEquationSolver
{
  DiscriminantStrategy& strategy;

 public:
  QuadraticEquationSolver(DiscriminantStrategy& strategy) : strategy(strategy) {}

  tuple<complex<double>, complex<double>> solve(double a, double b, double c)
  {
    complex<double> disc{strategy.calculate_discriminant(a, b, c), 0};
    auto root_disc = sqrt(disc);
    return {(-b + root_disc) / (2 * a), (-b - root_disc) / (2 * a)};
  };
};

int main()
{
  OrdinaryDiscriminantStrategy ordinary_strategy;
  QuadraticEquationSolver solver1{ordinary_strategy};
  auto results = solver1.solve(1, 10, 16);
  cout << "First result: " << get<0>(results) << endl;
  cout << "Second result: " << get<1>(results) << endl;

  RealDiscriminantStrategy real_strategy1;
  QuadraticEquationSolver solver2{ordinary_strategy};
  results = solver2.solve(1, 10, 16);
  cout << "First result: " << get<0>(results) << endl;
  cout << "Second result: " << get<1>(results) << endl;

  RealDiscriminantStrategy real_strategy2;
  QuadraticEquationSolver solver3{ordinary_strategy};
  results = solver3.solve(1, 4, 5);
  auto x1 = get<0>(results);
  auto x2 = get<1>(results);
  cout << "Is Nan: " << isnan(x1.real()) << endl;
  cout << "Is Nan: " << isnan(x2.real()) << endl;
  cout << "Is Nan: " << isnan(x1.real()) << endl;
  cout << "Is Nan: " << isnan(x2.real()) << endl;
}
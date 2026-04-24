#include "complex.hpp"

namespace sjtu {

// 默认构造函数
complex::complex() : a(0.0), b(0.0) {}

// 单参数构造函数
complex::complex(double a) : a(a), b(0.0) {}

// 双参数构造函数
complex::complex(double a, double b) : a(a), b(b) {}

// 返回实部引用
double &complex::real() {
  return a;
}

// 返回虚部引用
double &complex::imag() {
  return b;
}

// 取负运算符
complex complex::operator-() const {
  return complex(-a, -b);
}

// 取共轭运算符
complex complex::operator~() const {
  return complex(a, -b);
}

// 加法
complex complex::operator+(const complex &rhs) const {
  return complex(a + rhs.a, b + rhs.b);
}

// 减法
complex complex::operator-(const complex &rhs) const {
  return complex(a - rhs.a, b - rhs.b);
}

// 乘法
complex complex::operator*(const complex &rhs) const {
  return complex(a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a);
}

// 除法
complex complex::operator/(const complex &rhs) const {
  // 检查除数是否为0
  if (sign(rhs.a) == 0 && sign(rhs.b) == 0) {
    throw divided_by_zero();
  }

  double denominator = rhs.a * rhs.a + rhs.b * rhs.b;
  return complex((a * rhs.a + b * rhs.b) / denominator,
                  (b * rhs.a - a * rhs.b) / denominator);
}

// 加法赋值
complex &complex::operator+=(const complex &rhs) {
  a += rhs.a;
  b += rhs.b;
  return *this;
}

// 减法赋值
complex &complex::operator-=(const complex &rhs) {
  a -= rhs.a;
  b -= rhs.b;
  return *this;
}

// 乘法赋值
complex &complex::operator*=(const complex &rhs) {
  double new_a = a * rhs.a - b * rhs.b;
  double new_b = a * rhs.b + b * rhs.a;
  a = new_a;
  b = new_b;
  return *this;
}

// 除法赋值
complex &complex::operator/=(const complex &rhs) {
  // 检查除数是否为0
  if (sign(rhs.a) == 0 && sign(rhs.b) == 0) {
    throw divided_by_zero();
  }

  double denominator = rhs.a * rhs.a + rhs.b * rhs.b;
  double new_a = (a * rhs.a + b * rhs.b) / denominator;
  double new_b = (b * rhs.a - a * rhs.b) / denominator;
  a = new_a;
  b = new_b;
  return *this;
}

// 判断相等
bool complex::operator==(const complex &rhs) const {
  return sign(a - rhs.a) == 0 && sign(b - rhs.b) == 0;
}

// 转换为bool
complex::operator bool() const {
  return !(sign(a) == 0 && sign(b) == 0);
}

// 输出运算符
std::ostream &operator<<(std::ostream &os, const complex &x) {
  os << std::fixed << std::setprecision(6);

  // 输出实部
  if (sign(x.a) < 0) {
    os << "-";
  } else {
    // 实部非负时不输出符号
  }
  os << std::fabs(x.a);

  // 输出虚部
  if (sign(x.b) < 0) {
    os << "-";
  } else {
    os << "+";
  }
  os << std::fabs(x.b) << "i";

  return os;
}

} // namespace sjtu
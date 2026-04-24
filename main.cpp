#include "complex.hpp"
#include <iostream>
#include <vector>

using namespace sjtu;

int main() {
  // 测试构造函数
  complex z; // 默认构造 0
  complex z1 = 1; // 1
  complex z2 = 2.22; // 2.22
  complex z3(114.514); // 114.514
  complex z4(1, 2); // 1+2i
  complex z5(2.22, 3.33); // 2.22+3.33i

  // 测试拷贝构造和拷贝赋值
  complex x; // x = 0
  complex y = x; // y = x = 0
  x = y = 2; // x = y = 2

  // 测试访问实部和虚部
  complex z6(1, 2);
  std::cout << z6.real() << "," << z6.imag() << std::endl; // 输出 1,2
  z6.real() = 3;
  z6.imag() = 4; // z = 3+4i
  std::cout << z6.real() << "," << z6.imag() << std::endl; // 输出 3,4

  // 测试比较函数
  complex a = 1, b = 2, c = 2;
  std::cout << int(a == b) << std::endl; // 输出 0
  std::cout << int(b == c) << std::endl; // 输出 1

  // 测试四则运算
  complex t1(1, 2), t2(3, 4);
  complex add = t1 + t2;
  complex sub = t1 - t2;
  complex mul = t1 * t2;
  complex div = t1 / t2;

  std::cout << add << std::endl;
  std::cout << sub << std::endl;
  std::cout << mul << std::endl;
  std::cout << div << std::endl;

  // 测试取负和共轭
  std::cout << -t1 << std::endl;
  std::cout << ~t1 << std::endl;

  // 测试除法异常
  complex d1(1, 1), d2(0, 0);
  try {
    d1 /= d2;
  } catch(const std::exception &err) {
    std::cout << err.what() << std::endl;
  }

  // 测试输出格式
  complex o1(-2, 0);
  complex o2(0, -2);
  complex o3(1, -1e-10);
  complex o4(-1e-10, 1);
  std::cout << o1 << std::endl; // -2.000000+0.000000i
  std::cout << o2 << std::endl; // 0.000000-2.000000i
  std::cout << o3 << std::endl; // 1.000000+0.000000i
  std::cout << o4 << std::endl; // 0.000000+1.000000i

  // 测试bool转换
  complex zb; // 默认初始化为 0
  if (zb) {
    std::cout << "zb is not zero!" << std::endl;
  } else {
    std::cout << "zb is zero!" << std::endl;
  }

  return 0;
}
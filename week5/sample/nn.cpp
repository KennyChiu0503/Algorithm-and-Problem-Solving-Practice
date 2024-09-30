// Return the value of a^N , logN
int A(int a, int N) {
  if (N == 0) {
    return 1;
  }
  int k = A(a, N / 2);

  if (N % 2)
    return k * k * a;
  else
    return k * k;
}
// N = Bk ... B1 B0, B = 0 or 1
// A^N = A^2Bk
// logN
// int result = 1;
// int a;
// int N;
// while (N) {
//  if (N % 2)
//    return *= a;
//  a *= a;
//  N /= 2;
//}

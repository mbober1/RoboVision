#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <iomanip>
#include <bitset>
using namespace std;


typedef unsigned char byte;
#define POLYNOMIAL_9 0x161



unsigned int CRC8_SingleByte( unsigned int Data2 ) {
 unsigned int Poly = ( POLYNOMIAL_9 << 7 );
 for ( byte Idx = 0; Idx < 8; ++Idx ) {
   if (( Data2 & 0x8000 ) != 0 ) Data2 ^= Poly;
   Data2 <<= 1;
 }
 return Data2;
}




byte CRC8_DataArray( const byte *pDataFrame, byte Len ) {
  cout << " Obliczanie dla ramki (" << static_cast<int>(Len) << "): " << pDataFrame << endl; 
  unsigned int Data2 = pDataFrame[0] << 8;

  for ( unsigned int Idx = 1; Idx < Len; ++Idx ) { 
    Data2 |= pDataFrame[Idx];
    Data2 = CRC8_SingleByte(Data2);
  }
  Data2 = CRC8_SingleByte( Data2 );
  return static_cast<byte>(Data2 >>8);
}


// byte CRC8_DataArray( const char *pDataFrame, byte Len )
// {
//   return CRC8_DataArray(reinterpret_cast<const byte*>(pDataFrame),Len);
// }



// bool ParseDataFrame( const char *pDataFrame, int &AccX, int &AccY )
// {
//   std::istringstream IStrm(pDataFrame);
//   char  FHeader;
//   unsigned int CRC8;

//   IStrm >> FHeader >> AccX >> AccY >> hex >> CRC8;
//  if (IStrm.fail() || FHeader != 'X' ) return false;
//  return static_cast<byte>(CRC8) == CRC8_DataArray(pDataFrame,strlen(pDataFrame)-3);
// }


// inline
// bool ParseDataFrame( const std::string &rDataFrame, int &AccX, int &AccY )
// {
//   return ParseDataFrame(rDataFrame.c_str(),AccX,AccY);
// }



// std::string CreateDataFrame( int AccX, int AccY )
// {
//   std::ostringstream  OStrm;

//   OStrm << "X " << AccX << " " << AccY;
//   byte CRC8 = CRC8_DataArray(OStrm.str().c_str(),OStrm.str().length());
//   OStrm << " " << hex << uppercase << setw(2) << static_cast<int>(CRC8);
//   return OStrm.str();
// }



// int main()
// {
//   int   Num1, Num2;

//   //------------------------------------------------------------------------
//   //   Przykład tworzenia ramki danych
//   //
//   std::string  DataFrame = CreateDataFrame(147,45281);
//   cout << endl << "   Utworzona ramka danych: " << DataFrame << endl << endl;


  
//   //------------------------------------------------------------------------
//   //   Przykład parsowania ramki danych
//   //
//   cout << "--- Parsowanie ramki danych --------------" << endl;
//   if (ParseDataFrame(DataFrame,Num1,Num2)) {
//     cout << endl
// 	 << ":)  Ramka jest poprawna. Wczytane dane:" << endl
// 	 << "       Num1: " << Num1 << endl
// 	 << "       Num2: " << Num2 << endl
// 	 << endl;
//   } else {
//     cout << endl << ":(  Ramka jest niepoprawna." << endl << endl;
//   }
// }

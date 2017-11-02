
//--------------------------------------------
// File : BitAdjacentMatrix.h
//
// Desc : the Application class for adjacent matrix 
//        using the bit
//
// by xiedonghai, 2004,10.
//--------------------------------------------



//## begin module%418B2B360125.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%418B2B360125.cm

//## begin module%418B2B360125.cp preserve=no
//## end module%418B2B360125.cp

//## Module: BitAdjacentMatrix%418B2B360125; Pseudo Package specification
//## Source file: d:\Program Files\Rational\Rose 98i\C++\source\BitAdjacentMatrix.h

#ifndef BitAdjacentMatrix_h
#define BitAdjacentMatrix_h 1

//## begin module%418B2B360125.additionalIncludes preserve=no
//## end module%418B2B360125.additionalIncludes

//## begin module%418B2B360125.includes preserve=yes
//## end module%418B2B360125.includes

//## begin module%418B2B360125.additionalDeclarations preserve=yes
//## end module%418B2B360125.additionalDeclarations


//## begin BitAdjacentMatrix%418B2B360125.preface preserve=yes
//## end BitAdjacentMatrix%418B2B360125.preface

//## Class: BitAdjacentMatrix%418B2B360125
//	�����������ǽ���άģ�͵�͵�֮�����ͨ��ϵ��ŵ�һ��
//	bit Ϊ������Ԫ����ͨ�����С�
//	�����ΪM����������е���Ŀ��ͬ�����ǵ����Ŀ�������Ϊ
//	n , ��ô����Ĵ�СΪn*n.
//	����� i  �� ��j ( i, j  )֮�������ͨ��ϵ���ͽ� M[i][j]
//	��ֵ����Ϊ1��
//	M ��ÿ��Ԫ�ض�����Ϊһ��bit��
//	����c ��c++����С������Ϊ BYTE,��һ���ֽڣ�ռ8��bitλ��
//	Ϊ�����ֽ����������е�bit��������Ҫ�����еĳ���ת��Ϊ�ֽ�
//	���������ǣ�
//	nBytesOfRow = n / 8 + 1;
//	��Ҫ������ֽ���Ϊ��  col * nBytesOfRow
//	�����Ƶ�����λ��ŵ�����(i ,j )�����Ӧ���ֽڵĹ�ϵΪ��
//
//	 index = i * nBytesOfRow  + j / 8 ;
//
//	���ֽ��е�ƫ��ֵΪ j % 8 ;
//
//	Ҫע�����ƫ��ֵ�Ǵ����������õ��ġ�
//## Category: <Top Level>
//## Persistence: Transient
//## Cardinality/Multiplicity: n
#include "stdafx.h"
#include "winnt.h"

class BitAdjacentMatrix 
{
  //## begin BitAdjacentMatrix%418B2B360125.initialDeclarations preserve=yes
  //## end BitAdjacentMatrix%418B2B360125.initialDeclarations

  public:
    //## Constructors (generated)
      BitAdjacentMatrix();

      BitAdjacentMatrix(const BitAdjacentMatrix &right);

    //## Destructor (generated)
      ~BitAdjacentMatrix();

    //## Assignment Operation (generated)
      BitAdjacentMatrix & operator=(const BitAdjacentMatrix &right);

    //## Equality Operations (generated)
      int operator==(const BitAdjacentMatrix &right) const;

      int operator!=(const BitAdjacentMatrix &right) const;


    //## Other Operations (specified)
      //## Operation: SetPos%418B301300EA
      //	�ú����������ǽ�һ���ֽ���ָ����λ��Ϊ1��
      //	��ԭ���ǣ�
      //
      //	1 | 0  =  1;
      //	1 | 1  =  1;
      //	0 | 0  =  0;
      //	0 | 1  =  1;
      //
      //	1 �� 0�� 1 �Ļ������λ1��
      //
      //	���ȸ������к���ȡ���õ��Ӧ���ֽ� a
      //	���������ƫ�Ƶ�bit�� off ��
      //	Ȼ��128 �������Ʋ�����
      //	 1000 0000   ��off
      //	��1�Ƶ���Ҫ������1������λ�ϡ�
      //
      //	Ȼ��Ը��ֽڽ���λ�������
      //
      //	a  |=  128 >>off;
      void SetPos (int i, int j);

      //## Operation: IsPosAdjacent%418B305C02CB
      //	�ú��������������ж� ���к� ��Ӧ��λ�Ƿ�Ϊ1
      //
      //
      //	���õ�ԭ���ǣ�
      //
      //	1 & 1  =  1 ;
      //	1 & 0  =  0 ;
      //
      //	0 & 0 =  0;
      //	0 & 1 =  0;
      //
      //	����һ���ֽڣ�����Ҫ�����Ǹ�bit λ��Ϊ 1
      //	������������Ϊ0��Ȼ��ָͬ�����ֽڽ��� ��������ɡ�
      //
      //	Ѱ���ֽں�ƫ�������ķ����� SetPos����ͬ�ġ�
      bool IsPosAdjacent (int i, int j);

      //## Operation: Init%418B319F0074
      //	λ����ĳ�ʼ������Ҫ�������еĴ�С��ȷ���ֽ�����Ȼ�����
//	�ı���ȫ����Ϊ0��
      bool Init (LONG wid, LONG hei);

      //## Operation: IsInit%418B7AA9015D
      bool IsInit ();

    // Additional Public Declarations
      //## begin BitAdjacentMatrix%418B2B360125.public preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.public

  protected:
    // Additional Protected Declarations
      //## begin BitAdjacentMatrix%418B2B360125.protected preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.protected

  public:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: m_pBytes%418B2F8A03D3
      const unsigned char* get_m_pBytes () const;
      void set_m_pBytes (unsigned char* value);

      //## Attribute: m_nWid%418B2FC803DF
      const int get_m_nWid () const;
      void set_m_nWid (int value);

      //## Attribute: m_nHei%418B2FD503D7
      const int get_m_nHei () const;
      void set_m_nHei (int value);

      //## Attribute: m_nBytesOfRow%418B5ADE0273
      const int get_m_nBytesOfRow () const;
      void set_m_nBytesOfRow (int value);

    // Additional Private Declarations
      //## begin BitAdjacentMatrix%418B2B360125.private preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin BitAdjacentMatrix::m_pBytes%418B2F8A03D3.attr preserve=no  private: unsigned char* {U} 
      unsigned char* m_pBytes;
      //## end BitAdjacentMatrix::m_pBytes%418B2F8A03D3.attr

      //## begin BitAdjacentMatrix::m_nWid%418B2FC803DF.attr preserve=no  private: int {U} 
      LONG m_nWid;
      //## end BitAdjacentMatrix::m_nWid%418B2FC803DF.attr

      //## begin BitAdjacentMatrix::m_nHei%418B2FD503D7.attr preserve=no  private: int {U} 
      LONG m_nHei;
      //## end BitAdjacentMatrix::m_nHei%418B2FD503D7.attr

      //## begin BitAdjacentMatrix::m_nBytesOfRow%418B5ADE0273.attr preserve=no  private: int {U} 
      LONG m_nBytesOfRow;
      //## end BitAdjacentMatrix::m_nBytesOfRow%418B5ADE0273.attr

    // Additional Implementation Declarations
      //## begin BitAdjacentMatrix%418B2B360125.implementation preserve=yes
      //## end BitAdjacentMatrix%418B2B360125.implementation

};

//## begin BitAdjacentMatrix%418B2B360125.postscript preserve=yes
//## end BitAdjacentMatrix%418B2B360125.postscript

// Class BitAdjacentMatrix 

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char * BitAdjacentMatrix::get_m_pBytes () const
{
  //## begin BitAdjacentMatrix::get_m_pBytes%418B2F8A03D3.get preserve=no
  return m_pBytes;
  //## end BitAdjacentMatrix::get_m_pBytes%418B2F8A03D3.get
}

inline void BitAdjacentMatrix::set_m_pBytes (unsigned char * value)
{
  //## begin BitAdjacentMatrix::set_m_pBytes%418B2F8A03D3.set preserve=no
  m_pBytes = value;
  //## end BitAdjacentMatrix::set_m_pBytes%418B2F8A03D3.set
}

inline const int BitAdjacentMatrix::get_m_nWid () const
{
  //## begin BitAdjacentMatrix::get_m_nWid%418B2FC803DF.get preserve=no
  return m_nWid;
  //## end BitAdjacentMatrix::get_m_nWid%418B2FC803DF.get
}

inline void BitAdjacentMatrix::set_m_nWid (int value)
{
  //## begin BitAdjacentMatrix::set_m_nWid%418B2FC803DF.set preserve=no
  m_nWid = value;
  //## end BitAdjacentMatrix::set_m_nWid%418B2FC803DF.set
}

inline const int BitAdjacentMatrix::get_m_nHei () const
{
  //## begin BitAdjacentMatrix::get_m_nHei%418B2FD503D7.get preserve=no
  return m_nHei;
  //## end BitAdjacentMatrix::get_m_nHei%418B2FD503D7.get
}

inline void BitAdjacentMatrix::set_m_nHei (int value)
{
  //## begin BitAdjacentMatrix::set_m_nHei%418B2FD503D7.set preserve=no
  m_nHei = value;
  //## end BitAdjacentMatrix::set_m_nHei%418B2FD503D7.set
}

inline const int BitAdjacentMatrix::get_m_nBytesOfRow () const
{
  //## begin BitAdjacentMatrix::get_m_nBytesOfRow%418B5ADE0273.get preserve=no
  return m_nBytesOfRow;
  //## end BitAdjacentMatrix::get_m_nBytesOfRow%418B5ADE0273.get
}

inline void BitAdjacentMatrix::set_m_nBytesOfRow (int value)
{
  //## begin BitAdjacentMatrix::set_m_nBytesOfRow%418B5ADE0273.set preserve=no
  m_nBytesOfRow = value;
  //## end BitAdjacentMatrix::set_m_nBytesOfRow%418B5ADE0273.set
}

//## begin module%418B2B360125.epilog preserve=yes
//## end module%418B2B360125.epilog


#endif
